#include "reclamation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>  // Make sure this is included for QSqlError


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



