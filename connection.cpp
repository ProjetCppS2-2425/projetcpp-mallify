#include "connection.h"

Connection::Connection() {}

bool Connection::createconnect() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("mallify");
    db.setUserName("mallify");
    db.setPassword("Naiwwissem");

    if (db.open())
        test = true;

    return test;
}
