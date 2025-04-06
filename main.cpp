#include <QApplication>
#include "connection.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    if (!c.openConnection())
    {
        QMessageBox::critical(nullptr, "Database Error", "Connection failed.\nClick Cancel to exit.", QMessageBox::Cancel);
        return 1;
    }
    MainWindow w;
    w.show();
    return a.exec() && Employer::logout();
}
