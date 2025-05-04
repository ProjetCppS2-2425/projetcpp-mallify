#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QDebug>

class Arduino
{
public:
    Arduino();
    int connect_arduino(); // Connexion Arduino
    int close_arduino();   // Déconnexion Arduino
    void write_to_arduino(QByteArray data); // Envoyer des données
    QByteArray read_from_arduino();         // Lire des données
    QSerialPort* getserial();               // Accès au port série
    QString getarduino_port_name();         // Nom du port

private:
    QSerialPort *serial;
    QString arduino_port_name;
    QByteArray data;
};

#endif // ARDUINO_H
