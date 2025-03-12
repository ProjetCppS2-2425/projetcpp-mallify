#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{
    int id;
    QString name;
    QString email;
    QString phone;
    QString type;
    QString description;  // Renamed from full_report to match DB field
    QString priority;
    QString status;  // Added status field
    QString location;  // Added location field
    int id_emp;  // Added id_emp field

public:
    // Constructor
    Reclamation();
    Reclamation(int, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, int);

    // Getter for id
    int getId() const { return id; }

    // CRUD Functions
    bool ajouter();
    bool supprimer(int);
    bool modifier(int id, const QString& name, const QString& email, const QString& phone,const QString& type, const QString& priority, const QString& status,const QString& description, const QString& location);
    QSqlQueryModel* afficher();


};

#endif // RECLAMATION_H
