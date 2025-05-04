#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "transaction.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChart>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serial(new QSerialPort(this)) // Initialize serial
{
    ui->setupUi(this);
    setupSerialPort(); // Initialize the serial port
    ui->tab_repairs->setCurrentIndex(0);

    // Connect buttons and combo boxes
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::searchTransactions);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::exportToPdf);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::sortTransactions);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::searchEmployees);
    connect(ui->comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::sortEmployees);
    connect(ui->tab_repairs, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->printstat, &QPushButton::clicked, this, &MainWindow::printStatistics);
    connect(ui->transactionListWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::onTransactionSelected);

    // Ensure database is open before loading data
    if (QSqlDatabase::database().isOpen()) {
        loadTransactions();
        loadEmployees();
    } else {
        qWarning() << "Database is not open. Skipping data loading.";
    }
}

MainWindow::~MainWindow()
{
    if (serial && serial->isOpen()) {
        serial->close();
    }
    delete serial;
    delete ui;
}

void MainWindow::setupSerialPort() {
    serial->setPortName("COM11"); // Set the port to COM11 as a string literal
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::handleSerialData);
        qDebug() << "Serial port connected.";
    } else {
        qWarning() << "Failed to open serial port:" << serial->errorString();
    }
}

void MainWindow::handleSerialData() {
    while (serial->canReadLine()) {
        QString rawUid = serial->readLine();
        qDebug() << "Raw UID from serial port:" << rawUid;

        // Extract the actual UID by removing unexpected text
        QString uid = rawUid.trimmed(); // Trim spaces and special characters
        if (uid.contains("Unauthorized UID detected:")) {
            uid = uid.section("Unauthorized UID detected:", 1).trimmed();
        }
        qDebug() << "Processed UID (after cleaning):" << uid;

        if (uid.isEmpty()) {
            qDebug() << "No RFID tag scanned.";
            ui->welcome->setText("Waiting...");
            return;
        }

        // Log UID in hexadecimal format to check for hidden characters
        qDebug() << "Processed UID in hex:" << uid.toUtf8().toHex();

        // Ensure the database connection is open
        if (!QSqlDatabase::database().isOpen()) {
            qWarning() << "Database connection is not open.";
            ui->welcome->setText("Waiting...");
            return;
        }
        qDebug() << "Database connection is open.";




        // Use a fresh QSqlQuery object
        QSqlQuery query;
        query.prepare("SELECT FIRST_NAME, LAST_NAME FROM EMPLOYER WHERE LOWER(RFID) = LOWER(:uid) AND POSITION = :position");

        // Assume you have a way to determine the position
        QString position = "Tech Support"; // Replace with actual logic to determine position
        query.bindValue(":uid", uid);
        query.bindValue(":position", position); // Bind the position parameter

        qDebug() << "Executing query with UID:" << uid << "and POSITION:" << position;

        if (query.exec())  {
            if (query.next()) {
                // UID is authorized
                QString firstName = query.value("FIRST_NAME").toString();
                QString lastName = query.value("LAST_NAME").toString();
                QString position = query.value("POSITION").toString();
                QString welcomeMessage = QString("Welcome: %1 %2").arg(firstName, lastName);

                qDebug() << "Access granted for UID:" << uid << ". Welcome message:" << welcomeMessage;
                ui->welcome->setText(welcomeMessage); // Display welcome message

                // Change the state of the service to "available"
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE SERVICE SET STATUS = 'available' WHERE POSITION = :position");
                updateQuery.bindValue(":position", position);

                if (updateQuery.exec())
                {
                    qDebug() << "Service state updated to 'available' for position:" << position;
                } else {
                    qWarning() << "Failed to update service state for position:" << position
                               << ". Error:" << updateQuery.lastError().text();
                }

                serial->write("AUTHORIZED\n");
            } else {
                // UID is not authorized
                qDebug() << "Employer not found in database for UID:" << uid;
                ui->welcome->setText("Access Denied!"); // Display "Access Denied!"
                serial->write("DENIED\n");
            }
        } else {
            qWarning() << "Failed to execute query for UID:" << uid << ". Error:" << query.lastError().text();
        }
    }
}

