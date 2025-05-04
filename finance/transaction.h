#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDate>

class transaction {
public:
    transaction();
    ~transaction();

    // Getters
    int get_id() const;
    double get_amount() const;
    QDate get_date_echeance() const;
    QString get_etats_de_paiement() const;
    int get_id_propriete() const;
    int get_id_service() const;
    QString get_payment_method() const;

    // Setters
    void set_id(int id);
    void set_amount(double amount);
    void set_date_echeance(const QDate &date);
    void set_etats_de_paiement(const QString &status);
    void set_id_propriete(int id_propriete);
    void set_id_service(int id_service);
    void set_payment_method(const QString &method);

    // CRUD operations
    bool create();
    bool update();
    bool remove(int id);

private:
    int id;
    double amount;
    QDate date_echeance;
    QString etats_de_paiement;
    int id_propriete;
    int id_service;
    QString payment_method;
};

#endif // TRANSACTION_H
