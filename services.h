#ifndef SERVICES_H
#define SERVICES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class services {
private:
    int service_id, cost, id_emp_worker, id_shop;
    QString name, type, departement, status, description;

public:
    services();
    services(int service_id, QString name, QString type, QString departement, int cost, QString status, QString description, int id_emp_worker, int id_shop);


    bool createService();
    bool createServiceWithPhone(QString workerPhone);
    static services readService(int service_id);
    QSqlQueryModel* readServices();
    bool updateService();
    bool deleteService(int service_id);


    int getWorkerIdByPhone(QString phone);
};

#endif // SERVICES_H
