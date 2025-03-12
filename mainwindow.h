#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QEvent>
<<<<<<< Updated upstream
#include <QFile>
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
#include "employer.h"
#include<QSortFilterProxyModel>
=======
#include <QSortFilterProxyModel>
#include <QProcess>
#include "employer.h"
#include <QStandardPaths>
#include <QShortcut>
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
    void on_first_name_textChanged(const QString &arg1);
    void on_last_name_textChanged(const QString &arg1);
    void on_email_editingFinished();
    void on_phone_editingFinished();
    void on_camera_emp_clicked();
    void on_email_textChanged(const QString &arg1);
    void on_phone_textChanged(const QString &arg1);
    void on_cin_textChanged(const QString &arg1);
    void on_change_password_profile_clicked();
    void on_current_password_textChanged(const QString &arg1);
    void on_new_password_textChanged(const QString &arg1);
    void on_confirm_password_textChanged(const QString &arg1);
>>>>>>> Stashed changes
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
