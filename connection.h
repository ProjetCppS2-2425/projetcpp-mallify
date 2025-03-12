#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlError>
#include <QDebug>

class Connection
{
public:
    Connection(); // Constructeur
    bool createconnect(); // Méthode pour établir la connexion à Oracle
};

#endif // CONNECTION_H
