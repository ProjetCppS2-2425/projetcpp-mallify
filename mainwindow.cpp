#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->profile_section->setParent(this);
    ui->profile_section->setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
    ui->profile_section->setFixedSize(140, 120);
    ui->profile_section->move(this->width() - 140, 65);
    ui->profile_section->hide();
    ui->profile_section->installEventFilter(this);
    ui->profile_btn->setIcon(QIcon("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\pfp.jpg"));
    ui->sidebar_btn->setIcon(
        QIcon("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_light.png"));
    ui->logo->setPixmap(
        QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_light.png"));
    ui->logo_label->setPixmap(
        QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_light.png"));
    ui->profile_pic->setAcceptDrops(true);
    ui->profile_pic->setAlignment(Qt::AlignCenter);
    ui->title->setAcceptDrops(true);
    setAcceptDrops(true);
    QFile file("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\light.qss");
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_profile_btn_clicked()
{
    if (ui->profile_section->isVisible())
        ui->profile_section->hide();
    else {
        ui->profile_section->move(this->width() - 140, ui->profile_section->y());
        ui->profile_section->show();
    }
}
void MainWindow::on_logout_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_login_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_light_mode_dropdown_currentTextChanged(const QString &arg1)
{
    QString filePath = (arg1.toLower() == "dark")
                           ? "C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\dark.qss"
                           : "C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\light.qss";
    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    if (arg1.toLower() == "dark") {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_dark.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_dark.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_dark.png"));
    } else {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_light.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_sidebar_light.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\aab62\\Desktop\\testing\\i_am_him\\icons\\logo_light.png"));
    }
}
void MainWindow::on_sidebar_btn_clicked()
{
    ui->sidebar->setVisible(!ui->sidebar->isVisible());
}
void MainWindow::on_sidebar_btn_1_clicked()
{
    ui->container->setCurrentIndex(0);
    ui->title->setText("Employee Management");
}
void MainWindow::on_sidebar_btn_2_clicked()
{
    ui->container->setCurrentIndex(4);
    ui->title->setText("Service Management");
}
void MainWindow::on_sidebar_btn_6_clicked()
{
    ui->container->setCurrentIndex(1);
    ui->title->setText("Complaints Management");
}
void MainWindow::on_sidebar_btn_4_clicked()
{
    ui->container->setCurrentIndex(2);
    ui->title->setText("Shops Management");
}
void MainWindow::on_settings_btn_clicked()
{
    ui->container->setCurrentIndex(3);
    ui->title->setText("Profile");
}
void MainWindow::on_sidebar_btn_3_clicked()
{
    ui->container->setCurrentIndex(5);
    ui->title->setText("Tenants Management");
}
