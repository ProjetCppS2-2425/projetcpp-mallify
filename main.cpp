#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.createconnect(); // Tentative de connexion à la base de données

    MainWindow w; // Création de la fenêtre principale AVANT la boîte de dialogue

    if (test)
    {
        QMessageBox::information(&w, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful."), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed."), QMessageBox::Cancel);
        return 1; // Quitte l'application en cas d'échec
    }

    w.show(); // Affichage de la fenêtre principale
    return a.exec(); // Lancement de l'application Qt
}
