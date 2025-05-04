#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Available drivers:" << QSqlDatabase::drivers(); // Debug available drivers

    Connection c;
    bool test = c.createconnect();
    qDebug() << "Using database driver:" << QSqlDatabase::database().driverName(); // Log the database driver
    MainWindow w; // Move MainWindow outside the if block
    if (test && QSqlDatabase::database().isOpen()) { // Ensure the database is open
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\nClick OK to continue."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed.\nClick OK to exit."), QMessageBox::Ok);
        return -1; // Exit the application if the connection fails
    }

    return a.exec(); // Keep the application running
}