void MainWindow::loadTransactions() {
    QSqlQuery query("SELECT ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD FROM TRANSACTION");
    ui->transactionListWidget->clear();
    while (query.next()) {
        QString itemText = QString("ID: %1 | Amount: %2 | Date: %3 | Status: %4 | Service ID: %5 | Payment: %6")
            .arg(query.value("ID").toInt())
            .arg(query.value("AMOUNT").toDouble())
            .arg(query.value("DATE_ECHEANCE").toDate().toString())
            .arg(query.value("ETATS_DE_PAIEMENT").toString())
            .arg(query.value("ID_SERVICE").toInt())
            .arg(query.value("PAYMENT_METHOD").toString());
        ui->transactionListWidget->addItem(itemText);
    }
}

void MainWindow::sortTransactions() {
    QString sortCriteria = ui->comboBox->currentText();
    QString queryStr;
    if (sortCriteria == "by date") {
        queryStr = "SELECT ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD "
                   "FROM TRANSACTION ORDER BY DATE_ECHEANCE ASC";
    } else if (sortCriteria == "by type") {
        queryStr = "SELECT ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD "
                   "FROM TRANSACTION ORDER BY ETATS_DE_PAIEMENT ASC";
    } else if (sortCriteria == "matricule") {
        queryStr = "SELECT ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD "
                   "FROM TRANSACTION ORDER BY ID ASC";
    }
    QSqlQuery query(queryStr);
    ui->transactionListWidget->clear();
    while (query.next()) {
        QString itemText = QString("ID: %1 | Amount: %2 | Date: %3 | Status: %4 | Service ID: %5 | Payment: %6")
            .arg(query.value("ID").toInt())
            .arg(query.value("AMOUNT").toDouble())
            .arg(query.value("DATE_ECHEANCE").toDate().toString())
            .arg(query.value("ETATS_DE_PAIEMENT").toString())
            .arg(query.value("ID_SERVICE").toInt())
            .arg(query.value("PAYMENT_METHOD").toString());
        ui->transactionListWidget->addItem(itemText);
    }
}

