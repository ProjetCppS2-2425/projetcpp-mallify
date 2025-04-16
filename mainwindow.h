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
    void loadTenantData();
    void ajouter_button_clicked();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_add_tent_clicked();

    void on_refresh_tab_clicked();

    void on_table_tent_itemSelectionChanged();

    void on_delete_tent_clicked();

    void on_reset_tent_clicked();

    void on_update_tent_clicked();

    void on_predict_tent_clicked();

    void on_clear_pred_tent_clicked();

    void on_export_tent_clicked();

    void on_search_tent_clicked();

    void on_auto_mail_tent_clicked();

    void sendEmail(const QString &to, const QString &subject, const QString &body);

    void generateForms_Tent(int index, QWidget* container);

    void on_tabWidget_tent_tabBarClicked(int index);

    void on_delete_pred_tent_clicked();

    void on_delete_all_pred_tent_clicked();


    void on_refresh_pred_tent_clicked();

private:
    Ui::MainWindow *ui;
protected:
};
#endif // MAINWINDOW_H
