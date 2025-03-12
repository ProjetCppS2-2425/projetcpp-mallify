#include "connection.h"
Connection::Connection()
{
<<<<<<< Updated upstream
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
=======
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("mallify");
    db.setUserName("mallify");
    db.setPassword("mallify");
}
bool Connection::openConnection()
{
    if (!db.isOpen())
    {
        if (!db.open())
            return false;
    }
    return true;
}
void Connection::closeConnection()
{
    if (db.isOpen())
    {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }
}
Connection::~Connection()
{
    closeConnection();
>>>>>>> Stashed changes
}
