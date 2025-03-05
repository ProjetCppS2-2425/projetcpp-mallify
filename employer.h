#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>
#include<QByteArray>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QVariant>
#include<QMessageBox>
#include<QRandomGenerator>
#include<QCryptographicHash>
#include<QDebug>
#include<QProcess>
#include<QFile>
#include<QTextStream>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QEventLoop>
#include<QJsonDocument>
#include<QJsonObject>
#include<QUrl>
class Employer
{
private:
    int id,access_type,hours_worked,absences,lateness,created_by,modified_by;
    double base_salary,customer_feedback;
    QString first_name,last_name,email,phone,password,position,ui_preference;
    QByteArray profile_image,fingerprint;
    QDate hire_date,last_login,created_on,modified_on;
    static Employer*logged_in_employer;
public:
    Employer(int,int,int,int,int,int,int,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QByteArray&,const QByteArray&,const QDate&,const QDate&,const QDate&,const QDate&,double,double);
    ~Employer() = default;
    static bool login(const QString&,const QString&);
    static bool loginWithFace(const QByteArray&);
    static void logout();
    static Employer*getLoggedInEmployer();
    static bool updateAll(int,int,int,int,int,const QString&,double);
    static QSqlQueryModel* fetchAll();
    static bool delete_(int);
    bool add();
    bool update();
    bool is_valid(bool&& = false);
    static QString generatePassword(int = 12);
    static bool validatePassword(const QString&,const QString&);
    static void sendEmail(const QString&,const QString&,const QString&);
    static int findByEmail(const QString&);
    static int findByPhone(const QString&);
    static int findByFace(const QByteArray&);
    static void setPassword(const QString&);
    static void setUiPreference(const QString&);
    static bool verifyEmail(QString&);
    static bool verifyPhone(QString&);
    int getId()const;
    int getAccessType()const;
    int getHoursWorked()const;
    int getAbsences()const;
    int getLateness()const;
    double getBaseSalary()const;
    double getCustomerFeedback()const;
    QString getFirstName()const;
    QString getLastName()const;
    QString getEmail()const;
    QString getPhone()const;
    QString getPassword()const;
    QString getPosition()const;
    QString getUiPreference()const;
    QByteArray getProfileImage()const;
    QByteArray getFingerprint()const;
    QDate getHireDate()const;
    QDate getLastLogin()const;
    QDate getCreatedOn()const;
    QDate getModifiedOn()const;
};
#endif // EMPLOYER_H
