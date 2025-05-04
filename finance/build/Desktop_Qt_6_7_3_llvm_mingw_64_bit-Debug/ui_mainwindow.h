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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tab_repairs;
    QWidget *RE;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *view_more;
    QListWidget *RE_list_widget;
    QWidget *SM;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QListWidget *listWidget;
    QPushButton *edit_salary;
    QPushButton *delete_sm_btn;
    QListWidget *listWidget_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QWidget *stat;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(866, 588);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #252525;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #333;\n"
"    color: white;\n"
"    border: 2px solid #AA2020;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #444;\n"
"}\n"
"\n"
"QLineEdit, QComboBox, QDateEdit {\n"
"    background-color: #333;\n"
"    color: white;\n"
"    border: 2px solid #AA2020;\n"
"    border-radius: 3px;\n"
"    padding: 3px;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #222;\n"
"    color: white;\n"
"    border: 2px solid #AA2020;\n"
"    gridline-color: #AA2020;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #AA2020;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #222;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        tab_repairs = new QTabWidget(centralwidget);
        tab_repairs->setObjectName("tab_repairs");
        tab_repairs->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"	background-color: rgb(37, 37, 37);\n"
"    border: 2px solid #FF5C5C;\n"
"    background-color: #252525;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #404040;\n"
"    color: white;\n"
"    border: 2px solid #FF5C5C;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #FF5C5C;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #D32F2F;\n"
"    font-weight: bold;\n"
"}\n"
""));
        RE = new QWidget();
        RE->setObjectName("RE");
        RE->setStyleSheet(QString::fromUtf8("#RE::pane {\n"
"	border-color: rgb(246, 211, 45);\n"
"    border: 2px solid #FF5C5C;\n"
"    background-color: #252525;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #404040;\n"
"    color: white;\n"
"    border: 2px solid #FF5C5C;\n"
"    padding: 5px;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #FF5C5C;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #D32F2F;\n"
"    font-weight: bold;\n"
"}\n"
""));
        gridLayout = new QGridLayout(RE);
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(RE);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(RE);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        comboBox = new QComboBox(RE);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        view_more = new QPushButton(RE);
        view_more->setObjectName("view_more");

        gridLayout->addWidget(view_more, 2, 1, 1, 1);

        RE_list_widget = new QListWidget(RE);
        new QListWidgetItem(RE_list_widget);
        RE_list_widget->setObjectName("RE_list_widget");

        gridLayout->addWidget(RE_list_widget, 1, 0, 1, 3);

        tab_repairs->addTab(RE, QString());
        SM = new QWidget();
        SM->setObjectName("SM");
        gridLayout_3 = new QGridLayout(SM);
        gridLayout_3->setObjectName("gridLayout_3");
        comboBox_3 = new QComboBox(SM);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        gridLayout_3->addWidget(comboBox_3, 0, 3, 1, 1);

        pushButton_5 = new QPushButton(SM);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout_3->addWidget(pushButton_5, 0, 2, 1, 1);

        lineEdit_2 = new QLineEdit(SM);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_3->addWidget(lineEdit_2, 0, 0, 1, 2);

        listWidget = new QListWidget(SM);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");

        gridLayout_3->addWidget(listWidget, 1, 0, 1, 4);

        edit_salary = new QPushButton(SM);
        edit_salary->setObjectName("edit_salary");

        gridLayout_3->addWidget(edit_salary, 2, 0, 1, 1);

        delete_sm_btn = new QPushButton(SM);
        delete_sm_btn->setObjectName("delete_sm_btn");

        gridLayout_3->addWidget(delete_sm_btn, 2, 1, 1, 1);

        listWidget_4 = new QListWidget(SM);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        new QListWidgetItem(listWidget_4);
        listWidget_4->setObjectName("listWidget_4");

        gridLayout_3->addWidget(listWidget_4, 1, 4, 1, 2);

        pushButton_8 = new QPushButton(SM);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout_3->addWidget(pushButton_8, 2, 5, 1, 1);

        pushButton_7 = new QPushButton(SM);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout_3->addWidget(pushButton_7, 2, 4, 1, 1);

        tab_repairs->addTab(SM, QString());
        stat = new QWidget();
        stat->setObjectName("stat");
        lineEdit_3 = new QLineEdit(stat);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 130, 451, 29));
        lineEdit_4 = new QLineEdit(stat);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(140, 100, 371, 29));
        lineEdit_5 = new QLineEdit(stat);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(140, 160, 150, 29));
        label = new QLabel(stat);
        label->setObjectName("label");
        label->setGeometry(QRect(51, 101, 50, 17));
        label_2 = new QLabel(stat);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(51, 136, 45, 17));
        label_3 = new QLabel(stat);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(51, 171, 49, 17));
        layoutWidget = new QWidget(stat);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(180, 370, 391, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName("pushButton_10");

        horizontalLayout->addWidget(pushButton_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        horizontalLayout->addLayout(horizontalLayout_2);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");

        horizontalLayout->addWidget(pushButton_9);

        tab_repairs->addTab(stat, QString());

        gridLayout_2->addWidget(tab_repairs, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 866, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tab_repairs->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "by date", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "by type", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "...", nullptr));

        view_more->setText(QCoreApplication::translate("MainWindow", "View Details", nullptr));

        const bool __sortingEnabled = RE_list_widget->isSortingEnabled();
        RE_list_widget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = RE_list_widget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", " id_service - date - cost ", nullptr));
        RE_list_widget->setSortingEnabled(__sortingEnabled);

        tab_repairs->setTabText(tab_repairs->indexOf(RE), QCoreApplication::translate("MainWindow", "Repairs - Expenses", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "by mat", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "by full_name", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "by post", nullptr));

        pushButton_5->setText(QCoreApplication::translate("MainWindow", "search", nullptr));

        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "employee_mat  -  full_name - post - basic_salary - bonus_or_panelty - +hours  - date", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled1);

        edit_salary->setText(QCoreApplication::translate("MainWindow", "edit", nullptr));
        delete_sm_btn->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));

        const bool __sortingEnabled2 = listWidget_4->isSortingEnabled();
        listWidget_4->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget_4->item(0);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "fich de pay ", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_4->item(1);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "matricule :", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_4->item(2);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "full_name :", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_4->item(3);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "post :", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_4->item(4);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "date :", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_4->item(5);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "basic salary :", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_4->item(6);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "experience :", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_4->item(7);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("MainWindow", "+hours :", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_4->item(8);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("MainWindow", "penalty :", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_4->item(9);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("MainWindow", "total salaire :", nullptr));
        listWidget_4->setSortingEnabled(__sortingEnabled2);

        pushButton_8->setText(QCoreApplication::translate("MainWindow", "print", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "display formul", nullptr));
        tab_repairs->setTabText(tab_repairs->indexOf(SM), QCoreApplication::translate("MainWindow", "Salary Management", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mall X :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mall Y:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mall Z :", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "show profits", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "show expenses", nullptr));
        tab_repairs->setTabText(tab_repairs->indexOf(stat), QCoreApplication::translate("MainWindow", "stat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
