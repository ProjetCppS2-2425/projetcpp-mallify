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
#include <QTimer>
#include <QUrl>
#include <QBuffer>
#include <QRegularExpressionValidator>
#include "employer.h"
#include<QSortFilterProxyModel>
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_login_btn_clicked();
    void on_profile_btn_clicked();
    void on_settings_btn_clicked();
    void on_logout_btn_clicked();
    void on_profile_light_mod_currentTextChanged(const QString &arg1);
    void on_sidebar_btn_clicked();
    void on_sidebar_btn_1_clicked();
    void on_sidebar_btn_2_clicked();
    void on_sidebar_btn_3_clicked();
    void on_sidebar_btn_4_clicked();
    void on_sidebar_btn_5_clicked();
    void on_sidebar_btn_6_clicked();
    void on_resetfilter_emp_clicked();
    void on_unselect_btn_clicked();
    void on_emp_search_btn_clicked();
    void on_add_emp_clicked();
    void on_update_emp_clicked();
    void on_delete_emp_clicked();
    void on_reset_emp_clicked();
protected:
    void initializeAAB6(Ui::MainWindow *ui);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void on_table_emp_selectionChanged();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
