// MapDialog.cpp
#include "MapDialog.h"
#include <QQmlContext>
#include <QVBoxLayout>
#include <QMetaObject>
#include <QVariant>
#include <QDebug>

MapDialog::MapDialog(QWidget *parent)
    : QDialog(parent),
    quickView(new QQuickWidget(this)),
    networkManager(new QNetworkAccessManager(this))
{
    setWindowTitle("Select Location");
    resize(800, 600);

    // Configure QQuickWidget
    quickView->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickView->setClearColor(Qt::black); // set black to detect if it's a QML issue

    // Expose this dialog to QML
    quickView->rootContext()->setContextProperty("cppDialog", this);
    quickView->setSource(QUrl("qrc:/qml/MapView.qml"));

    if (quickView->status() != QQuickWidget::Ready) {
        qCritical() << "QML Load Error:" << quickView->errors();
    } else {
        qDebug() << "QML Loaded successfully.";
    }

    auto layout = new QVBoxLayout(this);
    layout->addWidget(quickView);
}

void MapDialog::handleMapClick(const QGeoCoordinate &coord)
{
    double lat = coord.latitude();
    double lon = coord.longitude();
    qDebug() << "Clicked coordinates:" << lat << lon;

    const QUrl url(QStringLiteral(
                       "https://nominatim.openstreetmap.org/reverse?format=jsonv2"
                       "&lat=%1&lon=%2").arg(lat).arg(lon));
    QNetworkRequest request(url);
    auto reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [=]() {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QString address = doc.object().value("display_name").toString();
        qDebug() << "Resolved address:" << address;
        selectLocation(address, lat, lon);
        reply->deleteLater();
    });
}


void MapDialog::selectLocation(const QString &address, double latitude, double longitude)
{
    qDebug() << "Location selected:" << address << latitude << longitude;
    emit locationSelected(address, latitude, longitude);
    accept();
}