void MainWindow::searchTransactions() {
    QString searchTerm = ui->lineEdit->text();
    QSqlQuery query;
    query.prepare("SELECT ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD "
                  "FROM TRANSACTION WHERE ID LIKE :searchTerm OR ETATS_DE_PAIEMENT LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + searchTerm + "%");
    ui->transactionListWidget->clear();
    if (query.exec()) {
        while (query.next()) {
            QString itemText = QString("ID: %1 | Amount: %2 | Date: %3 | Status: %4 | Service ID: %5 | Payment: %6")
                .arg(query.value("ID").toInt())
                .arg(query.value("AMOUNT").toDouble())
                .arg(query.value("DATE_ECHEANCE").toDate().toString())
                .arg(query.value("ETATS_DE_PAIEMENT").toString())
                .arg(query.value("ID_SERVICE").toInt())
                .arg(query.value("PAYMENT_METHOD").toString());
            ui->transactionListWidget->addItem(itemText);
        }
    } else {
        qWarning() << "Failed to search transactions:" << query.lastError().text();
    }
}

void MainWindow::loadEmployees() {
    QSqlQuery query("SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER");
    ui->listWidget->clear();
    while (query.next()) {
        QString itemText = QString("ID: %1 | Name: %2 %3 | Position: %4 | Salary: %5 | Absences: %6")
            .arg(query.value("ID").toInt())
            .arg(query.value("FIRST_NAME").toString())
            .arg(query.value("LAST_NAME").toString())
            .arg(query.value("POSITION").toString())
            .arg(query.value("BASE_SALARY").toDouble())
            .arg(query.value("ABSENCES").toInt());
        ui->listWidget->addItem(itemText);
    }
}

void MainWindow::sortEmployees() {
    QString sortCriteria = ui->comboBox_3->currentText();
    QString queryStr;
    if (sortCriteria == "by mat") {
        queryStr = "SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER ORDER BY ID ASC";
    } else if (sortCriteria == "by full_name") {
        queryStr = "SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER ORDER BY FIRST_NAME ASC";
    } else if (sortCriteria == "by post") {
        queryStr = "SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER ORDER BY POSITION ASC";
    }
    QSqlQuery query(queryStr);
    ui->listWidget->clear();
    while (query.next()) {
        QString itemText = QString("ID: %1 | Name: %2 %3 | Position: %4 | Salary: %5 | Absences: %6")
            .arg(query.value("ID").toInt())
            .arg(query.value("FIRST_NAME").toString())
            .arg(query.value("LAST_NAME").toString())
            .arg(query.value("POSITION").toString())
            .arg(query.value("BASE_SALARY").toDouble())
            .arg(query.value("ABSENCES").toInt());
        ui->listWidget->addItem(itemText);
    }
}

void MainWindow::searchEmployees() {
    QString searchTerm = ui->lineEdit_2->text();
    QSqlQuery query;
    query.prepare("SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES "
                  "FROM EMPLOYER WHERE FIRST_NAME LIKE :searchTerm OR LAST_NAME LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + searchTerm + "%");
    ui->listWidget->clear();
    if (query.exec()) {
        while (query.next()) {
            QString itemText = QString("ID: %1 | Name: %2 %3 | Position: %4 | Salary: %5 | Absences: %6")
                .arg(query.value("ID").toInt())
                .arg(query.value("FIRST_NAME").toString())
                .arg(query.value("LAST_NAME").toString())
                .arg(query.value("POSITION").toString())
                .arg(query.value("BASE_SALARY").toDouble())
                .arg(query.value("ABSENCES").toInt());
            ui->listWidget->addItem(itemText);
        }
    } else {
        qWarning() << "Failed to search employees:" << query.lastError().text();
    }
}

void MainWindow::exportToPdf() {
    QString filePath = QFileDialog::getSaveFileName(this, "Export Salary Management to PDF", "", "*.pdf");
    if (filePath.isEmpty()) {
        return;
    }
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(20, 20, 20, 20)); // Increased margins for better layout
    QPainter painter(&writer);
    int y = 0;
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(0, y += 100, "Salary Management Report"); // Title
    painter.setFont(QFont("Arial", 12));
    QSqlQuery query("SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER");
    while (query.next()) {
        QString line = QString("ID: %1 | Name: %2 %3 | Position: %4 | Salary: %5 | Absences: %6")
            .arg(query.value("ID").toInt())
            .arg(query.value("FIRST_NAME").toString())
            .arg(query.value("LAST_NAME").toString())
            .arg(query.value("POSITION").toString())
            .arg(query.value("BASE_SALARY").toDouble())
            .arg(query.value("ABSENCES").toInt());
        painter.drawText(50, y += 200, line); // Significantly increased spacing between lines
    }
    painter.end();
    QMessageBox::information(this, "Export to PDF", "Salary Management exported successfully.");
}

void MainWindow::printStatistics() {
    static bool isPrinting = false; // Prevent multiple triggers
    if (isPrinting) {
        return;
    }
    isPrinting = true;
    QString filePath = QFileDialog::getSaveFileName(this, "Export Statistics to PDF", "", "*.pdf");
    if (filePath.isEmpty()) {
        isPrinting = false;
        return;
    }
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(20, 20, 20, 20)); // Add margins for better spacing
    QPainter painter(&writer);

    // Query the database for income and outcome
    double totalIncome = 0.0, totalOutcome = 0.0;
    QSqlQuery incomeQuery("SELECT SUM(MONTHLY_RENT) FROM TENANT WHERE PAYMENT_STATUS = 'Paid'");
    if (incomeQuery.next()) {
        totalIncome = incomeQuery.value(0).toDouble();
    }
    QSqlQuery outcomeQuery("SELECT SUM(BASE_SALARY) FROM EMPLOYER");
    if (outcomeQuery.next()) {
        totalOutcome = outcomeQuery.value(0).toDouble();
    }

    // Create a pie chart
    QPieSeries *series = new QPieSeries();
    series->append(QString("Income (%1%)").arg((totalIncome / (totalIncome + totalOutcome)) * 100, 0, 'f', 2), totalIncome);
    series->append(QString("Outcome (%1%)").arg((totalOutcome / (totalIncome + totalOutcome)) * 100, 0, 'f', 2), totalOutcome);

    // Display percentages on the chart slices
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Income vs Outcome");
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Explicitly set the chart size and render it
    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);
    chartView.setFixedSize(600, 400); // Ensure the chart is large enough to render properly
    chartView.show(); // Ensure the chart is fully rendered before grabbing
    QPixmap chartPixmap = chartView.grab(); // Grab the rendered chart as a pixmap

    // Draw the chart in the PDF
    QRect chartRect(50, 100, writer.width() - 100, writer.height() - 200);
    painter.drawPixmap(chartRect, chartPixmap.scaled(chartRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    painter.end();
    isPrinting = false; // Reset the flag
    QMessageBox::information(this, "Export to PDF", "Statistics exported successfully.");
}

void MainWindow::loadFichDePay() {
    QSqlQuery query("SELECT ID, FIRST_NAME, LAST_NAME, POSITION, BASE_SALARY, ABSENCES FROM EMPLOYER");
    ui->listWidget_4->clear();
    while (query.next()) {
        QString itemText = QString("Matricule: %1\nFull Name: %2 %3\nPost: %4\nBasic Salary: %5\nAbsences: %6\nTotal Salary: %7")
            .arg(query.value("ID").toInt())
            .arg(query.value("FIRST_NAME").toString())
            .arg(query.value("LAST_NAME").toString())
            .arg(query.value("POSITION").toString())
            .arg(query.value("BASE_SALARY").toDouble())
            .arg(query.value("ABSENCES").toInt())
            .arg(query.value("BASE_SALARY").toDouble() - query.value("ABSENCES").toInt() * 50); // Example calculation
        ui->listWidget_4->addItem(itemText);
    }
}

void MainWindow::loadStatistics() {
    // Query the database for tenants' income
    double totalIncome = 0.0;
    QSqlQuery incomeQuery("SELECT SUM(MONTHLY_RENT) FROM TENANT WHERE PAYMENT_STATUS = 'Paid'");
    if (incomeQuery.next()) {
        totalIncome = incomeQuery.value(0).toDouble();
    }

    // Query the database for employees' salaries (outcome)
    double totalOutcome = 0.0;
    QSqlQuery outcomeQuery("SELECT SUM(BASE_SALARY) FROM EMPLOYER");
    if (outcomeQuery.next()) {
        totalOutcome = outcomeQuery.value(0).toDouble();
    }

    // Create a pie chart
    QPieSeries *series = new QPieSeries();
    QPieSlice *incomeSlice = series->append("Income", totalIncome);
    QPieSlice *outcomeSlice = series->append("Outcome", totalOutcome);

    // Calculate and display percentages near each slice
    double total = totalIncome + totalOutcome;
    incomeSlice->setLabel(QString("Income (%1%)").arg((totalIncome / total) * 100, 0, 'f', 2));
    outcomeSlice->setLabel(QString("Outcome (%1%)").arg((totalOutcome / total) * 100, 0, 'f', 2));
    incomeSlice->setLabelVisible(true);
    outcomeSlice->setLabelVisible(true);

    // Customize the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Income (Tenants) vs Outcome (Salaries)");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setMargins(QMargins(20, 20, 20, 20)); // Add margins for better spacing
    chart->setTitleFont(QFont("Arial", 16, QFont::Bold)); // Larger title font

    // Customize the legend
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Arial", 12)); // Larger legend font

    // Display the chart in the QChartView
    ui->chartView->setChart(chart);
}

void MainWindow::on_delete_sm_btn_clicked() {
    QMessageBox::information(this, "Delete", "Delete button clicked in Salary Management.");
}

void MainWindow::on_view_more_clicked() {
    QListWidgetItem *selectedItem = ui->transactionListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "View Details", "Please select a transaction to view details.");
        return;
    }
    QString selectedText = selectedItem->text();
    QMessageBox::information(this, "Transaction Details", "Details:\n" + selectedText);
}

