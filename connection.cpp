#include "connection.h"
Connection::Connection()
{
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
}
