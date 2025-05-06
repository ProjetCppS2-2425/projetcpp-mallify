#ifndef COORDINATEHANDLER_H
#define COORDINATEHANDLER_H

#include <QObject>

class CoordinateHandler : public QObject {
    Q_OBJECT
public:
    explicit CoordinateHandler(QObject *parent = nullptr) : QObject(parent) {}

public slots:
              //void onCoordinateClicked(double lat, double lon);

signals:
    void addressReady(const QString &address);
};

#endif // COORDINATEHANDLER_H
