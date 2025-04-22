#include "mainwindow.h"
#include "ui_mainwindow.h"

static int selectedHeaderColumnTent = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeAAB6(ui);
    //===============Tenant UI Settings & Conditions=========================//
    ui->prediction_history_tent->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prediction_history_tent->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_tent->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_tent->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_tent->setSortingEnabled(true);
    ui->table_tent->horizontalHeader()->setSectionsMovable(true);
    ui->table_tent->horizontalHeader()->setSortIndicatorShown(true);

    connect(ui->table_tent->horizontalHeader(), &QHeaderView::sectionClicked, this, [](int index) { selectedHeaderColumnTent = index; });
    connect(ui->table_tent->horizontalHeader(), &QHeaderView::sectionDoubleClicked, this, [this](int i) {
        ui->table_tent->sortByColumn(i, (ui->table_tent->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder)? Qt::DescendingOrder: Qt::AscendingOrder);
    });

    ui->nom_tent->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));
    ui->tel_tent->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\+?[0-9]{8,15}$)"), this));
    ui->email_tent->setValidator(new QRegularExpressionValidator(QRegularExpression(R"(^\S+@\S+\.\S+$)"), this));
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

void MainWindow::on_add_tent_clicked()
{
    ajouter_button_clicked();
}

void MainWindow::on_refresh_tab_clicked() {
    loadTenantData();
}

void MainWindow::on_delete_tent_clicked() {
    QList<QTableWidgetItem*> selectedItems = ui->table_tent->selectedItems();

    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    int id = ui->table_tent->item(row, 0)->text().toInt();

    Tenant tenant;
    tenant.setId(id);

    if (tenant.supprimer()) {
        ui->table_tent->removeRow(row);
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
    ui->activity_level_tent->setCurrentIndex(0);

    ui->from_tent->setDate(QDate(1, 1, 2));
    ui->to_tent->setDate(QDate(1, 1, 2));
}

void MainWindow::loadTenantData() {
    QSqlQueryModel* model = Tenant::fetch();

    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    int displayedCols = colCount - 1;
    ui->table_tent->setRowCount(rowCount);
    ui->table_tent->setColumnCount(displayedCols);

    QStringList headers = {"Id", "Name", "Email", "Phone", "Shop Type", "Rented Area", "Zone", "Monthly Rent", "Lease Start", "Lease End", "Payment Status"};
    ui->table_tent->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < rowCount; ++row) {
        int tableCol = 0;
        for (int col = 0; col < colCount; ++col) {
            if (col == colCount - 1) continue;

            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->table_tent->setItem(row, tableCol, item);
            tableCol++;
        }
    }

    ui->table_tent->setColumnHidden(0, true);

    delete model;

    for (int row = 0; row < ui->table_tent->rowCount(); ++row)
    {
        ui->table_tent->setRowHidden(row, false);
    }

    ui->table_tent->clearSelection();
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
    QString activityLevel = ui->activity_level_tent->currentText();

    if (!(email.contains('@') && email.contains('.'))) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT email FROM Tenant");

    while (query.next()) {
        if (query.value(0).toString() == email) {
            QMessageBox::warning(this, "Duplicate Email", "This email is already registered.");
            return;
        }
    }

    Tenant T(name, email, tel, store_type, rented_area, zone, monthly_rent, from_date, to_date, payment_status, activityLevel);

    if (T.ajouter()) {
        QMessageBox::information(this, "Success", "Tenant added successfully.");
        loadTenantData();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add tenant.");
    }
}

void MainWindow::on_table_tent_itemSelectionChanged() {
    QList<QTableWidgetItem*> selectedItems = ui->table_tent->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    ui->nom_tent->setText(ui->table_tent->item(row, 1)->text());
    ui->email_tent->setText(ui->table_tent->item(row, 2)->text());
    ui->tel_tent->setText(ui->table_tent->item(row, 3)->text());
    ui->store_type_tent->setCurrentText(ui->table_tent->item(row, 4)->text());
    ui->rented_tent->setText(ui->table_tent->item(row, 5)->text());
    ui->zone_tent->setCurrentText(ui->table_tent->item(row, 6)->text());
    ui->monthly_tent->setText(ui->table_tent->item(row, 7)->text());

    QString leaseStart = ui->table_tent->item(row, 8)->text().trimmed();
    QString leaseEnd = ui->table_tent->item(row, 9)->text().trimmed();

    QDate startDate = QDate::fromString(leaseStart.left(10), "yyyy-MM-dd");
    QDate endDate = QDate::fromString(leaseEnd.left(10), "yyyy-MM-dd");

    ui->from_tent->setDate(startDate);
    ui->to_tent->setDate(endDate);

    ui->payment_tent->setCurrentText(ui->table_tent->item(row, 10)->text());
}

