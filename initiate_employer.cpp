#include "mainwindow.h"
#include "ui_mainwindow.h"
static int selectedHeaderColumn = -1;
void MainWindow::initializeAAB6(Ui::MainWindow *ui)
{
    //login_page
    ui->container->hide();
    ui->topbar->hide();
    ui->sidebar->hide();
    ui->login_page->show();
    this->resize(300, 350);
    this->move((QApplication::primaryScreen()->geometry().width() - this->width()) / 2, (QApplication::primaryScreen()->geometry().height() - this->height()) / 2);
    ui->logo_label->setPixmap(QPixmap("C:\\Users\\aab62\\Desktop\\testing\\aab6\\icons\\logo_light.png").scaled(200, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //profile_page
    ui->profile_section->setParent(this);
    ui->profile_section->setWindowFlags(Qt::FramelessWindowHint|Qt::SubWindow);
    ui->profile_section->setFixedSize(140,120);
    ui->profile_section->move(this->width()-140,65);
    ui->profile_section->hide();
    ui->profile_section->installEventFilter(this);
    ui->profile_btn->setIcon(QIcon("C:\\Users\\aab62\\Desktop\\testing\\aab6\\icons\\pfp.jpg"));
    QFile f("C:\\Users\\aab62\\Desktop\\testing\\aab6\\light.qss");
    if(f.open(QFile::ReadOnly))qApp->setStyleSheet(f.readAll()),f.close();
    //main_page
    ui->pfp->setAcceptDrops(true);
    ui->pfp->setAlignment(Qt::AlignCenter);
    ui->pfp->setAttribute(Qt::WA_Hover, true);
    ui->pfp->setMouseTracking(true);
    ui->pfp->setScaledContents(true);
    ui->pfp->installEventFilter(this);
    ui->pfp->setCursor(Qt::PointingHandCursor);
    ui->table_emp->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->table_emp->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_emp->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_emp->horizontalHeader()->setSectionsMovable(true);
    ui->table_emp->horizontalHeader()->setSortIndicatorShown(true);
    ui->table_emp->setSortingEnabled(true);
    connect(ui->table_emp->horizontalHeader(), &QHeaderView::sectionClicked, this, [](int index){selectedHeaderColumn = index;});
    connect(ui->table_emp->horizontalHeader(), &QHeaderView::sectionDoubleClicked, this, [ui](int i){ui->table_emp->sortByColumn(i, (ui->table_emp->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder);});
    auto* proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(Employer::fetchAll());
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setDynamicSortFilter(true);
    ui->table_emp->setModel(proxyModel);
    connect(ui->table_emp->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_table_emp_selectionChanged);
    ui->first_name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));
    ui->last_name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));
    ui->phone->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\+?[0-9]{8,15}$)"), this));
    ui->email->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\S+@\S+\.\S+$)"), this));
}
void MainWindow::on_login_btn_clicked()
{
    QString username = ui->username->text().trimmed();
    QString password = ui->password->text().trimmed();
    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Login Error", "Username and password cannot be empty.");
        return;
    }
    if (!Employer::login(username, password))
    {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password.");
        return;
    }
    ui->container->show();
    ui->topbar->show();
    ui->sidebar->show();
    ui->login_page->hide();
    this->resize(1024, 768);
    this->move((QApplication::primaryScreen()->geometry().width() - width()) / 2,(QApplication::primaryScreen()->geometry().height() - height()) / 2);
}
void MainWindow::on_profile_btn_clicked()
{
    if (ui->profile_section->isVisible())
        ui->profile_section->hide();
    else
    {
        ui->profile_section->move(this->width() - 140, ui->profile_section->y());
        ui->profile_section->show();
    }
}
void MainWindow::on_settings_btn_clicked()
{
    ui->container->setCurrentIndex(3);
    ui->title->setText("Profile");
}
void MainWindow::on_logout_btn_clicked()
{
    Employer::logout();
    ui->container->hide();
    ui->topbar->hide();
    ui->sidebar->hide();
    ui->login_page->show();
    this->resize(300, 350);
    this->move((QApplication::primaryScreen()->geometry().width() - this->width()) / 2, (QApplication::primaryScreen()->geometry().height() - this->height()) / 2);
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
void MainWindow::on_profile_light_mod_currentTextChanged(const QString &arg1)
{
    QFile file((arg1.toLower() == "dark")? "C:\\Users\\aab62\\Desktop\\testing\\aab6\\dark.qss": "C:\\Users\\aab62\\Desktop\\testing\\aab6\\light.qss");
    if (file.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    if (arg1.toLower() == "dark")
        ui->logo_label->setPixmap(QPixmap("C:\\Users\\aab62\\Desktop\\testing\\aab6\\icons\\logo_dark.png").scaled(200, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    else
        ui->logo_label->setPixmap(QPixmap("C:\\Users\\aab62\\Desktop\\testing\\aab6\\icons\\logo_light.png").scaled(200, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    Employer::setUiPreference(arg1.toLower());
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()) event->acceptProposedAction();
}
void MainWindow::dropEvent(QDropEvent *event)
{
    QPixmap pix(event->mimeData()->urls().first().toLocalFile());
    if(!pix.isNull())ui->pfp->setPixmap(pix.scaled(ui->pfp->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}
bool MainWindow::eventFilter(QObject *obj,QEvent *event)
{
    if(obj==ui->profile_section&&(event->type()==QEvent::FocusOut||event->type()==QEvent::Leave))
    {
        ui->profile_section->hide();
        return true;
    }
    else if(obj==ui->pfp&&event->type()==QEvent::MouseButtonPress)
    {
        QPixmap pix(QFileDialog::getOpenFileName(this,"Select Profile Image","","Images (*.png *.jpg *.jpeg)"));
        if(!pix.isNull())ui->pfp->setPixmap(pix.scaled(ui->pfp->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
        return true;
    }
    return QMainWindow::eventFilter(obj,event);
}
void MainWindow::on_resetfilter_emp_clicked()
{
    ui->searchbox_emp->clear();
    if (auto *proxy = qobject_cast<QSortFilterProxyModel*>(ui->table_emp->model()))
        proxy->setFilterFixedString("");
}
void MainWindow::on_reset_emp_clicked()
{
}
void MainWindow::on_unselect_btn_clicked()
{
    ui->table_emp->clearSelection();
    ui->table_emp->horizontalHeader()->setSortIndicator(-1, Qt::AscendingOrder);
    ui->add_emp->setEnabled(true);
    ui->update_emp->setEnabled(false);
}
void MainWindow::on_emp_search_btn_clicked()
{
    QSortFilterProxyModel* proxy = static_cast<QSortFilterProxyModel*>(ui->table_emp->model());
    proxy->setFilterKeyColumn(selectedHeaderColumn);
    proxy->setFilterRegularExpression(QRegularExpression(ui->searchbox_emp->text(), QRegularExpression::CaseInsensitiveOption));
}
void MainWindow::on_delete_emp_clicked()
{
    if (QMessageBox::warning(this, "Confirm", "Delete selected?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        return;
    auto *model = ui->table_emp->model();
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel*>(model);
    if (proxyModel) model = proxyModel->sourceModel();
    QList<int> id_to_delete;
    for (const auto &index : ui->table_emp->selectionModel()->selectedRows())
        id_to_delete.append(model->data(model->index(index.row(), 0)).toInt());
    if (id_to_delete.contains(Employer::getLoggedInEmployer()->getId()))
    {
        ui->container->hide();
        ui->topbar->hide();
        ui->sidebar->hide();
        ui->login_page->show();
        this->resize(300, 350);
        this->move((QApplication::primaryScreen()->geometry().width() - this->width()) / 2,
                   (QApplication::primaryScreen()->geometry().height() - this->height()) / 2);
    }
    for (int empID : id_to_delete)
        Employer::delete_(empID);
    ui->table_emp->setModel(Employer::fetchAll());
    if (proxyModel)
    {
        proxyModel->setSourceModel(ui->table_emp->model());
        ui->table_emp->setModel(proxyModel);
    }
}
void MainWindow::on_add_emp_clicked()
{
    Employer emp(0, (ui->a1->isChecked() ? 1 : 0) | (ui->a2->isChecked() ? 2 : 0) | (ui->a3->isChecked() ? 4 : 0) | (ui->a4->isChecked() ? 8 : 0) | (ui->a5->isChecked() ? 16 : 0) | (ui->a6->isChecked() ? 32 : 0), ui->hours_worked->value(), ui->absences->value(), ui->lateness->value(), 0, 0, ui->first_name->text().trimmed(), ui->last_name->text().trimmed(), ui->email->text().trimmed(), ui->phone->text().trimmed(), Employer::generatePassword(), ui->position->currentText(), "light", QByteArray(), QByteArray(), ui->hire_date->date(), QDate(), QDate(), QDate(), ui->base_salary->value(), ui->customer_feedback->value());
    if (!emp.is_valid(true) || !emp.add())
    {
        QMessageBox::critical(this, "Error", "Employer validation failed or could not be added.");
        return;
    }
    emp.sendEmail(emp.getEmail(), "Your Account Details", "Your account has been created.\nEmail: " + emp.getEmail() + "\nPassword: " + emp.getPassword());
    QMessageBox::information(this, "Success", "Employer added successfully.\nPassword sent to: " + emp.getEmail());
    auto proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->table_emp->model());
    if (proxyModel) proxyModel->setSourceModel(Employer::fetchAll());
    ui->first_name->clear();
    ui->last_name->clear();
    ui->email->clear();
    ui->phone->clear();
    ui->position->setCurrentIndex(0);
    ui->hours_worked->setValue(0);
    ui->absences->setValue(0);
    ui->lateness->setValue(0);
    ui->base_salary->setValue(0);
    ui->hire_date->setDate(QDate::currentDate());
    ui->a1->setChecked(false);
    ui->a2->setChecked(false);
    ui->a3->setChecked(false);
    ui->a4->setChecked(false);
    ui->a5->setChecked(false);
    ui->a6->setChecked(false);
}
void MainWindow::on_update_emp_clicked()
{
    auto selectedRows = ui->table_emp->selectionModel()->selectedRows();
    if (selectedRows.size() == 1)
    {
        Employer emp(ui->table_emp->model()->data(ui->table_emp->model()->index(selectedRows.first().row(), 0)).toInt(), (ui->a1->isChecked() ? 1 : 0) | (ui->a2->isChecked() ? 2 : 0) | (ui->a3->isChecked() ? 4 : 0) | (ui->a4->isChecked() ? 8 : 0) | (ui->a5->isChecked() ? 16 : 0) | (ui->a6->isChecked() ? 32 : 0), ui->hours_worked->value(), ui->absences->value(), ui->lateness->value(), 0, 0, ui->first_name->text().trimmed(), ui->last_name->text().trimmed(), ui->email->text().trimmed(), ui->phone->text().trimmed(), "", ui->position->currentText(), "", QByteArray(), QByteArray(), ui->hire_date->date(), QDate(), QDate(), QDate(), ui->base_salary->value(), ui->customer_feedback->value());
        if (!emp.is_valid() || !emp.update())
        {
            QMessageBox::critical(this, "Update Error", QString("Failed to update Employer ID %1.").arg(emp.getId()));
            return;
        }
    }
    else
    {
        for (const QModelIndex& index : selectedRows)
        {
            if (!Employer::updateAll(ui->table_emp->model()->data(ui->table_emp->model()->index(index.row(), 0)).toInt(), (ui->a1->isChecked() ? 1 : 0) | (ui->a2->isChecked() ? 2 : 0) | (ui->a3->isChecked() ? 4 : 0) | (ui->a4->isChecked() ? 8 : 0) | (ui->a5->isChecked() ? 16 : 0) | (ui->a6->isChecked() ? 32 : 0), ui->hours_worked->value(), ui->absences->value(), ui->lateness->value(), ui->position->currentText(), ui->base_salary->value()))
            {
                QMessageBox::critical(this, "Update Error", QString("Failed to update Employer ID %1.").arg(ui->table_emp->model()->data(ui->table_emp->model()->index(index.row(), 0)).toInt()));
                return;
            }
        }
    }
    QMessageBox::information(this, "Success", "All selected employers were updated successfully.");
    auto modelProxy = static_cast<QSortFilterProxyModel*>(ui->table_emp->model());
    modelProxy->setSourceModel(nullptr);
    modelProxy->setSourceModel(Employer::fetchAll());
    ui->table_emp->clearSelection();
    ui->table_emp->update();
    ui->first_name->clear();
    ui->last_name->clear();
    ui->email->clear();
    ui->phone->clear();
    ui->position->setCurrentIndex(0);
    ui->hours_worked->setValue(0);
    ui->absences->setValue(0);
    ui->lateness->setValue(0);
    ui->base_salary->setValue(0);
    ui->hire_date->setDate(QDate::currentDate());
    ui->a1->setChecked(false);
    ui->a2->setChecked(false);
    ui->a3->setChecked(false);
    ui->a4->setChecked(false);
    ui->a5->setChecked(false);
    ui->a6->setChecked(false);
}
void MainWindow::on_table_emp_selectionChanged()
{
    int selectionCount = ui->table_emp->selectionModel()->selectedRows().size();
    ui->update_emp->setEnabled(selectionCount > 0);
    ui->add_emp->setEnabled(!selectionCount);
    ui->delete_emp->setEnabled(selectionCount > 0);
    ui->first_name->setEnabled(selectionCount <= 1);
    ui->last_name->setEnabled(selectionCount <= 1);
    ui->email->setEnabled(selectionCount <= 1);
    ui->phone->setEnabled(selectionCount <= 1);
    ui->pfp->setEnabled(selectionCount <= 1);
    ui->pfp->setCursor(selectionCount <= 1 ? Qt::PointingHandCursor : Qt::ForbiddenCursor);
    if (selectionCount == 1)
    {
        int row = ui->table_emp->selectionModel()->selectedRows().first().row();
        auto model = ui->table_emp->model();
        ui->first_name->setText(model->data(model->index(row, 1)).toString());
        ui->last_name->setText(model->data(model->index(row, 2)).toString());
        ui->email->setText(model->data(model->index(row, 3)).toString());
        ui->phone->setText(model->data(model->index(row, 4)).toString());
        ui->position->setCurrentText(model->data(model->index(row, 5)).toString());
        ui->hire_date->setDate(model->data(model->index(row, 6)).toDate());
        ui->base_salary->setValue(model->data(model->index(row, 7)).toDouble());
        ui->hours_worked->setValue(model->data(model->index(row, 8)).toInt());
        ui->absences->setValue(model->data(model->index(row, 9)).toInt());
        ui->lateness->setValue(model->data(model->index(row, 10)).toInt());
    }
    else if (selectionCount > 1)
    {
        ui->first_name->clear();
        ui->last_name->clear();
        ui->email->clear();
        ui->phone->clear();
        ui->pfp->setPixmap(QPixmap());
    }
}
