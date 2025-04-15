#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeAAB6(ui);
}
MainWindow::~MainWindow()
{
    delete ui;
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
void MainWindow::on_sidebar_btn_3_clicked()
{
    ui->container->setCurrentIndex(5);
    ui->title->setText("Tenants Management");
}
void MainWindow::on_sidebar_btn_4_clicked()
{
    ui->container->setCurrentIndex(2);
    ui->title->setText("Shops Management");
}
void MainWindow::on_sidebar_btn_5_clicked()
{
    ui->container->setCurrentIndex(6);
    ui->title->setText("Transaction Management");
}
void MainWindow::on_sidebar_btn_6_clicked()
{
    ui->container->setCurrentIndex(1);
    ui->title->setText("Complaints Management");
}
