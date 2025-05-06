#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QTableWidget>
#include <QMap>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QAudioInput>       // Added for speech-to-text
#include <QBuffer>           // Added for audio recording

#include <QAudioDevice>
#include <QAudioSource>
#include <QMediaDevices>
#include <QBuffer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QDataStream>

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
    QSqlQueryModel* search(const QString &priority, const QString &type, const QString &status);
    //stats
    QMap<QString, int> statistiquesParType(QTableWidget *table);

    bool exportTraitéeEnPDF(QTableWidget *table, const QString &filePath);

    QString transcribeSpeech();
    QByteArray createWavHeader(const QAudioFormat &format, qint64 dataSize);
    void showWindowsToastNotification(const QString &title, const QString &message);

};
#endif // RECLAMATION_H
