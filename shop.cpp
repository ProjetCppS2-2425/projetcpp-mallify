#include "shop.h"
#include <QSqlError>
#include <QDebug>

// Constructeur avec SURFACE ajouté
Shop::Shop(int id, const QString& name, const QString& category,
           const QString& description, const QString& condition,const QString& surface, double rental_price, int id_tenant)
    : id(id), name(name), category(category),  description(description),
    condition(condition),surface(surface), rental_price(rental_price), id_tenant(id_tenant) {}

// Constructeur par défaut
Shop::Shop() : id(0), name(""), category(""),  description(""), condition(""),surface(""), rental_price(0.0), id_tenant(0) {}

bool Shop::ajouter() {
    QSqlQuery q;
    q.prepare("INSERT INTO SHOP ( name, \"CATEGORY\", \"SURFACE\", description, \"CONDITION\", rental_price, id_tenant) "
              "VALUES (:name, :category, :surface, :description, :condition, :rental_price, :id_tenant)");

    q.bindValue(":name", name);
    q.bindValue(":category", category);
    q.bindValue(":surface", surface); // Ajout de la colonne SURFACE
    q.bindValue(":description", description);
    q.bindValue(":condition", condition);
    q.bindValue(":rental_price", rental_price);
    q.bindValue(":id_tenant", 654);

    bool success = q.exec();

    if (!success) {
        qDebug() << "❌ Erreur lors de l'ajout du shop Oracle :" << q.lastError().text();
    } else {
        qDebug() << "✅ Ajout réussi sur Oracle !";
        QSqlDatabase::database().commit(); // Valider la transaction
    }

    return success;
}

// Récupérer la liste des shops
QSqlQueryModel* Shop::fetch()
{
    auto *m = new QSqlQueryModel();
    m->setQuery("SELECT id, name, category, description, condition, rental_price, id_tenant FROM Shop");

    // Set header data for better display in UI components
    m->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    m->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    m->setHeaderData(2, Qt::Horizontal, QObject::tr("Category"));
    m->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    m->setHeaderData(4, Qt::Horizontal, QObject::tr("Condition"));
    m->setHeaderData(5, Qt::Horizontal, QObject::tr("Rental Price"));
    m->setHeaderData(6, Qt::Horizontal, QObject::tr("Tenant ID"));

    return m;
}

