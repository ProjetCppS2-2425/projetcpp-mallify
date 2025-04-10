#include "reclamation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>  // Make sure this is included for QSqlError

#include <QFileDialog>

#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>


#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVector>
#include <QTableWidget>
#include <QAudioFormat>
#include <QMediaDevices>

#include <QAudioInput>
#include <QBuffer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>

#include <QMediaDevices>
#include <QAudioInput>
#include <QAudioFormat>

#include <QMediaDevices>
#include <QAudioSource>
#include <QBuffer>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>

#include <QAudioDevice>
#include <QAudioSource>
#include <QMediaDevices>
#include <QBuffer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QDataStream>

Reclamation::Reclamation() {}  // Empty default constructor

// Constructor implementation
Reclamation::Reclamation(int id, const QString& n, const QString& e, const QString& p,
                         const QString& t, const QString& pr, const QString& desc,
                         const QString& loc, const QString& stat, int emp_id)
{
    this->id = id;
    this->name = n;
    this->email = e;
    this->phone = p;
    this->type = t;
    this->priority = pr;
    this->description = desc;
    this->location = loc;
    this->status = stat;
    this->id_emp = emp_id;
}

// Add a new reclamation
bool Reclamation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO COMPLAINT (NAME, EMAIL, PHONE, COMPLAINT_TYPE, DESCRIPTION, PRIORITY, STATUS, ADDED_DATE, LOCATION, ID_EMP) "
                  "VALUES (:name, :email, :phone, :complaint_type, :description, :priority, :status, SYSDATE, :location, :id_emp)");

    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);
    query.bindValue(":complaint_type", type);
    query.bindValue(":description", description);
    query.bindValue(":priority", priority);
    query.bindValue(":status", status);
    query.bindValue(":location", location);
    query.bindValue(":id_emp", id_emp);

    return query.exec();
}


QSqlQueryModel* Reclamation::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Prepare the query to select relevant fields from the database
    query.prepare("SELECT ID, NAME, EMAIL, PHONE, COMPLAINT_TYPE, PRIORITY, STATUS, LOCATION, DESCRIPTION FROM COMPLAINT ORDER BY ADDED_DATE DESC");

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
    } else {
        // Use std::move to avoid deprecated warning about setQuery
        model->setQuery(std::move(query));
    }

    return model;
}


bool Reclamation::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM COMPLAINT WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error deleting record: " << query.lastError().text();
        return false;
    }
}

bool Reclamation::modifier(int id, const QString& name, const QString& email, const QString& phone,
                           const QString& type, const QString& priority, const QString& status,
                           const QString& description, const QString& location)
{
    QSqlQuery query;
    query.prepare("UPDATE COMPLAINT SET "
                  "NAME = :name, EMAIL = :email, PHONE = :phone, COMPLAINT_TYPE = :complaint_type, "
                  "PRIORITY = :priority, STATUS = :status, DESCRIPTION = :description, LOCATION = :location "
                  "WHERE ID = :id");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);
    query.bindValue(":complaint_type", type);
    query.bindValue(":priority", priority);
    query.bindValue(":status", status);
    query.bindValue(":description", description);
    query.bindValue(":location", location);

    return query.exec();
}

QMap<QString, int> Reclamation::statistiquesParType(QTableWidget *table) {
    QMap<QString, int> stats;

    int rowCount = table->rowCount();
    int typeColumn = 4;

    for (int i = 0; i < rowCount; ++i) {
        QString type = table->item(i, typeColumn)->text();
        stats[type]++;
    }

    return stats;
}






bool Reclamation::exportTraitéeEnPDF(QTableWidget *table, const QString &filePath) {
    // Validate input
    if (!table || table->rowCount() == 0) return false;

    // PDF Setup
    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageMargins(QMargins(40, 60, 40, 40));

    QPainter painter(&pdf);
    if (!painter.isActive()) return false;

    // Style Configuration
    const QColor accentColor(46, 134, 193);
    const QColor textColor(51, 51, 51);
    const QColor separatorColor(220, 220, 220);
    const int statusColumn = 6;
    const int idColumn = 0;

    // Font Setup
    QFont titleFont("Arial", 18, QFont::Bold);
    QFont headerFont("Arial", 11, QFont::Bold);
    QFont textFont("Arial", 10);

    // Page Dimensions
    QRect pageRect = painter.viewport();
    int y = pageRect.y() + 800;
    const int x = pageRect.x() + 50;
    const int contentWidth = pageRect.width() - 100;

    // Draw Title
    painter.setFont(titleFont);
    painter.setPen(accentColor);
    painter.drawText(pageRect, Qt::AlignTop | Qt::AlignHCenter, "Processed Reclamations");
    painter.setPen(textColor);

    // Find Valid Rows
    QVector<bool> validRows(table->rowCount(), false);
    for (int row = 0; row < table->rowCount(); ++row) {
        QTableWidgetItem *item = table->item(row, statusColumn);
        if (item && item->text().trimmed().toLower() == "completed") {
            validRows[row] = true;
        }
    }

    // Draw Entries
    int processedCount = 0;
    painter.setFont(textFont);

    for (int row = 0; row < table->rowCount(); ++row) {
        if (!validRows[row]) continue;

        // Page Break Check
        if (y > pageRect.bottom() - 200) {
            pdf.newPage();
            y = pageRect.y() + 800;
        }

        // Entry Container
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(250, 250, 250));
        painter.drawRoundedRect(x - 20, y - 20, contentWidth + 40, 200, 8, 8);

        // Entry Content
        int fieldY = y;
        for (int col = 0; col < table->columnCount(); ++col) {
            if (col == idColumn) continue;

            QTableWidgetItem *item = table->item(row, col);
            QString header = table->horizontalHeaderItem(col) ?
                                 table->horizontalHeaderItem(col)->text() + ": " : "";
            QString value = item ? item->text() : "";

            // Field Drawing
            painter.setFont(headerFont);
            painter.setPen(accentColor);
            painter.drawText(x, fieldY + 200, header);

            painter.setFont(textFont);
            painter.setPen(textColor);
            painter.drawText(x + 1200, fieldY + 200, value);

            fieldY += 300;
        }

        // Add separator line between entries
        painter.setPen(QPen(separatorColor, 1));
        painter.drawLine(x - 20, fieldY + 30, x + contentWidth + 20, fieldY + 30);

        y = fieldY + 600;  // Space between entries
        processedCount++;
    }

    // Empty State
    if (processedCount == 0) {
        painter.setFont(QFont("Arial", 12));
        painter.setPen(accentColor);
        painter.drawText(pageRect, Qt::AlignCenter, "No completed reclamations found");
    }

    painter.end();
    return processedCount > 0;
}

QSqlQueryModel* Reclamation::search(const QString &priority, const QString &type, const QString &status)
{
    // Create a new query model instance
    QSqlQueryModel* model = new QSqlQueryModel();

    // Prepare the SQL query with placeholders
    QSqlQuery query;
    query.prepare(R"(
        SELECT ID, NAME, EMAIL, PHONE, COMPLAINT_TYPE, PRIORITY, STATUS, LOCATION, DESCRIPTION
        FROM COMPLAINT
        WHERE PRIORITY = :priority
          AND COMPLAINT_TYPE = :type
          AND STATUS = :status
        ORDER BY ADDED_DATE DESC
    )");

    // Bind values to the named placeholders
    query.bindValue(":priority", priority);
    query.bindValue(":type", type);
    query.bindValue(":status", status);

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Error executing search query:" << query.lastError().text();
    } else {
        // Set the result of the query to the model
        model->setQuery(query);
    }

    return model;
}