void MainWindow::on_update_tent_clicked() {
    QList<QTableWidgetItem*> selectedItems = ui->table_tent->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();

    int id = ui->table_tent->item(row, 0)->text().toInt();

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

    QString activityLevel = ui->activity_level_tent->currentText();

    Tenant T(name,email,tel,store_type,rented_area,zone,monthly_rent,from_date,to_date,payment_status,activityLevel);
    T.setId(id);
    T.update();

    loadTenantData();
}

void MainWindow::on_predict_tent_clicked() {
    double superficie = ui->space_tent->text().toDouble();
    if (superficie <= 0) {
        QMessageBox::warning(this, "Input error", "Area must be a positive number!");
        ui->space_tent->setFocus();
        return;
    }

    QString nivact = ui->nivact_tent->currentText();
    if (ui->nivact_tent->currentIndex() == 0) {
        QMessageBox::warning(this, "Input error", "Please select a valid activity level!");
        ui->nivact_tent->setFocus();
        return;
    }

    QString typeBoutique = ui->type_boutique_pred_tent->currentText();
    if (ui->type_boutique_pred_tent->currentIndex() == 0) {
        QMessageBox::warning(this, "Input error", "Please select a valid store type!");
        ui->type_boutique_pred_tent->setFocus();
        return;
    }

    bool blockA = ui->zone_a_tent->isChecked();
    bool blockB = ui->zone_b_tent->isChecked();
    bool blockC = ui->zone_c_tent->isChecked();
    bool blockD = ui->zone_d_tent->isChecked();

    int selectedZones = blockA + blockB + blockC + blockD;

    if (selectedZones != 1) {
        QMessageBox::warning(this, "Selection error",
                             "Please select only one area (A, B, C or D)!");
        return;
    }

    int niveauActivite = (nivact == "Low") ? 1 : (nivact == "Medium") ? 2 : 3;

    QMap<QString, double> typeBoutiqueEncoding;
    typeBoutiqueEncoding["Books"] = 20237.52;
    typeBoutiqueEncoding["Clothing"] = 25664.97;
    typeBoutiqueEncoding["Cosmetics"] = 30361.91;
    typeBoutiqueEncoding["Electronics"] = 25533.42;
    typeBoutiqueEncoding["Food Court"] = 20795.73;
    typeBoutiqueEncoding["Home Decor"] = 28736.87;
    typeBoutiqueEncoding["Jewelry"] = 35791.28;
    typeBoutiqueEncoding["Toys"] = 23182.85;

    double encodedTypeBoutique = typeBoutiqueEncoding.value(typeBoutique, 25000.0);

    QJsonObject json;
    json["Superficie_Louee"] = superficie;
    json["Niveau_d_Activite"] = niveauActivite;
    json["Zone_A"] = blockA ? 1 : 0;
    json["Zone_B"] = blockB ? 1 : 0;
    json["Zone_C"] = blockC ? 1 : 0;
    json["Zone_D"] = blockD ? 1 : 0;
    json["Type_Boutique"] = encodedTypeBoutique;

    QNetworkRequest request(QUrl("https://mallify-price-suggestion-model.onrender.com/predict"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument responseJson = QJsonDocument::fromJson(responseData);
            double predictedRent = responseJson.object().value("prediction").toDouble();

            ui->prediction_value_tent->setText("🔎 Predicted Rent: " + QString::number(predictedRent, 'f', 2) + " TND 🔎");

            int row = ui->prediction_history_tent->rowCount();
            ui->prediction_history_tent->insertRow(row);

            ui->prediction_history_tent->setItem(row, 0, new QTableWidgetItem(QString::number(superficie)));
            ui->prediction_history_tent->setItem(row, 1, new QTableWidgetItem(nivact));
            ui->prediction_history_tent->setItem(row, 2, new QTableWidgetItem(typeBoutique));

            QString zoneText;
            if (blockA) zoneText += "A ";
            if (blockB) zoneText += "B ";
            if (blockC) zoneText += "C ";
            if (blockD) zoneText += "D ";
            ui->prediction_history_tent->setItem(row, 3, new QTableWidgetItem(zoneText.trimmed()));

            ui->prediction_history_tent->setItem(row, 4, new QTableWidgetItem(QString::number(predictedRent, 'f', 2)));

            QDateTime now = QDateTime::currentDateTime();
            QString formattedDateTime = now.toString("yyyy-MM-dd HH:mm:ss");

            ui->prediction_history_tent->setItem(row, 5, new QTableWidgetItem(formattedDateTime));
        } else {
            ui->prediction_value_tent->setText("Error: " + reply->errorString());
            qDebug() << reply->errorString();
        }
        reply->deleteLater();
    });
}

