#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    bool test = false;

    // Connexion via ODBC (Oracle)
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("mallify"); // Nom du DSN ODBC configuré dans ODBC Data Source Administrator
    db.setUserName("mallify"); // Nom d'utilisateur Oracle
    db.setPassword("Naiwwissem"); // Mot de passe Oracle

    if (db.open()) {
        test = true;
        qDebug() << "Connexion ODBC à Oracle réussie !";
        qDebug() << "Base de données :" << db.databaseName();

        // Vérifier si la table Shop existe déjà
        QSqlQuery checkTableQuery;
        checkTableQuery.exec("SELECT table_name FROM all_tables WHERE table_name = 'SHOP'");

        if (!checkTableQuery.next()) {
            qDebug() << "⚠️ La table 'SHOP' n'existe pas, création en cours...";

            // Création de la table Shop si elle n'existe pas
            QSqlQuery createTableQuery;
            bool tableCreated = createTableQuery.exec("CREATE TABLE Shop ("
                                                      "id NUMBER PRIMARY KEY, "
                                                      "name VARCHAR2(255) NOT NULL, "
                                                      "category VARCHAR2(255), "
                                                      "description VARCHAR2(1000), "
                                                      "condition VARCHAR2(255), "
                                                      "rental_price NUMBER(10,2), "
                                                      "id_tenant NUMBER)");

            if (!tableCreated) {
                qDebug() << " Erreur lors de la création de la table Shop :"
                         << createTableQuery.lastError().text();
            } else {
                qDebug() << "Table Shop créée avec succès.";
            }
        } else {
            qDebug() << "La table 'SHOP' existe déjà.";
        }

    } else {
        qDebug() << "Erreur de connexion ODBC à Oracle :" << db.lastError().text();
    }

    return test;
}
