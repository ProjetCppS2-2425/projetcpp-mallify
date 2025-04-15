#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QHeaderView>
#include <QIcon>
#include <QMainWindow>
#include <QMenu>
#include <QMimeData>
#include <QPixmap>
#include <QPoint>
#include <QRect>
#include <QTimer>
#include <QRegularExpressionValidator>
#include <QSortFilterProxyModel>
#include <QStandardPaths>
#include <QShortcut>
#include <QAxObject>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QStackedBarSeries>
#include <QToolTip>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QVideoSink>
#include <QMediaDevices>
#include <QSpacerItem>
#include <QtConcurrent>
#include <QAtomicInt>
#include <employer.h>
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
    void on_new_password_textChanged(const QString &);
    void on_confirm_password_textChanged(const QString &);
    void on_export_emp_clicked();
    void on_import_emp_clicked(const QString& ="");
    void on_tabWidget_currentChanged(int);
    void on_login_btn_2_clicked();
    void on_stats_tab_currentChanged(int);
    void on_username_textChanged(const QString &arg1 ="");
    void on_password_textChanged(const QString &arg1 ="");
    void on_forgot_password_btn_clicked();
    void on_forget_password_profile_clicked();
protected:
    void initializeAAB6(Ui::MainWindow *);
    void dragEnterEvent(QDragEnterEvent *) override;
    void dropEvent(QDropEvent *) override;
    bool eventFilter(QObject *, QEvent *) override;
    void on_table_emp_selectionChanged();
    void g1();
    void g2();
    void g3();
    void importFace(const QImage&);
    void loadEmp(int,bool=true);
    void fetch_emp();
    void login();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