void MainWindow::on_clear_pred_tent_clicked() {
    std::list<int> list;
    ui->space_tent->clear();

    ui->nivact_tent->setCurrentIndex(0);
    ui->type_boutique_pred_tent->setCurrentIndex(0);

    ui->zone_a_tent->setChecked(false);
    ui->zone_b_tent->setChecked(false);
    ui->zone_c_tent->setChecked(false);
    ui->zone_d_tent->setChecked(false);

    ui->prediction_value_tent->clear();
}

void MainWindow::on_export_tent_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save as", "", "CSV files (*.csv)");
    if (!filePath.isEmpty()) {
        if (Tenant::exportTableTentToCSV(filePath)) {
            QMessageBox::information(this, "Exported", "Data exported successfully to Excel.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to export data.");
        }
    }
}

void MainWindow::on_search_tent_clicked() {
    QString filterText = ui->search_box_tent->text().trimmed();

    for (int row = 0; row < ui->table_tent->rowCount(); ++row) {
        QTableWidgetItem* item = ui->table_tent->item(row, selectedHeaderColumnTent);
        bool match = item && item->text().contains(filterText, Qt::CaseInsensitive);
        ui->table_tent->setRowHidden(row, !match);
    }
}

void MainWindow::sendEmail(const QString &to, const QString &subject, const QString &body) {
    QString customPath = "C:/temp/mail.html";
    QFile f(customPath);

    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream s(&f);
    s << "From: taha.medien1@gmail.com\n";
    s << "To: " << to << "\n";
    s << "Subject: " << subject << "\n";
    s << "Content-Type: text/html; charset=UTF-8\n";
    s << "\n";
    s << body;
    f.close();

    QString w = QString("curl.exe -v --url smtps://smtp.gmail.com:465 "
                        "--mail-from \"taha.medien1@gmail.com\" "
                        "--mail-rcpt \"%1\" "
                        "--user \"taha.medien1@gmail.com:ahtatwvmnsjbxnqixhtx\" "
                        "--upload-file \"%2\"").arg(to, customPath);

    QProcess x;
    x.setProcessChannelMode(QProcess::MergedChannels);
    x.setProgram("cmd.exe");
    x.setNativeArguments(QString("/C \"%1\"").arg(w));
    x.start();
    if (!x.waitForStarted()) return;
    if (!x.waitForFinished()) return;

    if (x.exitCode() == 0) QFile::remove(customPath);
}

