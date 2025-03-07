#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set the fixed size of the window to 1920x1080
    w.setFixedSize(1080, 720);

    w.show(); // Open the window with the fixed size

    return a.exec();
}
