#include "mapdialog.h"
#include "coordinatehandler.h"
#include <QQuickWidget>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QPushButton>

MapDialog::MapDialog(QWidget *parent)
    : QDialog(parent), m_quickWidget(new QQuickWidget(this)),
    m_addressLineEdit(new QLineEdit(this)),
    m_handler(new CoordinateHandler(this))
{
    setWindowTitle("Select a Location");
    resize(820, 700);

    // Set up layout: QQuickWidget (map) and QLineEdit (address)
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_quickWidget);
    m_addressLineEdit->setPlaceholderText("Address will appear here");
    layout->addWidget(m_addressLineEdit);

    // Expose coordinateHandler to QML
    m_quickWidget->rootContext()->setContextProperty("coordinateHandler", m_handler);

    // Load the QML file (adjust the URL as needed—using resource file below)
    m_quickWidget->setSource(QUrl("qrc:/Map.qml"));

    // Connect the signal from the handler so that when the address is ready, we update the QLineEdit
    connect(m_handler, &CoordinateHandler::addressReady,
            this, [this](const QString &address) {
                m_addressLineEdit->setText(address);
            });
}

MapDialog::~MapDialog() {
    // QQuickWidget and m_handler are parented and will be deleted automatically.
}
