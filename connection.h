#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
class Connection
{
<<<<<<< Updated upstream
public:
    Connection();
    bool createconnect();
=======
private:
    QSqlDatabase db;
public:
    Connection();
    ~Connection();
    bool openConnection();
    void closeConnection();
>>>>>>> Stashed changes
};
#endif // CONNECTION_H
