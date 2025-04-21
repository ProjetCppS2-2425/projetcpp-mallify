#include "mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include "services.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (ui->profile_section) {
        ui->profile_section->setParent(this);
        ui->profile_section->setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
        ui->profile_section->setFixedSize(140, 120);
        ui->profile_section->move(this->width() - 140, 65);
        ui->profile_section->hide();
        ui->profile_section->installEventFilter(this);
    }


    ui->profile_btn->setIcon(
        QIcon(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/icons/pfp.jpg")));
    ui->sidebar_btn->setIcon(
        QIcon(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/icons/logo_sidebar_light.png")));
    ui->logo->setPixmap(
        QPixmap(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/logo_sidebar_light.png")));
    ui->logo_label->setPixmap(
        QPixmap(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/logo_light.png")));

    ui->profile_pic->setAcceptDrops(true);
    ui->profile_pic->setAlignment(Qt::AlignCenter);
    ui->title->setAcceptDrops(true);
    setAcceptDrops(true);

    ui->service_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->worker_phone->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^[0-9]{8,8}$)"), this));

    QFile file(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/light.qss"));
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }

    loadServicesToTable();
}

void MainWindow::loadServicesToTable()
{
    services serviceHelper;
    QSqlQueryModel *model = serviceHelper.readServices();

    if (!model) {
        qDebug() << "Failed to fetch services!";
        return;
    }

    if (model->rowCount() == 0) {
        qDebug() << "No rows fetched from the database!";
        delete model;
        return;
    }


    ui->service_table->setRowCount(model->rowCount());
    ui->service_table->setColumnCount(model->columnCount());


    for (int col = 0; col < model->columnCount(); ++col) {
        ui->service_table
            ->setHorizontalHeaderItem(col,
                                      new QTableWidgetItem(
                                          model->headerData(col, Qt::Horizontal).toString()));
    }


    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellValue = model->data(model->index(row, col)).toString();
            ui->service_table->setItem(row, col, new QTableWidgetItem(cellValue));
        }
    }

    delete model;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_profile_btn_clicked()
{
    ui->profile_section->setVisible(!ui->profile_section->isVisible());
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
    ? QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/dark.qss")
    : QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/light.qss");

    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }

    QString iconPath = (arg1.toLower() == "dark") ? "logo_sidebar_dark.png"
                                                  : "logo_sidebar_light.png";
    ui->sidebar_btn->setIcon(
        QIcon(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/icons/" + iconPath)));
    ui->logo->setPixmap(
        QPixmap(QDir::toNativeSeparators("C:/Users/Naiw/Desktop/i_am_him/icons/" + iconPath)));
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
    loadServicesToTable();
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


void MainWindow::on_add_service_clicked()
{
    bool ok;
    QString name = ui->service_name->text().trimmed();
    QString type = ui->service_type->currentText();
    QString departement = ui->external_services->text().trimmed();
    int cost = ui->service_cost->text().toInt(&ok);
    QString phone = ui->worker_phone->text().trimmed();
    QString description = ui->service_description->text().trimmed();


    if (name.isEmpty() || type.isEmpty() || departement.isEmpty() || phone.isEmpty()
        || description.isEmpty() || !ok || cost < 0) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly.");
        return;
    }

    services serviceHelper;
    int id_emp_worker = serviceHelper.getWorkerIdByPhone(phone);
    if (id_emp_worker == -1) {
        QMessageBox::warning(this, "Input Error", "No worker found with this phone number.");
        return;
    }


    services newService(0, name, type, departement, cost, "Active", description, id_emp_worker, 0);
    if (newService.createService()) {
        QMessageBox::information(this, "Success", "Service added successfully.");
        ui->service_name->clear();
        ui->worker_phone->clear();
        ui->service_cost->clear();
        ui->service_description->clear();
        ui->service_type->setCurrentIndex(0);
        ui->external_services->clear();
        loadServicesToTable();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add service.");
    }
}

void MainWindow::on_delete_service_clicked()
{

    auto selectedRows = ui->service_table->selectionModel()->selectedRows();


    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a service to delete.");
        return;
    }


    int ret = QMessageBox::warning(this,
                                   "Confirm Deletion",
                                   "Are you sure you want to delete this service?",
                                   QMessageBox::Yes | QMessageBox::No,
                                   QMessageBox::No);
    if (ret == QMessageBox::No) {
        return;
    }


    int service_id = ui->service_table->item(selectedRows.first().row(), 0)->text().toInt();


    services serviceHelper;
    if (serviceHelper.deleteService(service_id)) {

        ui->service_table->removeRow(selectedRows.first().row());
        QMessageBox::information(this, "Success", "Service deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete service.");
    }
}

void MainWindow::on_update_service_clicked()
{

    auto selectedRows = ui->service_table->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a service to update.");
        return;
    }

    int row = selectedRows.first().row();
    int service_id = ui->service_table->item(row, 0)->text().toInt(); // Assuming ID is in the first column


    QString name = ui->service_name->text().trimmed();
    QString type = ui->service_type->currentText();
    QString departement = ui->external_services->text().trimmed();
    int cost = ui->service_cost->text().toInt();
    QString phone = ui->worker_phone->text().trimmed();
    QString description = ui->service_description->text().trimmed();


    if (name.isEmpty() || type.isEmpty() || departement.isEmpty() || phone.isEmpty() || description.isEmpty() || cost < 0) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields correctly.");
        return;
    }

    services serviceHelper;
    int id_emp_worker = serviceHelper.getWorkerIdByPhone(phone);
    if (id_emp_worker == -1) {
        QMessageBox::warning(this, "Error", "No employee found with this phone number.");
        return;
    }


    services updatedService(service_id, name, type, departement, cost, "Active", description, id_emp_worker, 0);

    if (updatedService.updateService()) {
        QMessageBox::information(this, "Success", "Service updated successfully.");
        loadServicesToTable();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update service.");
    }
}

void MainWindow::on_service_table_itemSelectionChanged()
{
    QList<QTableWidgetItem*> selectedItems = ui->service_table->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    ui->service_name->setText(ui->service_table->item(row, 1)->text());
    ui->service_cost->setText(ui->service_table->item(row, 2)->text());
    ui->service_type->setCurrentText(ui->service_table->item(row, 3)->text());
    ui->worker_phone->setText(ui->service_table->item(row, 5)->text());
    ui->service_description->setText(ui->service_table->item(row, 6)->text());
}

