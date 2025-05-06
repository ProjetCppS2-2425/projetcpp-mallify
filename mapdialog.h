// MapDialog.h
#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QQuickWidget>
#include <QQuickItem>
#include <QPointF>
#include <QGeoCoordinate>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class MapDialog : public QDialog {
    Q_OBJECT
public:
    explicit MapDialog(QWidget *parent = nullptr);
    ~MapDialog() override = default;

signals:
    void locationSelected(const QString &address, double latitude, double longitude);

public slots:
    Q_INVOKABLE void selectLocation(const QString &address, double latitude, double longitude);
    Q_INVOKABLE void handleMapClick(const QGeoCoordinate &coord);

private:
    QQuickWidget *quickView;
    QNetworkAccessManager *networkManager;
};

#endif // MAPDIALOG_H