void MainWindow::on_auto_mail_tent_clicked() {
    QDate currentDate = QDate::currentDate();

    for (int row = 0; row < ui->table_tent->rowCount(); ++row) {
        QString name = ui->table_tent->item(row, 1)->text().trimmed();
        QString email = ui->table_tent->item(row, 2)->text().trimmed();
        QString leaseEndStr = ui->table_tent->item(row, 9)->text().trimmed();

        QDate leaseEndDate = QDateTime::fromString(leaseEndStr, "yyyy-MM-dd'T'HH:mm:ss.zzz").date();

        if (!leaseEndDate.isValid()) {
            qDebug() << "Invalid date at row" << row << ":" << email;
            continue;
        }

        int daysRemaining = currentDate.daysTo(leaseEndDate);

        if (daysRemaining <= 7) {
            QString htmlBody = QString(
                                   "<html><body style='font-family: Arial, sans-serif; line-height: 1.6; color: #333;'>"
                                   "<div style='max-width: 600px; margin: 0 auto; padding: 20px; "
                                   "border: 1px solid #ddd; border-radius: 8px; background-color: #f9f9f9;'>"
                                   "<h2 style='color: #FF4C4C; text-align: center;'>Dear %1,</h2>"
                                   "<p>We hope this message finds you well. This is a friendly reminder that your rent payment for your shop at "
                                   "<b>Azure City Mall</b> is due by <b>%2</b>.</p>"
                                   "<p>To ensure uninterrupted services, we kindly request you to settle your rent before the due date. "
                                   "If you have already made the payment, please disregard this message.</p>"
                                   "<p>If you have any questions or face any issues, please do not hesitate to get in touch with us. "
                                   "Our team is here to assist you.</p>"
                                   "<p style='color: gray; text-align: center;'>Thank you for being a valued tenant.</p>"
                                   "<p style='color: gray; text-align: center;'>Best regards,<br><b>Azure City Team</b></p>"
                                   "</div></body></html>"
                                   ).arg(name, leaseEndDate.toString("MMMM d, yyyy"));

            sendEmail(email, "Reminder: Rent Payment Due", htmlBody);
            qDebug() << "Email sent to: " << email;
        }
    }

    QMessageBox::information(this, "Notification", "Reminder emails sent.");
}

void MainWindow::generateForms_Tent(int index, QWidget* container) {
    QChart* chart = nullptr;
    QChartView* chartView = nullptr;

    QVector<QColor> pieColors = {
        QColor(255, 92, 92),
        QColor(210, 61, 61),
        QColor(255, 140, 140)
    };

    if (QLayout* oldLayout = container->layout()) {
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout* layout = new QVBoxLayout;

    if (index == 1) {
        std::list<std::pair<QString, int>> list = Tenant::getPaymentStatusWithCounts();
        QPieSeries* series = new QPieSeries();

        int total = 0;
        for (const auto& entry : list) {
            total += entry.second;
        }

        int colorIndex = 0;
        for (const auto& entry : list) {
            const QString& status = entry.first;
            int count = entry.second;
            double percentage = (100.0 * count) / total;

            QPieSlice* slice = series->append(status, count);
            slice->setLabel(QString("%1 (%2%)").arg(status).arg(percentage, 0, 'f', 1));
            slice->setLabelVisible(false);
            slice->setColor(pieColors[colorIndex % pieColors.size()]);
            colorIndex++;
        }

        chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Tenant Payment Status");
        chart->legend()->setAlignment(Qt::AlignRight);

        series->setPieSize(0.7);
        chart->setAnimationOptions(QChart::AllAnimations);
    }

    if (index == 3) {
        auto [expiredCount, notExpiredCount] = Tenant::getRentExpirationStatus();

        QBarSeries *barSeries = new QBarSeries();
        QBarSet *set = new QBarSet("Rent Status");

        *set << expiredCount << notExpiredCount;

        set->setColor(pieColors[0]);
        set->setBrush(pieColors[0]);

        barSeries->append(set);

        QStringList categories = {"Expired", "Not Expired"};
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, std::max(expiredCount, notExpiredCount) + 1);
        axisY->setTickCount(std::max(expiredCount, notExpiredCount) + 2);
        axisY->setLabelFormat("%d");

        chart = new QChart();
        chart->addSeries(barSeries);
        chart->setTitle("Rent Expiration Status");
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
        barSeries->attachAxis(axisX);
        barSeries->attachAxis(axisY);

        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->legend()->setVisible(false);
    }

    if (chart) {
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        layout->addWidget(chartView);
        container->setLayout(layout);
    }
}

void MainWindow::on_tabWidget_tent_tabBarClicked(int index) {
    if (index == 1) {
        generateForms_Tent(1, ui->chart_widget_tent_one);
        generateForms_Tent(3, ui->chart_widget_tent_three);
    }
}

void MainWindow::on_delete_pred_tent_clicked() {
    int selectedRow = ui->prediction_history_tent->currentRow();
    if (selectedRow >= 0) {
        ui->prediction_history_tent->removeRow(selectedRow);
    } else {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
    }
}

void MainWindow::on_delete_all_pred_tent_clicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Clear All ?", "Are you sure you want to delete all prediction history?" ,QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        ui->prediction_history_tent->setRowCount(0);
    }
}

void MainWindow::on_refresh_pred_tent_clicked() {
    ui->prediction_history_tent->clearSelection();
}
