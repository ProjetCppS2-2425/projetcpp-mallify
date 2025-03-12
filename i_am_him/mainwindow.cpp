#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QRegularExpressionValidator>  // Include the necessary header for validators
#include <QSqlRecord>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setting up validators for the input fields
    ui->lineEditName->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));  // Name (letters and spaces only)
    ui->lineEditEmail->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\S+@\S+\.\S+$)"), this));  // Email
    ui->lineEditPhone->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\+?[0-9]{8,15}$)"), this));  // Phone number
    ui->lineEditLocation->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z0-9, ]+$"), this));  // Location (letters, numbers, commas, and spaces)

    // Profile section setup (same as before)
    ui->profile_section->setParent(this);
    ui->profile_section->setWindowFlags(Qt::FramelessWindowHint | Qt::SubWindow);
    ui->profile_section->setFixedSize(140, 120);
    ui->profile_section->move(this->width() - 140, 65);
    ui->profile_section->hide();
    ui->profile_section->installEventFilter(this);
    ui->profile_btn->setIcon(QIcon("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\pfp.jpg"));
    ui->sidebar_btn->setIcon(
        QIcon("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_light.png"));
    ui->logo->setPixmap(
        QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_light.png"));
    ui->logo_label->setPixmap(
        QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_light.png"));
    ui->profile_pic->setAcceptDrops(true);
    ui->profile_pic->setAlignment(Qt::AlignCenter);
    ui->title->setAcceptDrops(true);
    setAcceptDrops(true);
    QFile file("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\light.qss");
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
    ? "C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\dark.qss"
    : "C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\light.qss";
    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    if (arg1.toLower() == "dark") {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_dark.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_dark.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_dark.png"));
    } else {
        ui->sidebar_btn->setIcon(
            QIcon("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_light.png"));
        ui->logo->setPixmap(
            QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_sidebar_light.png"));
        ui->logo_label->setPixmap(
            QPixmap("C:\\Users\\mahdo\\Downloads\\ka7loush\\i_am_him\\icons\\logo_light.png"));
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


void MainWindow::afficherReclamations()
{
    QSqlQueryModel *model = Reclamation().afficher();

    ui->tableWidget_2->setRowCount(model->rowCount());
    ui->tableWidget_2->setColumnCount(9);  // Number of columns

    // Set headers
    QStringList headers = {"id","Nom", "Email", "Phone", "Type", "Priority", "Status", "Location", "Description"};
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    ui->tableWidget_2->horizontalHeader()->setSectionHidden(0, true);
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < 9; ++col) {
            ui->tableWidget_2->setItem(row, col, new QTableWidgetItem(model->record(row).value(col).toString()));
        }
    }
}

void MainWindow::on_btnSubmit_clicked()
{
    if (!ui) {
        qDebug() << "UI is not initialized!";
        return;
    }
    qDebug() << "UI is initialized!";

    QString name = ui->lineEditName->text();
    QString email = ui->lineEditEmail->text();
    QString phone = ui->lineEditPhone->text();
    QString type = ui->comboBoxCategory->currentText();
    QString priority = ui->comboBoxPriority->currentText();
    QString description = ui->textEditDescription->toPlainText();
    QString location = ui->lineEditLocation->text();  // Assuming a QLineEdit for location

    // Create the Reclamation object with the correct parameters
    Reclamation rec(-1, name, email, phone, type, priority, description, location, "Open", 1);

    qDebug() << "Attempting to insert into database...";

    // Attempt to add the complaint to the database
    if (rec.ajouter()) {
        qDebug() << "Success";
        QMessageBox::information(this, "Success", "Complaint added successfully.");

        afficherReclamations();

        // Optionally, clear input fields after successful addition
        ui->lineEditName->clear();
        ui->lineEditEmail->clear();
        ui->lineEditPhone->clear();
        ui->textEditDescription->clear();
        ui->lineEditLocation->clear();
        ui->comboBoxCategory->setCurrentIndex(0);
        ui->comboBoxPriority->setCurrentIndex(0);
        ui->comboBoxStatus->setCurrentIndex(0);
    } else {
        qDebug() << "Error";

        QMessageBox::critical(this, "Error", "Failed to add complaint.");
    }
}



void MainWindow::on_tabWidget_3_tabBarClicked(int index)
{
    ui->btnSubmit->setEnabled(false);
    ui->container->setCurrentIndex(1);  // Show complaints management
    ui->title->setText("Complaints Management");
    afficherReclamations();  // Refresh the table when switching to this tab
}


void MainWindow::on_pushButtonDelete_clicked()
{
    // Get the selected rows from the table
    QItemSelectionModel *select = ui->tableWidget_2->selectionModel();
    QModelIndexList selectedIndexes = select->selectedRows();

    // Loop through the selected rows
    for (int i = 0; i < selectedIndexes.count(); ++i) {
        int row = selectedIndexes.at(i).row();  // Get the row of the selected index
        int id = ui->tableWidget_2->item(row, 0)->text().toInt();  // Assuming 'ID' is the first column in the table

        // Create the Reclamation object with the ID to delete
        Reclamation rec;
        if (rec.supprimer(id)) {
            // If deletion was successful, remove the row from the table
            ui->tableWidget_2->removeRow(row);
            qDebug() << "Row deleted successfully.";
        } else {
            qDebug() << "Failed to delete row with ID: " << id;
        }
    }

    // Refresh the table (reload data)
    afficherReclamations();
}




void MainWindow::on_selectAll_clicked()
{
     ui->tableWidget_2->selectAll();
}


void MainWindow::on_tableWidget_2_itemSelectionChanged()
{
    // Get the selected row
    QItemSelectionModel *select = ui->tableWidget_2->selectionModel();
    if (select->hasSelection()) {
        QModelIndexList selectedRows = select->selectedRows();

        // Get the data of the selected row (excluding the ID column)
        int row = selectedRows.at(0).row();
        QString name = ui->tableWidget_2->item(row, 1)->text();  // Column 1: Name
        QString email = ui->tableWidget_2->item(row, 2)->text();  // Column 2: Email
        QString phone = ui->tableWidget_2->item(row, 3)->text();  // Column 3: Phone
        QString type = ui->tableWidget_2->item(row, 4)->text();   // Column 4: Type
        QString priority = ui->tableWidget_2->item(row, 5)->text();  // Column 5: Priority
        QString status = ui->tableWidget_2->item(row, 6)->text();   // Column 6: Status
        QString location = ui->tableWidget_2->item(row, 7)->text(); // Column 7: Location
        QString description = ui->tableWidget_2->item(row, 8)->text();  // Column 8: Description

        // Populate the input fields
        ui->lineEditName_2->setText(name);
        ui->lineEditEmail_2->setText(email);
        ui->lineEditPhone_2->setText(phone);
        ui->comboBoxCategory_2->setCurrentText(type);
        ui->comboBoxPriority_2->setCurrentText(priority);
        ui->comboBoxStatus_2->setCurrentText(status);
        ui->textEditDescription_2->setPlainText(description);
        ui->lineEditLocation_2->setText(location);
    }

}


void MainWindow::on_Updatebtn_clicked()
{
    // Get the selected row and the updated data
    QItemSelectionModel *select = ui->tableWidget_2->selectionModel();
    if (select->hasSelection()) {
        QModelIndexList selectedRows = select->selectedRows();
        int row = selectedRows.at(0).row();

        // Get the ID of the selected row (assuming the ID is in the first column)
        int id = ui->tableWidget_2->item(row, 0)->text().toInt();  // Assuming the ID is stored as user role

        // Get the updated values from the input fields
        QString name = ui->lineEditName_2->text();
        QString email = ui->lineEditEmail_2->text();
        QString phone = ui->lineEditPhone_2->text();
        QString type = ui->comboBoxCategory_2->currentText();
        QString priority = ui->comboBoxPriority_2->currentText();
        QString status = ui->comboBoxStatus_2->currentText();
        QString location = ui->lineEditLocation_2->text();
        QString description = ui->textEditDescription_2->toPlainText();

        // Update the data in the database
        bool success = Reclamation().modifier(id, name, email, phone, type, priority, status, description, location);

        if (success) {
            QMessageBox::information(this, "Success", "Complaint updated successfully."+ QString::number(id));
            afficherReclamations();  // Refresh the table
        } else {
            QMessageBox::critical(this, "Error", "Failed to update the complaint.");
        }
    }

}


void MainWindow::on_lineEditName_textChanged(const QString &arg1)
{
    // Check if the input is empty and show error message
    if (arg1.isEmpty()) {
        ui->label_4->setText("Name:*");
        ui->label_4->setStyleSheet("color: red;");
    } else {
        ui->label_4->setText("Name:");
    }

    // Enable or disable the Submit button based on input
    checkInputs();
}
void MainWindow::checkInputs()
{
    // Check if all required fields are filled
    bool allFilled = !ui->lineEditName->text().isEmpty() &&
                     !ui->lineEditEmail->text().isEmpty() &&
                     !ui->lineEditPhone->text().isEmpty() &&
                     !ui->textEditDescription->toPlainText().isEmpty() &&
                     !ui->lineEditLocation->text().isEmpty();

    // Enable the button only if all required fields are filled
    ui->btnSubmit->setEnabled(allFilled);
}



void MainWindow::on_lineEditEmail_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->label_5->setText("Email:*");
        ui->label_5->setStyleSheet("color: red;");
    } else {
        ui->label_5->setText("Email:");
        ui->label_5->setStyleSheet("color: black;");
    }

    // Enable or disable the Submit button based on input
    checkInputs();
}



void MainWindow::on_lineEditPhone_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->label_6->setText("Phone:*");
        ui->label_6->setStyleSheet("color: red;");
    } else {
        ui->label_6->setText("Phone:");
        ui->label_6->setStyleSheet("color: black;");
    }

    // Enable or disable the Submit button based on input
    checkInputs();
}



void MainWindow::on_lineEditLocation_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->label_11->setText("Location:*");
        ui->label_11->setStyleSheet("color: red;");
    } else {
        ui->label_11->setText("Location:");
        ui->label_11->setStyleSheet("color: black;");
    }

    // Enable or disable the Submit button based on input
    checkInputs();
}


void MainWindow::on_textEditDescription_textChanged()
{
    // Get the current text from the description field
    QString descriptionText = ui->textEditDescription->toPlainText();

    // Check if the description field is empty
    if (descriptionText.isEmpty()) {
        ui->label_8->setText("Description:*");
        ui->label_8->setStyleSheet("color: red;");
    } else {
        ui->label_8->setText("Description:");
        ui->label_8->setStyleSheet("color: black;");
    }

    // Enable or disable the Submit button based on input
    checkInputs();
}

