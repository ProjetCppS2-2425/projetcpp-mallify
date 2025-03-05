#include "employer.h"
Employer* Employer::logged_in_employer = nullptr;
Employer::Employer(int id, int access_type, int hours_worked, int absences, int lateness, int created_by, int modified_by, const QString& first_name, const QString& last_name, const QString& email, const QString& phone, const QString& password, const QString& position, const QString& ui_preference, const QByteArray& profile_image, const QByteArray& fingerprint, const QDate& hire_date, const QDate& last_login, const QDate& created_on, const QDate& modified_on, double base_salary, double customer_feedback) : id(id), access_type(access_type), hours_worked(hours_worked), absences(absences), lateness(lateness), created_by(created_by), modified_by(modified_by), base_salary(base_salary), customer_feedback(customer_feedback), first_name(first_name), last_name(last_name), email(email), phone(phone), password(password), position(position), ui_preference(ui_preference), profile_image(profile_image), fingerprint(fingerprint), hire_date(hire_date), last_login(last_login), created_on(created_on), modified_on(modified_on) {}
bool Employer::login(const QString& email, const QString& enteredPassword)
{
    QSqlQuery query;
    query.prepare("SELECT id, access_type, hours_worked, absences, lateness, created_by, modified_by, first_name, last_name, email, phone, password, position, ui_preference, profile_image, fingerprint, hire_date, last_login, created_on, modified_on, base_salary, customer_feedback FROM employer WHERE email = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next())
    {
        QString storedHashedPassword = query.value("password").toString();
        if (validatePassword(enteredPassword, storedHashedPassword))
        {
            logged_in_employer = new Employer
            (
                query.value("id").toInt(),
                query.value("access_type").toInt(),
                query.value("hours_worked").toInt(),
                query.value("absences").toInt(),
                query.value("lateness").toInt(),
                query.value("created_by").toInt(),
                query.value("modified_by").toInt(),
                query.value("first_name").toString(),
                query.value("last_name").toString(),
                query.value("email").toString(),
                query.value("phone").toString(),
                storedHashedPassword,
                query.value("position").toString(),
                query.value("ui_preference").toString(),
                query.value("profile_image").toByteArray(),
                query.value("fingerprint").toByteArray(),
                query.value("hire_date").toDate(),
                query.value("last_login").toDate(),
                query.value("created_on").toDate(),
                query.value("modified_on").toDate(),
                query.value("base_salary").toDouble(),
                query.value("customer_feedback").toDouble()
            );
            return true;
        }
    }
    return false;
}
void Employer::logout()
{
    if(logged_in_employer)
    {
        delete logged_in_employer;
        logged_in_employer = nullptr;
    }
}
Employer* Employer::getLoggedInEmployer()
{
    return logged_in_employer;
}
QString Employer::generatePassword(int length)
{
    static const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    QString password;
    for (int i = 0; i < length; ++i)
        password.append(chars[QRandomGenerator::global()->bounded(chars.length())]);
    return password;
}
bool Employer::validatePassword(const QString& enteredPassword, const QString& storedHashedPassword)
{
    return QString(QCryptographicHash::hash(enteredPassword.toUtf8(), QCryptographicHash::Sha256).toHex()) == storedHashedPassword;
}
void Employer::setPassword(const QString&newPassword)
{
    QString hashedPassword = QString(QCryptographicHash::hash(newPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
    QSqlQuery query;
    query.prepare("UPDATE employer SET password = :password WHERE id = :id");
    query.bindValue(":password", hashedPassword);
    query.bindValue(":id",logged_in_employer->id);
    if (query.exec())
        logged_in_employer->password = hashedPassword;
}
bool Employer::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employer (first_name,last_name,email,phone,password,position,profile_image,fingerprint,access_type,ui_preference,hire_date,base_salary,hours_worked,absences,lateness,customer_feedback,last_login,created_on,created_by,modified_on,modified_by) VALUES (:first_name,:last_name,:email,:phone,:password,:position,:profile_image,:fingerprint,:access_type,:ui_preference,:hire_date,:base_salary,:hours_worked,:absences,:lateness,:customer_feedback,:last_login,:created_on,:created_by,:modified_on,:modified_by)");
    query.bindValue(":first_name",first_name);
    query.bindValue(":last_name",last_name);
    query.bindValue(":email",email);
    query.bindValue(":phone",phone);
    query.bindValue(":password",QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex()));
    query.bindValue(":position",position);
    query.bindValue(":profile_image",profile_image);
    query.bindValue(":fingerprint",fingerprint);
    query.bindValue(":access_type",access_type);
    query.bindValue(":ui_preference",ui_preference);
    query.bindValue(":hire_date",hire_date);
    query.bindValue(":base_salary",base_salary);
    query.bindValue(":hours_worked",hours_worked);
    query.bindValue(":absences",absences);
    query.bindValue(":lateness",lateness);
    query.bindValue(":customer_feedback",customer_feedback);
    query.bindValue(":last_login",QDate::currentDate());
    query.bindValue(":created_on",QDate::currentDate());
    query.bindValue(":created_by",logged_in_employer->getId());
    query.bindValue(":modified_on",QDate::currentDate());
    query.bindValue(":modified_by",logged_in_employer->getId());
    return query.exec();
}
int Employer::getId() const
{
    return id;
}
int Employer::getAccessType() const
{
    return access_type;
}
int Employer::getHoursWorked() const
{
    return hours_worked;
}
int Employer::getAbsences() const
{
    return absences;
}
int Employer::getLateness() const
{
    return lateness;
}
double Employer::getBaseSalary() const
{
    return base_salary;
}
double Employer::getCustomerFeedback() const
{
    return customer_feedback;
}
QString Employer::getFirstName() const
{
    return first_name;
}
QString Employer::getLastName() const
{
    return last_name;
}
QString Employer::getEmail() const
{
    return email;
}
QString Employer::getPhone() const
{
    return phone;
}
QString Employer::getPassword() const
{
    return password;
}
QString Employer::getPosition() const
{
    return position;
}
QString Employer::getUiPreference() const
{
    return ui_preference;
}
QByteArray Employer::getProfileImage() const
{
    return profile_image;
}
QByteArray Employer::getFingerprint() const
{
    return fingerprint;
}
QDate Employer::getHireDate() const
{
    return hire_date;
}
QDate Employer::getLastLogin() const
{
    return last_login;
}
QDate Employer::getCreatedOn() const
{
    return created_on;
}
QDate Employer::getModifiedOn() const
{
    return modified_on;
}
void Employer::setUiPreference(const QString& ui_preference)
{
    QSqlQuery q;
    q.prepare("UPDATE employer SET ui_preference=:ui_preference WHERE id=:id");
    q.bindValue(":ui_preference", ui_preference);
    q.bindValue(":id", logged_in_employer->id);
    if (q.exec())
        logged_in_employer->ui_preference = ui_preference;
}
QSqlQueryModel* Employer::fetchAll()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id, first_name, last_name, email, phone, position, hire_date, base_salary, hours_worked, absences, lateness, customer_feedback, modified_on, modified_by FROM employer");
    return model;
}
bool Employer::delete_(int id)
{
    if(id==logged_in_employer->getId())logout();
    QSqlQuery query;
    query.prepare("DELETE FROM employer WHERE id=:id");
    query.bindValue(":id", id);
    return query.exec();
}
bool Employer::updateAll(int id, int access_type, int hours_worked, int absences, int lateness, const QString& position, double base_salary)
{
    QSqlQuery query;
    query.prepare("UPDATE employer SET access_type=:access_type, hours_worked=:hours_worked, absences=:absences, lateness=:lateness, position=:position, base_salary=:base_salary, modified_on=:modified_on, modified_by=:modified_by WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":access_type", access_type);
    query.bindValue(":hours_worked", hours_worked);
    query.bindValue(":absences", absences);
    query.bindValue(":lateness", lateness);
    query.bindValue(":position", position);
    query.bindValue(":base_salary", base_salary);
    query.bindValue(":modified_on", QDate::currentDate());
    query.bindValue(":modified_by", logged_in_employer->getId());
    return query.exec();
}
bool Employer::update()
{
    QSqlQuery query;
    query.prepare("UPDATE employer SET first_name=:first_name, last_name=:last_name, email=:email, phone=:phone, position=:position, profile_image=:profile_image, fingerprint=:fingerprint, access_type=:access_type, hire_date=:hire_date, base_salary=:base_salary, hours_worked=:hours_worked, absences=:absences, lateness=:lateness, customer_feedback=:customer_feedback, modified_on=:modified_on, modified_by=:modified_by WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":first_name", first_name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);
    query.bindValue(":position", position);
    query.bindValue(":profile_image", profile_image);
    query.bindValue(":fingerprint", fingerprint);
    query.bindValue(":access_type", access_type);
    query.bindValue(":hire_date", hire_date);
    query.bindValue(":base_salary", base_salary);
    query.bindValue(":hours_worked", hours_worked);
    query.bindValue(":absences", absences);
    query.bindValue(":lateness", lateness);
    query.bindValue(":customer_feedback", customer_feedback);
    query.bindValue(":modified_on", QDate::currentDate());
    query.bindValue(":modified_by", logged_in_employer->getId());
    return query.exec();
}
void Employer::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    QString customPath = "C:/Users/aab62/Desktop/testing/aab6/email.txt";
    QFile f(customPath);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream s(&f);
    s << QString("From: aab627092003@gmail.com\nTo: %1\nSubject: %2\n\n%3").arg(to, subject, body);
    f.close();
    QString w = QString("curl.exe --url smtps://smtp.gmail.com:465 --mail-from \"aab627092003@gmail.com\" --mail-rcpt \"%1\" --user \"aab627092003@gmail.com:ycpolfdqhqeomzil\" --upload-file %2").arg(to, customPath);
    QProcess x;
    x.setProcessChannelMode(QProcess::MergedChannels);
    x.setProgram("cmd.exe");
    x.setNativeArguments(QString("/C \"%1\"").arg(w));
    x.start();
    x.waitForFinished();
    QString output = x.readAll();
    QFile::remove(customPath);
}
int Employer::findByEmail(const QString &email)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM employer WHERE email = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next())
        return query.value(0).toInt();
    return -1;
}
int Employer::findByPhone(const QString &phone)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM employer WHERE phone = :phone");
    query.bindValue(":phone", phone);
    if (query.exec() && query.next())
        return query.value(0).toInt();
    return -1;
}
bool Employer::verifyEmail(QString &email)
{
    QString msg;
    QNetworkAccessManager m;
    QNetworkRequest r(QUrl("https://api.mails.so/v1/validate?email=" + email));
    r.setRawHeader("x-mails-api-key", "e810c06e-32ab-4f27-8abd-b1abca326c28");
    QNetworkReply *rp = m.get(r);
    QEventLoop l;
    QObject::connect(rp, &QNetworkReply::finished, &l, &QEventLoop::quit);
    l.exec();
    if (rp->error())
    {
        QMessageBox::critical(nullptr, "Email Validation Error", "API Error: " + rp->errorString());
        rp->deleteLater();
        return false;
    }
    QJsonObject o = QJsonDocument::fromJson(rp->readAll()).object()["data"].toObject();
    rp->deleteLater();
    if (!o["isv_format"].toBool()) msg = "Invalid email format.";
    else if (!o["isv_domain"].toBool()) msg = "Domain does not exist.";
    else if (!o["isv_noblock"].toBool()) msg = "Blocked domain or restricted email.";
    else if (!o["isv_mx"].toBool()) msg = "No valid mail server (MX missing).";
    else if (o["is_disposable"].toBool()) msg = "Disposable email not allowed.";
    else if (o["result"].toString() != "deliverable") msg = "Undeliverable email: " + o["reason"].toString();
    if (!msg.isEmpty())
    {
        QMessageBox::warning(nullptr, "Email Validation", msg);
        return false;
    }
    if (!o["isv_nocatchall"].toBool()) msg += "⚠️ Catch-all detected.\n";
    if (!o["isv_nogeneric"].toBool()) msg += "⚠️ Generic provider.\n";
    if (o["is_free"].toBool()) msg += "⚠️ Free email.\n";
    if (o["score"].toInt() < 50) msg += "⚠️ Risky email.\n";
    if (!msg.isEmpty())
        QMessageBox::information(nullptr, "Email Info", msg);
    return true;
}
bool Employer::verifyPhone(QString&phone)
{
    QString msg;
    if (!phone.startsWith("+")) phone = "+216" + phone;
    QNetworkAccessManager m;
    QNetworkReply *r = m.get(QNetworkRequest(QUrl("https://api.veriphone.io/v2/verify?phone=" + phone + "&key=8FA789F6ED7B4F14B9D0C2D7A683F880")));
    QEventLoop l;
    QObject::connect(r, &QNetworkReply::finished, &l, &QEventLoop::quit);
    l.exec();
    if (r->error())
    {
        QMessageBox::critical(nullptr, "Phone Validation Error", "API Error: " + r->errorString());
        r->deleteLater();
        return false;
    }
    QJsonObject j = QJsonDocument::fromJson(r->readAll()).object();
    r->deleteLater();
    if (j["status"].toString() != "success" || !j["phone_valid"].toBool())
    {
        QMessageBox::warning(nullptr, "Phone Validation", "Invalid phone number.");
        return false;
    }
    phone = j["e164"].toString();
    if (!j["carrier"].toString().isEmpty()) msg += "⚠️ Carrier: " + j["carrier"].toString() + ".\n";
    if (!j["line_type"].toString().isEmpty()) msg += "⚠️ Type: " + j["line_type"].toString() + ".\n";
    if (!msg.isEmpty())
        QMessageBox::information(nullptr, "Phone Info", msg);
    return true;
}
bool Employer::is_valid(bool &&isAdding)
{
    if (first_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Input Error", "First name is empty.");
        return false;
    }
    if (last_name.isEmpty())
    {
        QMessageBox::warning(nullptr, "Input Error", "Last name is empty.");
        return false;
    }
    static QString lastEmail, lastPhone;
    if (isAdding || email != lastEmail)
        if (!verifyEmail(email)) return false;
    if (isAdding || phone != lastPhone)
        if (!verifyPhone(phone)) return false;
    lastEmail = email;
    lastPhone = phone;
    int existingEmailId = findByEmail(email);
    int existingPhoneId = findByPhone(phone);
    if (existingEmailId > -1 && (isAdding || existingEmailId != id))
    {
        QMessageBox::warning(nullptr, "Input Error", "Email is already in use.");
        return false;
    }
    if (existingPhoneId > -1 && (isAdding || existingPhoneId != id))
    {
        QMessageBox::warning(nullptr, "Input Error", "Phone is already in use.");
        return false;
    }
    QMessageBox::information(nullptr, "Success", isAdding ? "Employer added successfully!" : "Employer updated successfully!");
    return true;
}
