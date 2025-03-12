#include "tenant.h"

Tenant::Tenant(const QString& tn, const QString& e, const QString& p, const QString& s, int r, const QString& z, int m, const QDate& ls, const QDate& le, const QString& ps, const QString& a)
    : tenant_name(tn), email(e), phone(p), shop_type(s), zone(z), payment_status(ps), activity_level(a),
    rented_area(r), monthly_rent(m), lease_start_date(ls), lease_end_date(le) {}

Tenant::Tenant() : id(0), rented_area(0), monthly_rent(0) {
    tenant_name = "";
    email = "";
    phone = "";
    shop_type = "";
    zone = "";
    payment_status = "";
    activity_level = "";
    lease_start_date = QDate();
    lease_end_date = QDate();
}

bool Tenant::ajouter() {
    QSqlQuery q;
    q.prepare("INSERT INTO Tenant (tenant_name, email, phone, shop_type, rented_area, zone, monthly_rent, lease_start_date, lease_end_date, payment_status, activity_level) "
              "VALUES (:tn, :e, :p, :s, :r, :z, :m, :ls, :le, :ps, :a)");
    q.bindValue(":tn", tenant_name);
    q.bindValue(":e", email);
    q.bindValue(":p", phone);
    q.bindValue(":s", shop_type);
    q.bindValue(":r", rented_area);
    q.bindValue(":z", zone);
    q.bindValue(":m", monthly_rent);
    q.bindValue(":ls", lease_start_date);
    q.bindValue(":le", lease_end_date);
    q.bindValue(":ps", payment_status);
    q.bindValue(":a", activity_level);

    return q.exec();
}

bool Tenant::supprimer() {
    QSqlQuery q;
    q.prepare("DELETE FROM Tenant where id = :i");
    q.bindValue(":i", id);

    return q.exec();
}

bool Tenant::update() {
    QSqlQuery q;
    q.prepare("UPDATE Tenant "
              "SET tenant_name = :tn, "
              "email = :e, "
              "phone = :p, "
              "shop_type = :s, "
              "rented_area = :r, "
              "zone = :z, "
              "monthly_rent = :m, "
              "lease_start_date = :ls, "
              "lease_end_date = :le, "
              "payment_status = :ps, "
              "activity_level = :a "
              "WHERE id = :i");

    q.bindValue(":i", id);
    q.bindValue(":tn", tenant_name);
    q.bindValue(":e", email);
    q.bindValue(":p", phone);
    q.bindValue(":s", shop_type);
    q.bindValue(":r", rented_area);
    q.bindValue(":z", zone);
    q.bindValue(":m", monthly_rent);
    q.bindValue(":ls", lease_start_date);
    q.bindValue(":le", lease_end_date);
    q.bindValue(":ps", payment_status);
    q.bindValue(":a", activity_level);

    return q.exec();
}

int Employer::findByEmail(const QString &email) {
    QSqlQuery query;
    query.prepare("SELECT id FROM employer WHERE email = :email");
    query.bindValue(":email", email);
    return query.exec() && query.next() ? query.value(0).toInt() : -1;
}

QSqlQueryModel* Tenant::fetch() {
    auto *m = new QSqlQueryModel();
    m->setQuery("SELECT id, tenant_name, email, phone, shop_type, rented_area, zone, monthly_rent, lease_start_date, lease_end_date, payment_status, activity_level FROM Tenant");
    return m;
}