void MainWindow::onTabChanged(int index) {
    if (index == 0) {
        loadTransactions();
    } else if (index == 1) {
        loadEmployees();
    } else if (index == 2) {
        loadStatistics();
        QMessageBox::information(this, "Tab Changed", "Statistics tab selected.");
    }
}

void MainWindow::loadServicesForLastMonth() {
    QMessageBox::information(this, "Load Services", "Loading services for the last month.");
}

void MainWindow::on_delete_transaction_clicked() {
    QListWidgetItem *selectedItem = ui->transactionListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Delete Transaction", "Please select a transaction to delete.");
        return;
    }
    QString selectedText = selectedItem->text();
    int id = selectedText.split(" | ").first().split(": ").last().toInt();
    QSqlQuery query;
    query.prepare("DELETE FROM TRANSACTION WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::critical(this, "Delete Transaction", "Failed to delete transaction: " + query.lastError().text());
        return;
    }
    // Reassign IDs to maintain sequential order
    query.exec("SET @new_id = 0");
    query.exec("UPDATE TRANSACTION SET ID = (@new_id := @new_id + 1) ORDER BY ID");
    QMessageBox::information(this, "Delete Transaction", "Transaction deleted successfully.");
    loadTransactions(); // Refresh the transaction list
}

void MainWindow::editSalary() {
    QMessageBox::information(this, "Edit Salary", "Edit Salary button clicked.");
}

