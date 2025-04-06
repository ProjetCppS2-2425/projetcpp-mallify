#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QByteArray>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QCryptographicHash>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QBuffer>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QThread>
class Employer
{
private:
    int id,access_type,hours_worked,absences,lateness,created_by,modified_by;
    double base_salary,customer_feedback;
    QString first_name,last_name,cin,email,phone,password,position,ui_preference,face_embedding;
    QByteArray profile_image,fingerprint;
    QDate hire_date,last_login,created_on,modified_on;
    static Employer* logged_in_employer;
    static QMap<QString, QString> emailCache;
    static QMap<QString, QString> phoneCache;
    static QSqlQueryModel* model;
public:
    Employer(int,int,int,int,int,int,int,double,double,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QByteArray&,const QByteArray&,const QDate&,const QDate&,const QDate&,const QDate&);
    ~Employer();
    static bool login(int,const QString&);
    static bool loginWithFace(int);
    static bool logout();
    static Employer* getLoggedInEmployer();
    static QString verifyEmail(const QString&);
    static QString verifyPhone(QString&);
    static void refreshCache();
    static int findByEmail(const QString&);
    static int findByPhone(const QString&);
    static int findByCin(const QString&);
    static int findByFace(const QString&);
    bool add();
    bool update();
    static bool updateAll(int,int,int,int,int,const QString&,double,double,const QDate&);
    static QSqlQueryModel* fetchAll();
    static bool delete_(int);
    static void sendEmail(const QString&,const QString&,const QString&);
    static void updatePassword(const QString&);
    static void updateUiPreference(const QString&);
    static QString generatePassword(int = 12);
    static bool validatePassword(const QString&,const QString&);
    static QJsonArray verifyFace(const QImage&);
    static bool compareToken(const QString&,const QString&);
    int getId()const;
    int getAccessType()const;
    int getHoursWorked()const;
    int getAbsences()const;
    int getLateness()const;
    int getCreatedBy()const;
    int getModifiedBy()const;
    double getBaseSalary()const;
    double getCustomerFeedback()const;
    QString getFirstName()const;
    QString getLastName()const;
    QString getCin()const;
    QString getEmail()const;
    QString getPhone()const;
    QString getPassword()const;
    QString getPosition()const;
    QString getUiPreference()const;
    QString getFaceEmbedding()const;
    QByteArray getProfileImage()const;
    QByteArray getFingerprint()const;
    QDate getHireDate()const;
    QDate getLastLogin()const;
    QDate getCreatedOn()const;
    QDate getModifiedOn()const;
};
#endif // EMPLOYER_H
