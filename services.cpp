#include "services.h"


services::services() : service_id(0), cost(0), id_emp_worker(0), id_shop(0) {}

services::services(int service_id, QString name, QString type, QString departement, int cost, QString status, QString description, int id_emp_worker, int id_shop)
    : service_id(service_id), name(name), type(type), departement(departement), cost(cost), status(status), description(description), id_emp_worker(id_emp_worker), id_shop(id_shop) {}



int services::getWorkerIdByPhone(QString phone) {
    QSqlQuery query;
    query.prepare("SELECT ID FROM EMPLOYER WHERE PHONE = :phone");
    query.bindValue(":phone", phone);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    qDebug() << "Query failed:" << query.lastError().text();
    return -1;
}


bool services::createService() {
    QSqlQuery query;
    query.prepare("INSERT INTO MALLIFY.SERVICE (NAME, TYPE, DEPARTEMENT, COST, STATUS, DESCRIPTION, ID_EMP_WORKER, ID_SHOP) "
                  "VALUES (:name, :type, :departement, :cost, :status, :description, :id_emp_worker, :id_shop)");

    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":departement", departement);
    query.bindValue(":cost", cost);
    query.bindValue(":status", status);
    query.bindValue(":description", description);
    query.bindValue(":id_emp_worker", id_emp_worker);
    query.bindValue(":id_shop", id_shop == 0 ? QVariant::fromValue<int>(0) : id_shop);

    if (!query.exec()) {
        qDebug() << "Error inserting service: " << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* services::readServices() {
    QSqlQuery query;
    query.prepare("SELECT "
                  "S.ID, "
                  "S.NAME, "
                  "S.COST, "
                  "S.TYPE, "
                  "S.STATUS, "
                  "E.FIRST_NAME || ' ' || E.LAST_NAME AS ASSIGNED_EMPLOYER, "
                  "S.DESCRIPTION "
                  "FROM MALLIFY.SERVICE S "
                  "LEFT JOIN MALLIFY.EMPLOYER E ON S.ID_EMP_WORKER = E.ID");

    if (!query.exec()) {
        qDebug() << "SQL Query Execution Error: " << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error loading data into model: " << model->lastError().text();
        delete model;
        return nullptr;
    }

    qDebug() << "Query executed successfully, rows returned: " << model->rowCount();

    return model;
}



services services::readService(int service_id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM MALLIFY.SERVICE WHERE ID = :service_id");
    query.bindValue(":service_id", service_id);

    if (query.exec() && query.next()) {
        return services(query.value("ID").toInt(),
                        query.value("NAME").toString(),
                        query.value("TYPE").toString(),
                        query.value("DEPARTEMENT").toString(),
                        query.value("COST").toInt(),
                        query.value("STATUS").toString(),
                        query.value("DESCRIPTION").toString(),
                        query.value("ID_EMP_WORKER").toInt(),
                        query.value("ID_SHOP").toInt());
    }
    qDebug() << "Error reading service: " << query.lastError().text();
    return services();
}


bool services::updateService() {

    if (service_id <= 0 || name.isEmpty() || cost <= 0) {
        qDebug() << "Invalid input data. Service ID:" << service_id << ", Name:" << name << ", Cost:" << cost;
        return false;
    }

    QSqlQuery query;


    if (!query.prepare("UPDATE MALLIFY.SERVICE SET "
                       "NAME=:name, "
                       "TYPE=:type, "
                       "DEPARTEMENT=:departement, "
                       "COST=:cost, "
                       "STATUS=:status, "
                       "DESCRIPTION=:description, "
                       "ID_EMP_WORKER=:id_emp_worker, "
                       "ID_SHOP=:id_shop "
                       "WHERE ID=:service_id")) {
        qDebug() << "Query preparation failed:" << query.lastError().text();
        return false;
    }


    query.bindValue(":service_id", service_id);
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":departement", departement);
    query.bindValue(":cost", cost);
    query.bindValue(":status", status);
    query.bindValue(":description", description);
    query.bindValue(":id_emp_worker", id_emp_worker);
    query.bindValue(":id_shop", id_shop);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error updating service with ID" << service_id << ":" << query.lastError().text();
        qDebug() << "Database error message:" << query.lastError().databaseText();
        return false;
    }


    qDebug() << "Service with ID" << service_id << "updated successfully.";
    return true;
}


bool services::deleteService(int service_id) {
    if (service_id <= 0) {
        qDebug() << "Invalid service ID.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM MALLIFY.SERVICE WHERE ID = :service_id");
    query.bindValue(":service_id", service_id);

    if (!query.exec()) {
        qDebug() << "Error deleting service with ID" << service_id << ": " << query.lastError().text();
        return false;
    }

    return true;
}
