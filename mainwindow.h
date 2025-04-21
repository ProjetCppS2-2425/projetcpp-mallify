#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFile>
#include <QFileDialog>
#include <QHeaderView>
#include <QIcon>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMimeData>
#include <QPixmap>
#include <QPoint>
#include <QRect>
#include <QTextStream>
#include <QUrl>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadServicesToTable();
private slots:
    void on_profile_btn_clicked();

    void on_logout_btn_clicked();

    void on_settings_btn_clicked();

    void on_login_btn_clicked();

    void on_sidebar_btn_1_clicked();

    void on_light_mode_dropdown_currentTextChanged(const QString &arg1);

    void on_sidebar_btn_clicked();

    void on_sidebar_btn_2_clicked();

    void on_sidebar_btn_6_clicked();

    void on_sidebar_btn_4_clicked();

    void on_sidebar_btn_3_clicked();

    void on_add_service_clicked();

    void on_delete_service_clicked();

    void on_update_service_clicked();

    void on_service_table_itemSelectionChanged();

private:
    Ui::MainWindow *ui;

protected:
};
#endif // MAINWINDOW_H
