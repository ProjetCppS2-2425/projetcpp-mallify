#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shop.h"
#include "connection.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QTableWidgetItem>

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
    ui->profile_btn->setIcon(QIcon("F:\\QT\\boutique1\\icons\\pfp.jpg"));
    ui->sidebar_btn->setIcon(
        QIcon("F:\\QT\\boutique1\\icons\\logo_sidebar_light.png"));
    ui->logo->setPixmap(
        QPixmap("F:\\QT\\boutique1\\icons\\logo_sidebar_light.png"));
    ui->logo_label->setPixmap(
        QPixmap("F:\\QT\\boutique1\\icons\\logo_light.png"));
    ui->title->setAcceptDrops(true);
    setAcceptDrops(true);
    QFile file("F:\\QT\\boutique1\\light.qss");
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }

    // Activer le bouton addShop
    ui->addShop->setEnabled(true);

    // Initialiser le tableau des boutiques
    refreshShopTable();
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
    ? "F:\\QT\\boutique1\\dark.qss"
    : "F:\\QT\\boutique1\\light.qss";
    QFile file(filePath);
    if (file.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(file.readAll());
        file.close();
    }
    if (arg1.toLower() == "dark") {
        ui->sidebar_btn->setIcon(
            QIcon("F:\\QT\\boutique1\\icons\\logo_sidebar_dark.png"));
        ui->logo->setPixmap(
            QPixmap("F:\\QT\\boutique1\\icons\\logo_sidebar_dark.png"));
        ui->logo_label->setPixmap(
            QPixmap("F:\\QT\\boutique1\\icons\\logo_dark.png"));
    } else {
        ui->sidebar_btn->setIcon(
            QIcon("F:\\QT\\boutique1\\icons\\logo_sidebar_light.png"));
        ui->logo->setPixmap(
            QPixmap("F:\\QT\\boutique1\\icons\\logo_sidebar_light.png"));
        ui->logo_label->setPixmap(
            QPixmap("F:\\QT\\boutique1\\icons\\logo_light.png"));
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

    // Rafraîchir le tableau des boutiques quand on accède à la page
    refreshShopTable();
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

// Modifiez la méthode on_addShop_clicked() pour utiliser directement la classe Shop:
void MainWindow::on_addShop_clicked()
{
    qDebug() << "Bouton addShop cliqué";

    // Récupération des informations saisies dans les champs
    QString name = ui->nom_19->text(); // Shop Name
    QString surface = ui->nom_18->text(); // Surface
    double rental_price = ui->nom_20->text().toDouble(); // Rent Price
    QString description = ui->nom_17->text(); // Description
    QString condition = ui->condition->text(); // Condition

    qDebug() << "Valeurs récupérées - Nom:" << name << "Surface:" << surface
             << "Prix:" << rental_price << "Description:" << description
             << "Condition:" << condition;

    // Valeurs par défaut pour les champs manquants
    QString category = "Retail"; // Catégorie par défaut
    int id_tenant = 0; // ID du locataire (0 si pas encore loué)

    // Générer un ID unique
    int id = QDateTime::currentDateTime().toSecsSinceEpoch() % 10000;
    qDebug() << "ID généré:" << id;

    // Vérification des données (validation basique)
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Données manquantes",
                             "Veuillez entrer un nom pour la boutique.");
        return;
    }

    if (rental_price <= 0) {
        QMessageBox::warning(this, "Prix invalide",
                             "Le prix de location doit être supérieur à 0.");
        return;
    }

    if (condition.isEmpty()) {
        condition = "Available"; // Valeur par défaut
    }

    // Créer la description complète avec la surface
    QString fullDescription = description;
    if (!surface.isEmpty()) {
        fullDescription = "Surface: " + surface + " m² - " + description;
    }

    // Créer un objet Shop et l'ajouter à la base de données
    Shop shop(id, name, category, fullDescription, condition,surface, rental_price, id_tenant);
    bool success = shop.ajouter();

    if (!success) {
        qDebug() << "Erreur lors de l'ajout de la boutique";
        QMessageBox::critical(this, "Erreur",
                              "L'ajout de la boutique a échoué.");
    } else {
        qDebug() << "Boutique ajoutée avec succès";
        QMessageBox::information(this, "Succès",
                                 "La boutique a été ajoutée avec succès.");

        // Réinitialiser les champs après l'ajout
        ui->nom_19->clear(); // Shop Name
        ui->nom_18->clear(); // Surface
        ui->nom_20->clear(); // Rent Price
        ui->nom_17->clear(); // Description
        ui->condition->clear(); // Condition

        // Rafraîchir le tableau des boutiques
        refreshShopTable();
    }
}

