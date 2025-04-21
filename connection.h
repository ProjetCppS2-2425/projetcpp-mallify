#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    ~Connection();
    bool openConnection();
    void closeConnection();
};
#endif // CONNECTION_H
