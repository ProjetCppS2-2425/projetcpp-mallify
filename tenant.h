#ifndef TENANT_H
#define TENANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDate>

class Tenant {
    int id;
    QString tenant_name, email, phone, shop_type, zone, payment_status, activity_level;
    int rented_area, monthly_rent;
    QDate lease_start_date, lease_end_date;

public:
    Tenant();

    Tenant(const QString&, const QString&, const QString&, const QString&, int, const QString&, int, const QDate&, const QDate&, const QString&, const QString&);

    bool ajouter();
    bool supprimer();
    bool update();

    static int findByEmail(const QString&);

    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    static QSqlQueryModel* fetch();
};

#endif // TENANT_H

