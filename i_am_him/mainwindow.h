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

    void afficherReclamations();
    void on_btnSubmit_clicked();


    void on_tabWidget_3_tabBarClicked(int index);

    void on_pushButtonDelete_clicked();



    void on_selectAll_clicked();

    void on_tableWidget_2_itemSelectionChanged();

    void on_Updatebtn_clicked();

    void on_lineEditName_textChanged(const QString &arg1);
    void checkInputs();
    void on_lineEditEmail_textChanged(const QString &arg1);

    void on_lineEditPhone_textChanged(const QString &arg1);

    void on_lineEditLocation_textChanged(const QString &arg1);

    void on_textEditDescription_textChanged();

private:
    Ui::MainWindow *ui;
protected:
};
#endif // MAINWINDOW_H
