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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *grid0;
    QWidget *login_page;
    QVBoxLayout *v2;
    QLabel *logo_label;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *login_btn;
    QPushButton *forgot_password_btn;
    QPushButton *login_btn_2;
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
    QWidget *topbar;
    QHBoxLayout *h0;
    QToolButton *sidebar_btn;
    QLabel *title;
    QToolButton *profile_btn;
    QStackedWidget *container;
    QWidget *employer_page;
    QGridLayout *grid1;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_6;
    QWidget *searchform_emp;
    QHBoxLayout *grid5;
    QToolButton *resetfilter_emp;
    QToolButton *unselect_btn;
    QLineEdit *searchbox_emp;
    QToolButton *emp_search_btn;
    QToolButton *camera_emp;
    QWidget *list_emp;
    QGridLayout *grid6;
    QPushButton *export_emp;
    QPushButton *import_emp;
    QLabel *rows_selected;
    QPushButton *delete_emp;
    QTableView *table_emp;
    QWidget *emp_form;
    QGridLayout *grid19;
    QLabel *pfp;
    QGridLayout *gridLayout_2;
    QLabel *label_1;
    QLabel *label_2;
    QLineEdit *first_name;
    QLineEdit *last_name;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *phone;
    QLineEdit *email;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QComboBox *position;
    QGridLayout *gridLayout_4;
    QCheckBox *a1;
    QCheckBox *a2;
    QCheckBox *a6;
    QCheckBox *a5;
    QCheckBox *a4;
    QCheckBox *a3;
    QLabel *label_13;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QDoubleSpinBox *base_salary;
    QSpinBox *hours_worked;
    QSpinBox *absences;
    QSpinBox *lateness;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_9;
    QLabel *label_102;
    QLabel *label_20;
    QDateEdit *hire_date;
    QDoubleSpinBox *customer_feedback;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_emp;
    QPushButton *update_emp;
    QPushButton *reset_emp;
    QWidget *tab_2;
    QWidget *complaint_page;
    QGridLayout *gridLayout_17;
    QWidget *shop_page;
    QGridLayout *gridLayout_18;
    QWidget *profile_page;
    QGridLayout *grid4;
    QGroupBox *groupBox_20;
    QGridLayout *grid24;
    QLabel *pfp_profile;
    QPushButton *request_change_btn;
    QTextEdit *textEdit;
    QGroupBox *groupBox_21;
    QGridLayout *grid25;
    QLabel *label_3;
    QLineEdit *current_password;
    QLabel *label_10;
    QLineEdit *new_password;
    QLabel *label_11;
    QLineEdit *confirm_password;
    QPushButton *change_password_profile;
    QPushButton *forget_password_profile;
    QLabel *label_12;
    QComboBox *profile_light_mod;
    QWidget *service_page;
    QGridLayout *gridLayout;
    QWidget *tenants_page;
    QGridLayout *gridLayout_24;
    QWidget *page;
    QGridLayout *gridLayout_29;
    QWidget *profile_section;
    QVBoxLayout *v1;
    QTextBrowser *nom_role;
    QPushButton *settings_btn;
    QPushButton *logout_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1214, 764);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        grid0 = new QGridLayout(centralwidget);
        grid0->setSpacing(0);
        grid0->setObjectName("grid0");
        grid0->setContentsMargins(0, 0, 0, 0);
        login_page = new QWidget(centralwidget);
        login_page->setObjectName("login_page");
        sizePolicy.setHeightForWidth(login_page->sizePolicy().hasHeightForWidth());
        login_page->setSizePolicy(sizePolicy);
        v2 = new QVBoxLayout(login_page);
        v2->setObjectName("v2");
        logo_label = new QLabel(login_page);
        logo_label->setObjectName("logo_label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo_label->sizePolicy().hasHeightForWidth());
        logo_label->setSizePolicy(sizePolicy1);

        v2->addWidget(logo_label);

        username = new QLineEdit(login_page);
        username->setObjectName("username");

        v2->addWidget(username);

        password = new QLineEdit(login_page);
        password->setObjectName("password");

        v2->addWidget(password);

        login_btn = new QPushButton(login_page);
        login_btn->setObjectName("login_btn");
        sizePolicy1.setHeightForWidth(login_btn->sizePolicy().hasHeightForWidth());
        login_btn->setSizePolicy(sizePolicy1);

        v2->addWidget(login_btn);

        forgot_password_btn = new QPushButton(login_page);
        forgot_password_btn->setObjectName("forgot_password_btn");
        sizePolicy1.setHeightForWidth(forgot_password_btn->sizePolicy().hasHeightForWidth());
        forgot_password_btn->setSizePolicy(sizePolicy1);

        v2->addWidget(forgot_password_btn);

        login_btn_2 = new QPushButton(login_page);
        login_btn_2->setObjectName("login_btn_2");
        sizePolicy1.setHeightForWidth(login_btn_2->sizePolicy().hasHeightForWidth());
        login_btn_2->setSizePolicy(sizePolicy1);

        v2->addWidget(login_btn_2);


        grid0->addWidget(login_page, 0, 0, 3, 2);

        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy2);
        v0 = new QVBoxLayout(sidebar);
        v0->setObjectName("v0");
        logo = new QLabel(sidebar);
        logo->setObjectName("logo");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy3);
        logo->setPixmap(QPixmap(QString::fromUtf8("icons/logo.svg")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        v0->addWidget(logo);

        verticalSpacer = new QSpacerItem(20, 300, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

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


        grid0->addWidget(sidebar, 0, 2, 3, 1);

        topbar = new QWidget(centralwidget);
        topbar->setObjectName("topbar");
        sizePolicy1.setHeightForWidth(topbar->sizePolicy().hasHeightForWidth());
        topbar->setSizePolicy(sizePolicy1);
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
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);

        h0->addWidget(title);

        profile_btn = new QToolButton(topbar);
        profile_btn->setObjectName("profile_btn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/pfp.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        profile_btn->setIcon(icon1);

        h0->addWidget(profile_btn);


        grid0->addWidget(topbar, 0, 3, 1, 1);

        container = new QStackedWidget(centralwidget);
        container->setObjectName("container");
        sizePolicy.setHeightForWidth(container->sizePolicy().hasHeightForWidth());
        container->setSizePolicy(sizePolicy);
        employer_page = new QWidget();
        employer_page->setObjectName("employer_page");
        sizePolicy.setHeightForWidth(employer_page->sizePolicy().hasHeightForWidth());
        employer_page->setSizePolicy(sizePolicy);
        grid1 = new QGridLayout(employer_page);
        grid1->setSpacing(7);
        grid1->setObjectName("grid1");
        grid1->setContentsMargins(11, 11, 11, 11);
        tabWidget = new QTabWidget(employer_page);
        tabWidget->setObjectName("tabWidget");
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        gridLayout_6 = new QGridLayout(tab_1);
        gridLayout_6->setObjectName("gridLayout_6");
        searchform_emp = new QWidget(tab_1);
        searchform_emp->setObjectName("searchform_emp");
        sizePolicy1.setHeightForWidth(searchform_emp->sizePolicy().hasHeightForWidth());
        searchform_emp->setSizePolicy(sizePolicy1);
        grid5 = new QHBoxLayout(searchform_emp);
        grid5->setSpacing(7);
        grid5->setObjectName("grid5");
        grid5->setContentsMargins(11, 11, 11, 11);
        resetfilter_emp = new QToolButton(searchform_emp);
        resetfilter_emp->setObjectName("resetfilter_emp");
        sizePolicy3.setHeightForWidth(resetfilter_emp->sizePolicy().hasHeightForWidth());
        resetfilter_emp->setSizePolicy(sizePolicy3);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        resetfilter_emp->setIcon(icon2);

        grid5->addWidget(resetfilter_emp);

        unselect_btn = new QToolButton(searchform_emp);
        unselect_btn->setObjectName("unselect_btn");
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        unselect_btn->setIcon(icon3);

        grid5->addWidget(unselect_btn);

        searchbox_emp = new QLineEdit(searchform_emp);
        searchbox_emp->setObjectName("searchbox_emp");

        grid5->addWidget(searchbox_emp);

        emp_search_btn = new QToolButton(searchform_emp);
        emp_search_btn->setObjectName("emp_search_btn");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        emp_search_btn->setIcon(icon4);

        grid5->addWidget(emp_search_btn);

        camera_emp = new QToolButton(searchform_emp);
        camera_emp->setObjectName("camera_emp");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        camera_emp->setIcon(icon5);

        grid5->addWidget(camera_emp);


        gridLayout_6->addWidget(searchform_emp, 0, 0, 1, 2);

        list_emp = new QWidget(tab_1);
        list_emp->setObjectName("list_emp");
        sizePolicy.setHeightForWidth(list_emp->sizePolicy().hasHeightForWidth());
        list_emp->setSizePolicy(sizePolicy);
        grid6 = new QGridLayout(list_emp);
        grid6->setSpacing(7);
        grid6->setObjectName("grid6");
        grid6->setContentsMargins(11, 11, 11, 11);
        export_emp = new QPushButton(list_emp);
        export_emp->setObjectName("export_emp");
        sizePolicy1.setHeightForWidth(export_emp->sizePolicy().hasHeightForWidth());
        export_emp->setSizePolicy(sizePolicy1);

        grid6->addWidget(export_emp, 2, 1, 1, 1);

        import_emp = new QPushButton(list_emp);
        import_emp->setObjectName("import_emp");
        sizePolicy1.setHeightForWidth(import_emp->sizePolicy().hasHeightForWidth());
        import_emp->setSizePolicy(sizePolicy1);

        grid6->addWidget(import_emp, 2, 2, 1, 1);

        rows_selected = new QLabel(list_emp);
        rows_selected->setObjectName("rows_selected");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(rows_selected->sizePolicy().hasHeightForWidth());
        rows_selected->setSizePolicy(sizePolicy4);

        grid6->addWidget(rows_selected, 0, 0, 1, 3);

        delete_emp = new QPushButton(list_emp);
        delete_emp->setObjectName("delete_emp");
        sizePolicy1.setHeightForWidth(delete_emp->sizePolicy().hasHeightForWidth());
        delete_emp->setSizePolicy(sizePolicy1);

        grid6->addWidget(delete_emp, 2, 0, 1, 1);

        table_emp = new QTableView(list_emp);
        table_emp->setObjectName("table_emp");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        table_emp->setFont(font);
        table_emp->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        table_emp->setStyleSheet(QString::fromUtf8(""));
        table_emp->setFrameShape(QFrame::Shape::NoFrame);
        table_emp->setEditTriggers(QAbstractItemView::EditTrigger::AllEditTriggers);
        table_emp->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        table_emp->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        table_emp->setShowGrid(false);
        table_emp->setGridStyle(Qt::PenStyle::NoPen);
        table_emp->setSortingEnabled(true);
        table_emp->setWordWrap(true);
        table_emp->setCornerButtonEnabled(false);

        grid6->addWidget(table_emp, 1, 0, 1, 3);


        gridLayout_6->addWidget(list_emp, 1, 0, 1, 1);

        emp_form = new QWidget(tab_1);
        emp_form->setObjectName("emp_form");
        grid19 = new QGridLayout(emp_form);
        grid19->setObjectName("grid19");
        pfp = new QLabel(emp_form);
        pfp->setObjectName("pfp");
        sizePolicy.setHeightForWidth(pfp->sizePolicy().hasHeightForWidth());
        pfp->setSizePolicy(sizePolicy);

        grid19->addWidget(pfp, 0, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_1 = new QLabel(emp_form);
        label_1->setObjectName("label_1");
        sizePolicy1.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QLabel(emp_form);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        first_name = new QLineEdit(emp_form);
        first_name->setObjectName("first_name");

        gridLayout_2->addWidget(first_name, 1, 0, 1, 1);

        last_name = new QLineEdit(emp_form);
        last_name->setObjectName("last_name");

        gridLayout_2->addWidget(last_name, 1, 1, 1, 1);


        grid19->addLayout(gridLayout_2, 1, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName("gridLayout_3");
        label_4 = new QLabel(emp_form);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        phone = new QLineEdit(emp_form);
        phone->setObjectName("phone");

        gridLayout_3->addWidget(phone, 1, 1, 1, 1);

        email = new QLineEdit(emp_form);
        email->setObjectName("email");

        gridLayout_3->addWidget(email, 1, 0, 1, 1);

        label_5 = new QLabel(emp_form);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);


        grid19->addLayout(gridLayout_3, 2, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        label_6 = new QLabel(emp_form);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_6);

        position = new QComboBox(emp_form);
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->addItem(QString());
        position->setObjectName("position");
        sizePolicy1.setHeightForWidth(position->sizePolicy().hasHeightForWidth());
        position->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(position);


        grid19->addLayout(verticalLayout, 3, 0, 1, 3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName("gridLayout_4");
        a1 = new QCheckBox(emp_form);
        a1->setObjectName("a1");
        sizePolicy1.setHeightForWidth(a1->sizePolicy().hasHeightForWidth());
        a1->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a1, 1, 0, 1, 1);

        a2 = new QCheckBox(emp_form);
        a2->setObjectName("a2");
        sizePolicy1.setHeightForWidth(a2->sizePolicy().hasHeightForWidth());
        a2->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a2, 1, 1, 1, 1);

        a6 = new QCheckBox(emp_form);
        a6->setObjectName("a6");
        sizePolicy1.setHeightForWidth(a6->sizePolicy().hasHeightForWidth());
        a6->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a6, 2, 2, 1, 1);

        a5 = new QCheckBox(emp_form);
        a5->setObjectName("a5");
        sizePolicy1.setHeightForWidth(a5->sizePolicy().hasHeightForWidth());
        a5->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a5, 2, 1, 1, 1);

        a4 = new QCheckBox(emp_form);
        a4->setObjectName("a4");
        sizePolicy1.setHeightForWidth(a4->sizePolicy().hasHeightForWidth());
        a4->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a4, 2, 0, 1, 1);

        a3 = new QCheckBox(emp_form);
        a3->setObjectName("a3");
        sizePolicy1.setHeightForWidth(a3->sizePolicy().hasHeightForWidth());
        a3->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(a3, 1, 2, 1, 1);

        label_13 = new QLabel(emp_form);
        label_13->setObjectName("label_13");
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_13, 0, 0, 1, 3);


        grid19->addLayout(gridLayout_4, 4, 0, 1, 3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName("gridLayout_5");
        label_17 = new QLabel(emp_form);
        label_17->setObjectName("label_17");
        sizePolicy3.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_17, 0, 3, 1, 1);

        label_14 = new QLabel(emp_form);
        label_14->setObjectName("label_14");
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_14, 0, 1, 1, 1);

        label_15 = new QLabel(emp_form);
        label_15->setObjectName("label_15");
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_15, 0, 2, 1, 1);

        label_16 = new QLabel(emp_form);
        label_16->setObjectName("label_16");
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_16, 0, 0, 1, 1);

        base_salary = new QDoubleSpinBox(emp_form);
        base_salary->setObjectName("base_salary");
        sizePolicy1.setHeightForWidth(base_salary->sizePolicy().hasHeightForWidth());
        base_salary->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(base_salary, 1, 0, 1, 1);

        hours_worked = new QSpinBox(emp_form);
        hours_worked->setObjectName("hours_worked");
        sizePolicy1.setHeightForWidth(hours_worked->sizePolicy().hasHeightForWidth());
        hours_worked->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(hours_worked, 1, 1, 1, 1);

        absences = new QSpinBox(emp_form);
        absences->setObjectName("absences");
        sizePolicy1.setHeightForWidth(absences->sizePolicy().hasHeightForWidth());
        absences->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(absences, 1, 2, 1, 1);

        lateness = new QSpinBox(emp_form);
        lateness->setObjectName("lateness");
        sizePolicy1.setHeightForWidth(lateness->sizePolicy().hasHeightForWidth());
        lateness->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(lateness, 1, 3, 1, 1);


        grid19->addLayout(gridLayout_5, 5, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        grid19->addLayout(horizontalLayout_2, 6, 0, 1, 3);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(2);
        gridLayout_9->setObjectName("gridLayout_9");
        label_102 = new QLabel(emp_form);
        label_102->setObjectName("label_102");
        sizePolicy1.setHeightForWidth(label_102->sizePolicy().hasHeightForWidth());
        label_102->setSizePolicy(sizePolicy1);

        gridLayout_9->addWidget(label_102, 0, 0, 1, 1);

        label_20 = new QLabel(emp_form);
        label_20->setObjectName("label_20");
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        gridLayout_9->addWidget(label_20, 0, 1, 1, 1);

        hire_date = new QDateEdit(emp_form);
        hire_date->setObjectName("hire_date");
        sizePolicy1.setHeightForWidth(hire_date->sizePolicy().hasHeightForWidth());
        hire_date->setSizePolicy(sizePolicy1);

        gridLayout_9->addWidget(hire_date, 1, 1, 1, 1);

        customer_feedback = new QDoubleSpinBox(emp_form);
        customer_feedback->setObjectName("customer_feedback");
        customer_feedback->setMaximum(100.000000000000000);

        gridLayout_9->addWidget(customer_feedback, 1, 0, 1, 1);


        grid19->addLayout(gridLayout_9, 7, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        grid19->addItem(horizontalSpacer, 8, 0, 1, 3);

        add_emp = new QPushButton(emp_form);
        add_emp->setObjectName("add_emp");
        sizePolicy1.setHeightForWidth(add_emp->sizePolicy().hasHeightForWidth());
        add_emp->setSizePolicy(sizePolicy1);

        grid19->addWidget(add_emp, 9, 0, 1, 1);

        update_emp = new QPushButton(emp_form);
        update_emp->setObjectName("update_emp");
        sizePolicy1.setHeightForWidth(update_emp->sizePolicy().hasHeightForWidth());
        update_emp->setSizePolicy(sizePolicy1);

        grid19->addWidget(update_emp, 9, 1, 1, 1);

        reset_emp = new QPushButton(emp_form);
        reset_emp->setObjectName("reset_emp");
        sizePolicy1.setHeightForWidth(reset_emp->sizePolicy().hasHeightForWidth());
        reset_emp->setSizePolicy(sizePolicy1);

        grid19->addWidget(reset_emp, 9, 2, 1, 1);


        gridLayout_6->addWidget(emp_form, 1, 1, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        grid1->addWidget(tabWidget, 0, 0, 1, 1);

        container->addWidget(employer_page);
        complaint_page = new QWidget();
        complaint_page->setObjectName("complaint_page");
        sizePolicy.setHeightForWidth(complaint_page->sizePolicy().hasHeightForWidth());
        complaint_page->setSizePolicy(sizePolicy);
        gridLayout_17 = new QGridLayout(complaint_page);
        gridLayout_17->setObjectName("gridLayout_17");
        container->addWidget(complaint_page);
        shop_page = new QWidget();
        shop_page->setObjectName("shop_page");
        sizePolicy.setHeightForWidth(shop_page->sizePolicy().hasHeightForWidth());
        shop_page->setSizePolicy(sizePolicy);
        gridLayout_18 = new QGridLayout(shop_page);
        gridLayout_18->setObjectName("gridLayout_18");
        container->addWidget(shop_page);
        profile_page = new QWidget();
        profile_page->setObjectName("profile_page");
        sizePolicy.setHeightForWidth(profile_page->sizePolicy().hasHeightForWidth());
        profile_page->setSizePolicy(sizePolicy);
        grid4 = new QGridLayout(profile_page);
        grid4->setObjectName("grid4");
        groupBox_20 = new QGroupBox(profile_page);
        groupBox_20->setObjectName("groupBox_20");
        sizePolicy.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy);
        grid24 = new QGridLayout(groupBox_20);
        grid24->setObjectName("grid24");
        pfp_profile = new QLabel(groupBox_20);
        pfp_profile->setObjectName("pfp_profile");
        sizePolicy.setHeightForWidth(pfp_profile->sizePolicy().hasHeightForWidth());
        pfp_profile->setSizePolicy(sizePolicy);
        pfp_profile->setScaledContents(true);

        grid24->addWidget(pfp_profile, 0, 0, 1, 1);

        request_change_btn = new QPushButton(groupBox_20);
        request_change_btn->setObjectName("request_change_btn");
        sizePolicy1.setHeightForWidth(request_change_btn->sizePolicy().hasHeightForWidth());
        request_change_btn->setSizePolicy(sizePolicy1);

        grid24->addWidget(request_change_btn, 3, 0, 1, 1);

        textEdit = new QTextEdit(groupBox_20);
        textEdit->setObjectName("textEdit");
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);

        grid24->addWidget(textEdit, 1, 0, 1, 1);


        grid4->addWidget(groupBox_20, 0, 0, 1, 1);

        groupBox_21 = new QGroupBox(profile_page);
        groupBox_21->setObjectName("groupBox_21");
        sizePolicy.setHeightForWidth(groupBox_21->sizePolicy().hasHeightForWidth());
        groupBox_21->setSizePolicy(sizePolicy);
        groupBox_21->setStyleSheet(QString::fromUtf8(""));
        grid25 = new QGridLayout(groupBox_21);
        grid25->setObjectName("grid25");
        label_3 = new QLabel(groupBox_21);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        grid25->addWidget(label_3, 0, 0, 1, 1);

        current_password = new QLineEdit(groupBox_21);
        current_password->setObjectName("current_password");

        grid25->addWidget(current_password, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_21);
        label_10->setObjectName("label_10");
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        grid25->addWidget(label_10, 1, 0, 1, 1);

        new_password = new QLineEdit(groupBox_21);
        new_password->setObjectName("new_password");

        grid25->addWidget(new_password, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox_21);
        label_11->setObjectName("label_11");
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        grid25->addWidget(label_11, 2, 0, 1, 1);

        confirm_password = new QLineEdit(groupBox_21);
        confirm_password->setObjectName("confirm_password");

        grid25->addWidget(confirm_password, 2, 1, 1, 1);

        change_password_profile = new QPushButton(groupBox_21);
        change_password_profile->setObjectName("change_password_profile");
        sizePolicy1.setHeightForWidth(change_password_profile->sizePolicy().hasHeightForWidth());
        change_password_profile->setSizePolicy(sizePolicy1);

        grid25->addWidget(change_password_profile, 3, 0, 1, 1);

        forget_password_profile = new QPushButton(groupBox_21);
        forget_password_profile->setObjectName("forget_password_profile");
        sizePolicy1.setHeightForWidth(forget_password_profile->sizePolicy().hasHeightForWidth());
        forget_password_profile->setSizePolicy(sizePolicy1);

        grid25->addWidget(forget_password_profile, 3, 1, 1, 1);

        label_12 = new QLabel(groupBox_21);
        label_12->setObjectName("label_12");
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        grid25->addWidget(label_12, 4, 0, 1, 1);

        profile_light_mod = new QComboBox(groupBox_21);
        profile_light_mod->addItem(QString());
        profile_light_mod->addItem(QString());
        profile_light_mod->setObjectName("profile_light_mod");
        sizePolicy1.setHeightForWidth(profile_light_mod->sizePolicy().hasHeightForWidth());
        profile_light_mod->setSizePolicy(sizePolicy1);

        grid25->addWidget(profile_light_mod, 4, 1, 1, 1);


        grid4->addWidget(groupBox_21, 1, 0, 1, 1);

        container->addWidget(profile_page);
        service_page = new QWidget();
        service_page->setObjectName("service_page");
        sizePolicy.setHeightForWidth(service_page->sizePolicy().hasHeightForWidth());
        service_page->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(service_page);
        gridLayout->setObjectName("gridLayout");
        container->addWidget(service_page);
        tenants_page = new QWidget();
        tenants_page->setObjectName("tenants_page");
        sizePolicy.setHeightForWidth(tenants_page->sizePolicy().hasHeightForWidth());
        tenants_page->setSizePolicy(sizePolicy);
        gridLayout_24 = new QGridLayout(tenants_page);
        gridLayout_24->setObjectName("gridLayout_24");
        container->addWidget(tenants_page);
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_29 = new QGridLayout(page);
        gridLayout_29->setObjectName("gridLayout_29");
        container->addWidget(page);

        grid0->addWidget(container, 1, 3, 2, 1);

        profile_section = new QWidget(centralwidget);
        profile_section->setObjectName("profile_section");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(profile_section->sizePolicy().hasHeightForWidth());
        profile_section->setSizePolicy(sizePolicy5);
        profile_section->setMinimumSize(QSize(0, 0));
        profile_section->setMaximumSize(QSize(0, 0));
        v1 = new QVBoxLayout(profile_section);
        v1->setSpacing(2);
        v1->setObjectName("v1");
        v1->setContentsMargins(2, 2, 2, 2);
        nom_role = new QTextBrowser(profile_section);
        nom_role->setObjectName("nom_role");
        sizePolicy1.setHeightForWidth(nom_role->sizePolicy().hasHeightForWidth());
        nom_role->setSizePolicy(sizePolicy1);
        nom_role->setStyleSheet(QString::fromUtf8("max-height:50px;"));

        v1->addWidget(nom_role);

        settings_btn = new QPushButton(profile_section);
        settings_btn->setObjectName("settings_btn");

        v1->addWidget(settings_btn);

        logout_btn = new QPushButton(profile_section);
        logout_btn->setObjectName("logout_btn");

        v1->addWidget(logout_btn);


        grid0->addWidget(profile_section, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1214, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        container->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo_label->setText(QCoreApplication::translate("MainWindow", "image", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        login_btn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        forgot_password_btn->setText(QCoreApplication::translate("MainWindow", "Forget Password?", nullptr));
        login_btn_2->setText(QCoreApplication::translate("MainWindow", "Login With Camera", nullptr));
        logo->setText(QString());
        sidebar_btn_1->setText(QCoreApplication::translate("MainWindow", "Employers", nullptr));
        sidebar_btn_3->setText(QCoreApplication::translate("MainWindow", "Tenants", nullptr));
        sidebar_btn_4->setText(QCoreApplication::translate("MainWindow", "Shops", nullptr));
        sidebar_btn_5->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        sidebar_btn_2->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        sidebar_btn_6->setText(QCoreApplication::translate("MainWindow", "Complaints", nullptr));
        sidebar_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Employers Mangement", nullptr));
        profile_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        resetfilter_emp->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        unselect_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        emp_search_btn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        camera_emp->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        export_emp->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        import_emp->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        rows_selected->setText(QString());
        delete_emp->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pfp->setText(QCoreApplication::translate("MainWindow", "image", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        position->setItemText(0, QCoreApplication::translate("MainWindow", "Administrator", nullptr));
        position->setItemText(1, QCoreApplication::translate("MainWindow", "Human Resources", nullptr));
        position->setItemText(2, QCoreApplication::translate("MainWindow", "Service Manager", nullptr));
        position->setItemText(3, QCoreApplication::translate("MainWindow", "Finance Manager", nullptr));
        position->setItemText(4, QCoreApplication::translate("MainWindow", "Complaints Manager", nullptr));
        position->setItemText(5, QCoreApplication::translate("MainWindow", "Tenant Manager", nullptr));
        position->setItemText(6, QCoreApplication::translate("MainWindow", "Shops Manager", nullptr));

        a1->setText(QCoreApplication::translate("MainWindow", "Employers", nullptr));
        a2->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        a6->setText(QCoreApplication::translate("MainWindow", "Tenants", nullptr));
        a5->setText(QCoreApplication::translate("MainWindow", "Complaints", nullptr));
        a4->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        a3->setText(QCoreApplication::translate("MainWindow", "Finance", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Access & Permissions", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Lateness", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Hours Worked", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Absences", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Base Salary", nullptr));
        label_102->setText(QCoreApplication::translate("MainWindow", "Customer Feedback", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Hire Date", nullptr));
        add_emp->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        update_emp->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        reset_emp->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "List Employers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "Your Information", nullptr));
        pfp_profile->setText(QCoreApplication::translate("MainWindow", "image here", nullptr));
        request_change_btn->setText(QCoreApplication::translate("MainWindow", "Request Change", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">First Name:          Ahmed Amine</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Last Name:           Boussetta</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Email:               ahmed@labla.com</p>\n"
"<p style=\" margin-top:0px; margin-bo"
                        "ttom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Phone:               +123 456 7890</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Position:            Administrator</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hire Date:           01-Jan-2023</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Base Salary:        lihowa</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hours Worked:        240 hours</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Absences:            2</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\">Lateness:            4</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Customer Rating:     4.8 / 5</p></body></html>", nullptr));
        groupBox_21->setTitle(QCoreApplication::translate("MainWindow", "Account Security & Preferences", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", " Confirm Password:", nullptr));
        change_password_profile->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        forget_password_profile->setText(QCoreApplication::translate("MainWindow", "Forget password", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "UI Theme:", nullptr));
        profile_light_mod->setItemText(0, QCoreApplication::translate("MainWindow", "Light", nullptr));
        profile_light_mod->setItemText(1, QCoreApplication::translate("MainWindow", "Dark", nullptr));

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
