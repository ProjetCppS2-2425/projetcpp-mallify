#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tenant.h"

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
    ui->profile_btn->setIcon(QIcon("C:\\Users\\Taha\\Desktop\\mallify\\icons\\pfp.jpg"));
    ui->sidebar_btn->setIcon(
        QIcon("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_light.png"));
    ui->logo->setPixmap(
        QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_light.png"));
    ui->logo_label->setPixmap(
        QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_light.png"));
    ui->profile_pic->setAcceptDrops(true);
    ui->profile_pic->setAlignment(Qt::AlignCenter);
    ui->title->setAcceptDrops(true);
    setAcceptDrops(true);
    QFile file("C:\\Users\\moham\\Desktop\\mallify\\light.qss");

    ui->table_emp_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->nom_tent->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));
    ui->tel_tent->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\+?[0-9]{8,15}$)"), this));
    ui->email_tent->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\S+@\S+\.\S+$)"), this));

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
                           ? "C:\\Users\\moham\\Desktop\\mallify\\dark.qss"
                           : "C:\\Users\\moham\\Desktop\\mallify\\light.qss";
    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    if (arg1.toLower() == "dark") {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_dark.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_dark.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_dark.png"));
    } else {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_light.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_sidebar_light.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\Taha\\Desktop\\mallify\\icons\\logo_light.png"));
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

//=========================================================================================================================/

void MainWindow::on_sidebar_btn_3_clicked() {
    ui->container->setCurrentIndex(5);
    ui->title->setText("Tenants Management");
    loadTenantData();
}

void MainWindow::on_add_btn_tent_clicked() {
    ajouter_button_clicked();
}

void MainWindow::on_refresh_tab_clicked() {
    loadTenantData();
}

void MainWindow::on_delete_tent_clicked() {
    QList<QTableWidgetItem*> selectedItems = ui->table_emp_3->selectedItems();

    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    int id = ui->table_emp_3->item(row, 0)->text().toInt();

    Tenant tenant;
    tenant.setId(id);

    if (tenant.supprimer()) {
        ui->table_emp_3->removeRow(row);
    } else {
        QMessageBox::warning(this, "Deletion Failed", "Failed to delete the tenant.");
    }
}

void MainWindow::on_reset_tent_clicked() {
    ui->nom_tent->clear();
    ui->email_tent->clear();
    ui->tel_tent->clear();
    ui->rented_tent->clear();
    ui->monthly_tent->clear();

    ui->store_type_tent->setCurrentIndex(0);
    ui->zone_tent->setCurrentIndex(0);
    ui->payment_tent->setCurrentIndex(0);

    ui->from_tent->setDate(QDate(1, 1, 2));
    ui->to_tent->setDate(QDate(1, 1, 2));
}

void MainWindow::loadTenantData() {
    QSqlQueryModel* model = Tenant::fetch();

    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    int displayedCols = colCount - 1;
    ui->table_emp_3->setRowCount(rowCount);
    ui->table_emp_3->setColumnCount(displayedCols);

    QStringList headers = {"Id", "Name", "Email", "Phone", "Shop Type", "Rented Area", "Zone", "Monthly Rent", "Lease Start", "Lease End", "Payment Status"};
    ui->table_emp_3->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < rowCount; ++row) {
        int tableCol = 0;
        for (int col = 0; col < colCount; ++col) {
            if (col == colCount - 1) continue;

            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->table_emp_3->setItem(row, tableCol, item);
            tableCol++;
        }
    }

    ui->table_emp_3->setColumnHidden(0, true);

    delete model;
}

void MainWindow::ajouter_button_clicked() {
    QString name = ui->nom_tent->text();
    QString email = ui->email_tent->text();
    QString tel = ui->tel_tent->text();

    int rented_area = ui->rented_tent->text().toInt();
    int monthly_rent = ui->monthly_tent->text().toInt();

    QDate from_date = ui->from_tent->date();
    QDate to_date = ui->to_tent->date();

    QString store_type = ui->store_type_tent->currentText();
    QString zone = ui->zone_tent->currentText();
    QString payment_status = ui->payment_tent->currentText();


    Tenant T(name,email,tel,store_type,rented_area,zone,monthly_rent,from_date,to_date,payment_status,"active");

    T.ajouter();
    loadTenantData();
}

void MainWindow::on_table_emp_3_itemSelectionChanged() {
    QList<QTableWidgetItem*> selectedItems = ui->table_emp_3->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    ui->nom_tent->setText(ui->table_emp_3->item(row, 1)->text());
    ui->email_tent->setText(ui->table_emp_3->item(row, 2)->text());
    ui->tel_tent->setText(ui->table_emp_3->item(row, 3)->text());
    ui->store_type_tent->setCurrentText(ui->table_emp_3->item(row, 4)->text());
    ui->rented_tent->setText(ui->table_emp_3->item(row, 5)->text());
    ui->zone_tent->setCurrentText(ui->table_emp_3->item(row, 6)->text());
    ui->monthly_tent->setText(ui->table_emp_3->item(row, 7)->text());

    QString leaseStart = ui->table_emp_3->item(row, 8)->text().trimmed();
    QString leaseEnd = ui->table_emp_3->item(row, 9)->text().trimmed();

    QDate startDate = QDate::fromString(leaseStart.left(10), "yyyy-MM-dd");
    QDate endDate = QDate::fromString(leaseEnd.left(10), "yyyy-MM-dd");

    ui->from_tent->setDate(startDate);
    ui->to_tent->setDate(endDate);

    ui->payment_tent->setCurrentText(ui->table_emp_3->item(row, 10)->text());
}

void MainWindow::on_update_tent_clicked() {
    QList<QTableWidgetItem*> selectedItems = ui->table_emp_3->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    int id = ui->table_emp_3->item(row, 0)->text().toInt();
    qDebug() << "ID " << id;

    QString name = ui->nom_tent->text();
    QString email = ui->email_tent->text();
    QString tel = ui->tel_tent->text();

    int rented_area = ui->rented_tent->text().toInt();
    int monthly_rent = ui->monthly_tent->text().toInt();

    QDate from_date = ui->from_tent->date();
    QDate to_date = ui->to_tent->date();

    QString store_type = ui->store_type_tent->currentText();
    QString zone = ui->zone_tent->currentText();
    QString payment_status = ui->payment_tent->currentText();

    Tenant T(name,email,tel,store_type,rented_area,zone,monthly_rent,from_date,to_date,payment_status,"active");
    T.setId(id);
    T.update();

    loadTenantData();
}