void MainWindow::refreshShopTable()
{
    qDebug() << "Début de refreshShopTable()";

    // Vérifier si la table existe
    QSqlQuery checkTableQuery;
    checkTableQuery.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='Shop'");
    if (!checkTableQuery.next()) {
        qDebug() << "La table Shop n'existe pas, création...";
        // Créer la table si elle n'existe pas
        QSqlQuery createTableQuery;
        bool success = createTableQuery.exec("CREATE TABLE IF NOT EXISTS Shop ("
                                             "id INTEGER PRIMARY KEY, "
                                             "name TEXT NOT NULL, "
                                             "category TEXT, "
                                             "description TEXT, "
                                             "condition TEXT, "
                                             "rental_price REAL, "
                                             "id_tenant INTEGER)");
        if (!success) {
            qDebug() << "Erreur lors de la création de la table:" << createTableQuery.lastError().text();
        }
    } else {
        qDebug() << "La table Shop existe déjà";
    }

    // Exécuter la requête pour récupérer les boutiques
    QSqlQuery query;
    bool success = query.exec("SELECT id, name, category, description, condition, rental_price, id_tenant FROM Shop");

    if (!success) {
        qDebug() << "Erreur lors de la récupération des boutiques:" << query.lastError().text();
        return;
    }

    // Afficher le nombre de résultats
    int count = 0;
    while (query.next()) {
        count++;
    }
    qDebug() << "Nombre de boutiques dans la base de données:" << count;

    // Réexécuter la requête pour remplir le tableau
    query.exec("SELECT id, name, category, description, condition, rental_price, id_tenant FROM Shop");

    // Effacer le tableau existant
    ui->tableWidget_5->setRowCount(0);

    // Remplir le tableau avec les résultats de la requête
    int row = 0;
    while (query.next()) {
        ui->tableWidget_5->insertRow(row);

        // ID
        QTableWidgetItem* idItem = new QTableWidgetItem(query.value(0).toString());
        ui->tableWidget_5->setItem(row, 0, idItem);

        // ID Tenant (owner ID)
        QTableWidgetItem* tenantItem = new QTableWidgetItem(query.value(6).toString());
        ui->tableWidget_5->setItem(row, 1, tenantItem);

        // Name (store name)
        QTableWidgetItem* nameItem = new QTableWidgetItem(query.value(1).toString());
        ui->tableWidget_5->setItem(row, 2, nameItem);

        // Rental Price
        QTableWidgetItem* priceItem = new QTableWidgetItem(query.value(5).toString());
        ui->tableWidget_5->setItem(row, 3, priceItem);

        // Condition
        QTableWidgetItem* conditionItem = new QTableWidgetItem(query.value(4).toString());
        ui->tableWidget_5->setItem(row, 4, conditionItem);

        // State (nous utiliserons la catégorie comme état pour l'instant)
        QTableWidgetItem* stateItem = new QTableWidgetItem(query.value(2).toString());
        ui->tableWidget_5->setItem(row, 5, stateItem);

        row++;
    }

    qDebug() << "Nombre de boutiques chargées dans le tableau:" << row;
}

