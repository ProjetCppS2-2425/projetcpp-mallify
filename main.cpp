#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
<<<<<<< Updated upstream
    bool test = c.createconnect();
    if (!test)
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n""Click Cancel to exit."),QMessageBox::Cancel);
    MainWindow w;
    w.show();
    return a.exec();
=======
    if (!c.openConnection())
    {
        QMessageBox::critical(nullptr, "Database Error", "Connection failed.\nClick Cancel to exit.", QMessageBox::Cancel);
        return 1;
    }
    MainWindow w;
    w.show();
    return a.exec() && Employer::logout();
>>>>>>> Stashed changes
}
