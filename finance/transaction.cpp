#include "transaction.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

transaction::transaction()
    : id(0), amount(0.0), id_service(0) {}

transaction::~transaction() {}

int transaction::get_id() const { return id; }
double transaction::get_amount() const { return amount; }
QDate transaction::get_date_echeance() const { return date_echeance; }
QString transaction::get_etats_de_paiement() const { return etats_de_paiement; }
int transaction::get_id_service() const { return id_service; }
QString transaction::get_payment_method() const { return payment_method; }

void transaction::set_id(int id) { this->id = id; }
void transaction::set_amount(double amount) { this->amount = amount; }
void transaction::set_date_echeance(const QDate &date) { this->date_echeance = date; }
void transaction::set_etats_de_paiement(const QString &status) { this->etats_de_paiement = status; }
void transaction::set_id_service(int id_service) { this->id_service = id_service; }
void transaction::set_payment_method(const QString &method) { this->payment_method = method; }

bool transaction::create() {
    // Generate a unique ID by finding the maximum existing ID and incrementing it
    QSqlQuery maxIdQuery;
    maxIdQuery.prepare("SELECT COALESCE(MAX(ID), 0) + 1 FROM TRANSACTION");
    if (maxIdQuery.exec() && maxIdQuery.next()) {
        id = maxIdQuery.value(0).toInt();
        qDebug() << "Generated unique ID for transaction:" << id;
    } else {
        qWarning() << "Failed to generate unique ID:" << maxIdQuery.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO TRANSACTION (ID, AMOUNT, DATE_ECHEANCE, ETATS_DE_PAIEMENT, ID_SERVICE, PAYMENT_METHOD) "
                  "VALUES (:id, :amount, :date_echeance, :etats_de_paiement, :id_service, :payment_method)");
    query.bindValue(":id", id);
    query.bindValue(":amount", amount);
    query.bindValue(":date_echeance", date_echeance.toString("yyyy-MM-dd"));
    query.bindValue(":etats_de_paiement", etats_de_paiement);
    query.bindValue(":id_service", id_service);
    query.bindValue(":payment_method", payment_method);

    if (!query.exec()) {
        qWarning() << "Failed to create transaction:" << query.lastError().text();
        return false;
    }
    return true;
}

bool transaction::update() {
    QSqlQuery query;
    query.prepare("UPDATE TRANSACTION SET AMOUNT = :amount, DATE_ECHEANCE = :date_echeance, "
                  "ETATS_DE_PAIEMENT = :etats_de_paiement, ID_SERVICE = :id_service, PAYMENT_METHOD = :payment_method "
                  "WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":amount", amount);
    query.bindValue(":date_echeance", date_echeance.toString("yyyy-MM-dd"));
    query.bindValue(":etats_de_paiement", etats_de_paiement);
    query.bindValue(":id_service", id_service);
    query.bindValue(":payment_method", payment_method);

    if (!query.exec()) {
        qWarning() << "Failed to update transaction:" << query.lastError().text();
        return false;
    }
    return true;
}

bool transaction::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM TRANSACTION WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qWarning() << "Failed to delete transaction:" << query.lastError().text();
        return false;
    }
    return true;
}
