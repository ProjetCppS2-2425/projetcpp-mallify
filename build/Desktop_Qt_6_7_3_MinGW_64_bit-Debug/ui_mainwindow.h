/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *grid0;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QGridLayout *gridLayout_7;
    QWidget *background0;
    QGridLayout *gridLayout_3;
    QWidget *background1;
    QGridLayout *gridLayout_4;
    QWidget *background2;
    QGridLayout *gridLayout_6;
    QWidget *background3;
    QVBoxLayout *verticalLayout;
    QLabel *logo_label;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *login_btn;
    QLabel *forgot_password_btn;
    QPushButton *login_btn_2;
    QWidget *main_page;
    QGridLayout *grid3;
    QWidget *topbar;
    QHBoxLayout *h0;
    QToolButton *sidebar_btn;
    QLabel *title;
    QToolButton *profile_btn;
    QWidget *sidebar;
    QVBoxLayout *v0;
    QLabel *logo;
    QSpacerItem *verticalSpacer;
    QPushButton *sidebar_btn_1;
    QPushButton *sidebar_btn_3;
    QPushButton *sidebar_btn_4;
    QPushButton *sidebar_btn_5;
    QPushButton *sidebar_btn_2;
    QPushButton *sidebar_btn_6;
    QStackedWidget *container;
    QWidget *employer_page;
    QGridLayout *grid1;
    QWidget *complaint_page;
    QGridLayout *gridLayout_17;
    QWidget *shop_page;
    QGridLayout *gridLayout_18;
    QTabWidget *tabWidget_4;
    QWidget *tab_18;
    QGridLayout *gridLayout_22;
    QWidget *searchform_emp_9;
    QHBoxLayout *grid5_9;
    QComboBox *comboBox_10;
    QComboBox *comboBox_11;
    QWidget *list_emp_9;
    QGridLayout *gridLayout_21;
    QPushButton *delete_emp_9;
    QTableWidget *tableWidget_5;
    QWidget *emp_form_9;
    QGridLayout *gridLayout_23;
    QLineEdit *nom_18;
    QPushButton *reset_emp_9;
    QLineEdit *nom_17;
    QLineEdit *nom_19;
    QPushButton *update_emp_9;
    QPushButton *addShop;
    QLineEdit *nom_20;
    QLineEdit *condition;
    QWidget *tab_19;
    QWidget *profile_page;
    QGridLayout *grid4;
    QWidget *service_page;
    QGridLayout *gridLayout;
    QWidget *tenants_page;
    QGridLayout *gridLayout_24;
    QWidget *profile_section;
    QVBoxLayout *verticalLayout_13;
    QTextBrowser *nom_role;
    QPushButton *settings_btn;
    QPushButton *logout_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1049, 612);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        grid0 = new QGridLayout(centralwidget);
        grid0->setSpacing(0);
        grid0->setObjectName("grid0");
        grid0->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        login_page = new QWidget();
        login_page->setObjectName("login_page");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_page->sizePolicy().hasHeightForWidth());
        login_page->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(login_page);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        background0 = new QWidget(login_page);
        background0->setObjectName("background0");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(background0->sizePolicy().hasHeightForWidth());
        background0->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(background0);
        gridLayout_3->setObjectName("gridLayout_3");
        background1 = new QWidget(background0);
        background1->setObjectName("background1");
        sizePolicy1.setHeightForWidth(background1->sizePolicy().hasHeightForWidth());
        background1->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(background1);
        gridLayout_4->setObjectName("gridLayout_4");
        background2 = new QWidget(background1);
        background2->setObjectName("background2");
        sizePolicy1.setHeightForWidth(background2->sizePolicy().hasHeightForWidth());
        background2->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(background2);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        background3 = new QWidget(background2);
        background3->setObjectName("background3");
        sizePolicy1.setHeightForWidth(background3->sizePolicy().hasHeightForWidth());
        background3->setSizePolicy(sizePolicy1);
        background3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(background3);
        verticalLayout->setObjectName("verticalLayout");
        logo_label = new QLabel(background3);
        logo_label->setObjectName("logo_label");
        sizePolicy.setHeightForWidth(logo_label->sizePolicy().hasHeightForWidth());
        logo_label->setSizePolicy(sizePolicy);
        logo_label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setBold(true);
        logo_label->setFont(font);
        logo_label->setStyleSheet(QString::fromUtf8(""));
        logo_label->setPixmap(QPixmap(QString::fromUtf8("icons/logo_dark.png")));
        logo_label->setScaledContents(true);
        logo_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(logo_label);

        username = new QLineEdit(background3);
        username->setObjectName("username");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy2);
        username->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        username->setFont(font1);
        username->setStyleSheet(QString::fromUtf8(""));
        username->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(username);

        password = new QLineEdit(background3);
        password->setObjectName("password");
        sizePolicy2.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy2);
        password->setMaximumSize(QSize(16777215, 16777215));
        password->setFont(font1);
        password->setStyleSheet(QString::fromUtf8(""));
        password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(password);

        login_btn = new QPushButton(background3);
        login_btn->setObjectName("login_btn");
        sizePolicy2.setHeightForWidth(login_btn->sizePolicy().hasHeightForWidth());
        login_btn->setSizePolicy(sizePolicy2);
        login_btn->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        login_btn->setFont(font2);

        verticalLayout->addWidget(login_btn);

        forgot_password_btn = new QLabel(background3);
        forgot_password_btn->setObjectName("forgot_password_btn");
        sizePolicy2.setHeightForWidth(forgot_password_btn->sizePolicy().hasHeightForWidth());
        forgot_password_btn->setSizePolicy(sizePolicy2);
        forgot_password_btn->setStyleSheet(QString::fromUtf8(""));
        forgot_password_btn->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(forgot_password_btn);

        login_btn_2 = new QPushButton(background3);
        login_btn_2->setObjectName("login_btn_2");
        sizePolicy2.setHeightForWidth(login_btn_2->sizePolicy().hasHeightForWidth());
        login_btn_2->setSizePolicy(sizePolicy2);
        login_btn_2->setMaximumSize(QSize(16777215, 16777215));
        login_btn_2->setFont(font2);

        verticalLayout->addWidget(login_btn_2);


        gridLayout_6->addWidget(background3, 0, 0, 1, 1);


        gridLayout_4->addWidget(background2, 0, 0, 1, 1);


        gridLayout_3->addWidget(background1, 0, 0, 1, 1);


        gridLayout_7->addWidget(background0, 0, 0, 1, 1);

        stackedWidget->addWidget(login_page);
        main_page = new QWidget();
        main_page->setObjectName("main_page");
        grid3 = new QGridLayout(main_page);
        grid3->setSpacing(0);
        grid3->setObjectName("grid3");
        grid3->setContentsMargins(0, 0, 0, 0);
        topbar = new QWidget(main_page);
        topbar->setObjectName("topbar");
        sizePolicy2.setHeightForWidth(topbar->sizePolicy().hasHeightForWidth());
        topbar->setSizePolicy(sizePolicy2);
        h0 = new QHBoxLayout(topbar);
        h0->setObjectName("h0");
        sidebar_btn = new QToolButton(topbar);
        sidebar_btn->setObjectName("sidebar_btn");
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/sidebar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sidebar_btn->setIcon(icon);

        h0->addWidget(sidebar_btn);

        title = new QLabel(topbar);
        title->setObjectName("title");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy3);

        h0->addWidget(title);

        profile_btn = new QToolButton(topbar);
        profile_btn->setObjectName("profile_btn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/pfp.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        profile_btn->setIcon(icon1);

        h0->addWidget(profile_btn);


        grid3->addWidget(topbar, 0, 1, 1, 2);

        sidebar = new QWidget(main_page);
        sidebar->setObjectName("sidebar");
        sizePolicy1.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy1);
        v0 = new QVBoxLayout(sidebar);
        v0->setObjectName("v0");
        logo = new QLabel(sidebar);
        logo->setObjectName("logo");
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setPixmap(QPixmap(QString::fromUtf8("icons/logo.svg")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        v0->addWidget(logo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        v0->addItem(verticalSpacer);

        sidebar_btn_1 = new QPushButton(sidebar);
        sidebar_btn_1->setObjectName("sidebar_btn_1");

        v0->addWidget(sidebar_btn_1);

        sidebar_btn_3 = new QPushButton(sidebar);
        sidebar_btn_3->setObjectName("sidebar_btn_3");

        v0->addWidget(sidebar_btn_3);

        sidebar_btn_4 = new QPushButton(sidebar);
        sidebar_btn_4->setObjectName("sidebar_btn_4");

        v0->addWidget(sidebar_btn_4);

        sidebar_btn_5 = new QPushButton(sidebar);
        sidebar_btn_5->setObjectName("sidebar_btn_5");

        v0->addWidget(sidebar_btn_5);

        sidebar_btn_2 = new QPushButton(sidebar);
        sidebar_btn_2->setObjectName("sidebar_btn_2");

        v0->addWidget(sidebar_btn_2);

        sidebar_btn_6 = new QPushButton(sidebar);
        sidebar_btn_6->setObjectName("sidebar_btn_6");

        v0->addWidget(sidebar_btn_6);


        grid3->addWidget(sidebar, 0, 0, 2, 1);

        container = new QStackedWidget(main_page);
        container->setObjectName("container");
        sizePolicy3.setHeightForWidth(container->sizePolicy().hasHeightForWidth());
        container->setSizePolicy(sizePolicy3);
        employer_page = new QWidget();
        employer_page->setObjectName("employer_page");
        sizePolicy3.setHeightForWidth(employer_page->sizePolicy().hasHeightForWidth());
        employer_page->setSizePolicy(sizePolicy3);
        grid1 = new QGridLayout(employer_page);
        grid1->setSpacing(7);
        grid1->setObjectName("grid1");
        grid1->setContentsMargins(11, 11, 11, 11);
        container->addWidget(employer_page);
        complaint_page = new QWidget();
        complaint_page->setObjectName("complaint_page");
        sizePolicy3.setHeightForWidth(complaint_page->sizePolicy().hasHeightForWidth());
        complaint_page->setSizePolicy(sizePolicy3);
        gridLayout_17 = new QGridLayout(complaint_page);
        gridLayout_17->setObjectName("gridLayout_17");
        container->addWidget(complaint_page);
        shop_page = new QWidget();
        shop_page->setObjectName("shop_page");
        sizePolicy3.setHeightForWidth(shop_page->sizePolicy().hasHeightForWidth());
        shop_page->setSizePolicy(sizePolicy3);
        gridLayout_18 = new QGridLayout(shop_page);
        gridLayout_18->setObjectName("gridLayout_18");
        tabWidget_4 = new QTabWidget(shop_page);
        tabWidget_4->setObjectName("tabWidget_4");
        tab_18 = new QWidget();
        tab_18->setObjectName("tab_18");
        gridLayout_22 = new QGridLayout(tab_18);
        gridLayout_22->setObjectName("gridLayout_22");
        searchform_emp_9 = new QWidget(tab_18);
        searchform_emp_9->setObjectName("searchform_emp_9");
        sizePolicy2.setHeightForWidth(searchform_emp_9->sizePolicy().hasHeightForWidth());
        searchform_emp_9->setSizePolicy(sizePolicy2);
        grid5_9 = new QHBoxLayout(searchform_emp_9);
        grid5_9->setObjectName("grid5_9");
        comboBox_10 = new QComboBox(searchform_emp_9);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName("comboBox_10");

        grid5_9->addWidget(comboBox_10);

        comboBox_11 = new QComboBox(searchform_emp_9);
        comboBox_11->setObjectName("comboBox_11");

        grid5_9->addWidget(comboBox_11);


        gridLayout_22->addWidget(searchform_emp_9, 0, 0, 1, 1);

        list_emp_9 = new QWidget(tab_18);
        list_emp_9->setObjectName("list_emp_9");
        sizePolicy3.setHeightForWidth(list_emp_9->sizePolicy().hasHeightForWidth());
        list_emp_9->setSizePolicy(sizePolicy3);
        gridLayout_21 = new QGridLayout(list_emp_9);
        gridLayout_21->setObjectName("gridLayout_21");
        delete_emp_9 = new QPushButton(list_emp_9);
        delete_emp_9->setObjectName("delete_emp_9");
        sizePolicy2.setHeightForWidth(delete_emp_9->sizePolicy().hasHeightForWidth());
        delete_emp_9->setSizePolicy(sizePolicy2);

        gridLayout_21->addWidget(delete_emp_9, 1, 0, 1, 1);

        tableWidget_5 = new QTableWidget(list_emp_9);
        if (tableWidget_5->columnCount() < 6)
            tableWidget_5->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_5->rowCount() < 1)
            tableWidget_5->setRowCount(1);
        QFont font3;
        font3.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font3);
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem6);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setStyleSheet(QString::fromUtf8(""));
        tableWidget_5->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(142);
        tableWidget_5->horizontalHeader()->setHighlightSections(false);
        tableWidget_5->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_5->horizontalHeader()->setStretchLastSection(true);

        gridLayout_21->addWidget(tableWidget_5, 0, 0, 1, 2);


        gridLayout_22->addWidget(list_emp_9, 1, 0, 1, 1);

        emp_form_9 = new QWidget(tab_18);
        emp_form_9->setObjectName("emp_form_9");
        sizePolicy3.setHeightForWidth(emp_form_9->sizePolicy().hasHeightForWidth());
        emp_form_9->setSizePolicy(sizePolicy3);
        gridLayout_23 = new QGridLayout(emp_form_9);
        gridLayout_23->setObjectName("gridLayout_23");
        nom_18 = new QLineEdit(emp_form_9);
        nom_18->setObjectName("nom_18");
        sizePolicy2.setHeightForWidth(nom_18->sizePolicy().hasHeightForWidth());
        nom_18->setSizePolicy(sizePolicy2);
        nom_18->setMinimumSize(QSize(0, 0));

        gridLayout_23->addWidget(nom_18, 1, 0, 1, 3);

        reset_emp_9 = new QPushButton(emp_form_9);
        reset_emp_9->setObjectName("reset_emp_9");
        sizePolicy2.setHeightForWidth(reset_emp_9->sizePolicy().hasHeightForWidth());
        reset_emp_9->setSizePolicy(sizePolicy2);

        gridLayout_23->addWidget(reset_emp_9, 5, 1, 1, 1);

        nom_17 = new QLineEdit(emp_form_9);
        nom_17->setObjectName("nom_17");
        sizePolicy3.setHeightForWidth(nom_17->sizePolicy().hasHeightForWidth());
        nom_17->setSizePolicy(sizePolicy3);
        nom_17->setMinimumSize(QSize(0, 0));

        gridLayout_23->addWidget(nom_17, 4, 0, 1, 3);

        nom_19 = new QLineEdit(emp_form_9);
        nom_19->setObjectName("nom_19");
        sizePolicy2.setHeightForWidth(nom_19->sizePolicy().hasHeightForWidth());
        nom_19->setSizePolicy(sizePolicy2);
        nom_19->setMinimumSize(QSize(0, 0));

        gridLayout_23->addWidget(nom_19, 0, 0, 1, 3);

        update_emp_9 = new QPushButton(emp_form_9);
        update_emp_9->setObjectName("update_emp_9");
        sizePolicy2.setHeightForWidth(update_emp_9->sizePolicy().hasHeightForWidth());
        update_emp_9->setSizePolicy(sizePolicy2);

        gridLayout_23->addWidget(update_emp_9, 5, 0, 1, 1);

        addShop = new QPushButton(emp_form_9);
        addShop->setObjectName("addShop");
        addShop->setEnabled(true);
        sizePolicy2.setHeightForWidth(addShop->sizePolicy().hasHeightForWidth());
        addShop->setSizePolicy(sizePolicy2);

        gridLayout_23->addWidget(addShop, 5, 2, 1, 1);

        nom_20 = new QLineEdit(emp_form_9);
        nom_20->setObjectName("nom_20");
        sizePolicy2.setHeightForWidth(nom_20->sizePolicy().hasHeightForWidth());
        nom_20->setSizePolicy(sizePolicy2);
        nom_20->setMinimumSize(QSize(0, 0));

        gridLayout_23->addWidget(nom_20, 2, 0, 1, 3);

        condition = new QLineEdit(emp_form_9);
        condition->setObjectName("condition");

        gridLayout_23->addWidget(condition, 3, 0, 1, 3);


        gridLayout_22->addWidget(emp_form_9, 0, 1, 2, 1);

        tabWidget_4->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName("tab_19");
        tabWidget_4->addTab(tab_19, QString());

        gridLayout_18->addWidget(tabWidget_4, 0, 0, 1, 1);

        container->addWidget(shop_page);
        profile_page = new QWidget();
        profile_page->setObjectName("profile_page");
        sizePolicy3.setHeightForWidth(profile_page->sizePolicy().hasHeightForWidth());
        profile_page->setSizePolicy(sizePolicy3);
        grid4 = new QGridLayout(profile_page);
        grid4->setObjectName("grid4");
        container->addWidget(profile_page);
        service_page = new QWidget();
        service_page->setObjectName("service_page");
        sizePolicy3.setHeightForWidth(service_page->sizePolicy().hasHeightForWidth());
        service_page->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(service_page);
        gridLayout->setObjectName("gridLayout");
        container->addWidget(service_page);
        tenants_page = new QWidget();
        tenants_page->setObjectName("tenants_page");
        sizePolicy3.setHeightForWidth(tenants_page->sizePolicy().hasHeightForWidth());
        tenants_page->setSizePolicy(sizePolicy3);
        gridLayout_24 = new QGridLayout(tenants_page);
        gridLayout_24->setObjectName("gridLayout_24");
        container->addWidget(tenants_page);

        grid3->addWidget(container, 1, 2, 1, 1);

        stackedWidget->addWidget(main_page);

        grid0->addWidget(stackedWidget, 0, 0, 1, 1);

        profile_section = new QWidget(centralwidget);
        profile_section->setObjectName("profile_section");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(profile_section->sizePolicy().hasHeightForWidth());
        profile_section->setSizePolicy(sizePolicy4);
        profile_section->setMinimumSize(QSize(0, 0));
        profile_section->setMaximumSize(QSize(0, 0));
        verticalLayout_13 = new QVBoxLayout(profile_section);
        verticalLayout_13->setSpacing(2);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(2, 2, 2, 2);
        nom_role = new QTextBrowser(profile_section);
        nom_role->setObjectName("nom_role");
        sizePolicy2.setHeightForWidth(nom_role->sizePolicy().hasHeightForWidth());
        nom_role->setSizePolicy(sizePolicy2);
        nom_role->setStyleSheet(QString::fromUtf8("max-height:50px;"));

        verticalLayout_13->addWidget(nom_role);

        settings_btn = new QPushButton(profile_section);
        settings_btn->setObjectName("settings_btn");

        verticalLayout_13->addWidget(settings_btn);

        logout_btn = new QPushButton(profile_section);
        logout_btn->setObjectName("logout_btn");

        verticalLayout_13->addWidget(logout_btn);


        grid0->addWidget(profile_section, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1049, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        container->setCurrentIndex(2);
        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo_label->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "  User Name", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Password", nullptr));
        login_btn->setText(QCoreApplication::translate("MainWindow", "L o g  I n", nullptr));
        forgot_password_btn->setText(QCoreApplication::translate("MainWindow", "forget password?", nullptr));
        login_btn_2->setText(QCoreApplication::translate("MainWindow", "L o g  I n With Camera", nullptr));
        sidebar_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Employers Mangement", nullptr));
        profile_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        logo->setText(QString());
        sidebar_btn_1->setText(QCoreApplication::translate("MainWindow", "Employers", nullptr));
        sidebar_btn_3->setText(QCoreApplication::translate("MainWindow", "Tenants", nullptr));
        sidebar_btn_4->setText(QCoreApplication::translate("MainWindow", "Shops", nullptr));
        sidebar_btn_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        sidebar_btn_2->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        sidebar_btn_6->setText(QCoreApplication::translate("MainWindow", "Complaints", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "Filter By State", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "Rented", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "Not Rented", nullptr));

        delete_emp_9->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "store ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "owner ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "store name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "rent price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "condition", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "state", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "STORE1", nullptr));
        nom_18->setText(QString());
        nom_18->setPlaceholderText(QCoreApplication::translate("MainWindow", "Surface", nullptr));
        reset_emp_9->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        nom_17->setText(QString());
        nom_17->setPlaceholderText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        nom_19->setText(QString());
        nom_19->setPlaceholderText(QCoreApplication::translate("MainWindow", "Shop Name", nullptr));
        update_emp_9->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        addShop->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        nom_20->setText(QString());
        nom_20->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rent Price", nullptr));
        condition->setText(QCoreApplication::translate("MainWindow", "condition", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_18), QCoreApplication::translate("MainWindow", "List Shops", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_19), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        nom_role->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ahmed Amine</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Role</span></p></body></html>", nullptr));
        settings_btn->setText(QCoreApplication::translate("MainWindow", "profile", nullptr));
        logout_btn->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
