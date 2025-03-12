#ifndef SHOP_H
#define SHOP_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class Shop
{
private:
    int id;
    QString name;
    QString category;
    QString description;
    QString condition;
    QString surface;
    double rental_price;
    int id_tenant;

public:
    // Constructor
    Shop(int, const QString&, const QString&, const QString&, const QString&, const QString&, double, int);

    // Default constructor
    Shop();

    // Getters
    int getId() const { return id; }
    QString getName() const { return name; }
    QString getCategory() const { return category; }
    QString getDescription() const { return description; }
    QString getCondition() const { return condition; }
    QString getSurface() const { return surface; }
    double getRentalPrice() const { return rental_price; }
    int getIdTenant() const { return id_tenant; }

    // CRUD
    bool ajouter();
    bool update();
    static bool updateAll(int);
    static bool delete_(int);
    static QSqlQueryModel* fetch();
};

#endif
