#include "connection.h"
Connection::Connection()
{
}
bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("mallify");//inserer le nom de la source de données
    db.setUserName("mallify");//inserer nom de l'utilisateur
    db.setPassword("mallify");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}
