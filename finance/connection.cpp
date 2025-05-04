#include "connection.h"
#include <QSqlDatabase>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // Use SQLite driver
    db.setDatabaseName("mallify.db"); // SQLite database file (it will be created if it doesn't exist)

    if (!db.open()) {
        qWarning() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connection established successfully.";
    return true;
}
