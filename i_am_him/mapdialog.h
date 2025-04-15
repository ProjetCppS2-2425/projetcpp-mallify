#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QLineEdit>

class QQuickWidget;
class CoordinateHandler;

class MapDialog : public QDialog {
    Q_OBJECT
public:
    explicit MapDialog(QWidget *parent = nullptr);
    ~MapDialog();

private:
    QQuickWidget *m_quickWidget;
    QLineEdit *m_addressLineEdit;
    CoordinateHandler *m_handler;
};

#endif // MAPDIALOG_H