/*
void MainWindow::on_pushButton_3_clicked() {
    QMessageBox::information(this, "Button 3", "Button 3 clicked.");
}
*/

void MainWindow::on_add_transaction_clicked() {
    transaction t;
    t.set_id(0); // ID will be auto-assigned
    t.set_amount(ui->salaryLineEdit->text().toDouble());
    t.set_date_echeance(QDate::currentDate());
    t.set_etats_de_paiement("Pending");
    t.set_id_service(ui->serviceLineEdit->text().toInt());
    t.set_payment_method("Cash");
    if (t.create()) {
        QMessageBox::information(this, "Add Transaction", "Transaction added successfully.");
        loadTransactions(); // Refresh the transaction list
    } else {
        QMessageBox::critical(this, "Add Transaction", "Failed to add transaction.");
    }
}

void MainWindow::on_edit_transaction_clicked() {
    QListWidgetItem *selectedItem = ui->transactionListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Edit Transaction", "Please select a transaction to edit.");
        return;
    }
    QString selectedText = selectedItem->text();
    int id = selectedText.split(" | ").first().split(": ").last().toInt();
    transaction t;
    t.set_id(id);
    t.set_amount(ui->salaryLineEdit->text().toDouble());
    t.set_date_echeance(QDate::currentDate());
    t.set_etats_de_paiement(ui->propertyLineEdit->text()); // Use the value from the input field
    t.set_id_service(ui->serviceLineEdit->text().toInt());

    // Preserve the existing payment method if the input field is empty
    QString paymentMethod = ui->bonusLineEdit->text();
    if (paymentMethod.isEmpty()) {
        QSqlQuery query;
        query.prepare("SELECT PAYMENT_METHOD FROM TRANSACTION WHERE ID = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next()) {
            paymentMethod = query.value(0).toString();
        }
    }
    t.set_payment_method(paymentMethod);
    if (t.update()) {
        QMessageBox::information(this, "Edit Transaction", "Transaction updated successfully.");
        loadTransactions(); // Refresh the transaction list
    } else {
        QMessageBox::critical(this, "Edit Transaction", "Failed to update transaction.");
    }
}

void MainWindow::onTransactionSelected() {
    QListWidgetItem *selectedItem = ui->transactionListWidget->currentItem();
    if (!selectedItem) {
        return; // No item selected
    }
    // Extract details from the selected item
    QString selectedText = selectedItem->text();
    QStringList details = selectedText.split(" | ");
    int id = details[0].split(": ").last().toInt();
    double amount = details[1].split(": ").last().toDouble();
    QString date = details[2].split(": ").last();
    QString status = details[3].split(": ").last();
    int serviceId = details[4].split(": ").last().toInt();
    QString paymentMethod = details[5].split(": ").last();

    // Populate the form fields
    ui->idLineEdit->setText(QString::number(id));
    ui->salaryLineEdit->setText(QString::number(amount));
    ui->serviceLineEdit->setText(QString::number(serviceId));
    ui->bonusLineEdit->setText(paymentMethod); // Assuming bonusLineEdit is used for payment method
    ui->propertyLineEdit->setText(status); // Assuming propertyLineEdit is used for status
}
