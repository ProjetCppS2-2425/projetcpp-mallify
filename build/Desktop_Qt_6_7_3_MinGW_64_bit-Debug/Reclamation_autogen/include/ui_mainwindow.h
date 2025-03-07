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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QFrame *frame_4;
    QLabel *labelStatus;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_17;
    QTabWidget *tabWidget;
    QWidget *Add;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditPhone;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *lineEditEmail;
    QLabel *label_4;
    QTextEdit *textEditDescription;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *btnSubmit;
    QLabel *label_5;
    QComboBox *comboBoxCategory;
    QComboBox *comboBoxCategory_2;
    QLineEdit *lineEditName;
    QLabel *label;
    QWidget *Remove;
    QGridLayout *gridLayout_7;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QLabel *label_31;
    QLabel *label_29;
    QPushButton *pushButton_6;
    QLabel *label_30;
    QComboBox *comboBoxCategory_8;
    QTableWidget *tableWidget_2;
    QComboBox *comboBoxCategory_7;
    QPushButton *btnSubmit_2;
    QLabel *label_22;
    QLineEdit *lineEdit_2;
    QPushButton *btnSubmit_4;
    QWidget *Edit;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_7;
    QTableWidget *tableWidget_3;
    QLabel *label_33;
    QLabel *label_34;
    QComboBox *comboBoxCategory_10;
    QLabel *label_32;
    QLineEdit *lineEdit_3;
    QLabel *label_35;
    QComboBox *comboBoxCategory_11;
    QPushButton *btnSubmit_5;
    QWidget *Display;
    QGridLayout *gridLayout_3;
    QComboBox *comboBoxCategory_9;
    QLabel *label_25;
    QLabel *label_27;
    QComboBox *comboBoxCategory_5;
    QPushButton *btnSubmit_3;
    QLabel *label_26;
    QComboBox *comboBoxCategory_6;
    QTableWidget *tableWidget;
    QLabel *label_28;
    QWidget *PDF_Status;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1121, 820);
        QPalette palette;
        QBrush brush(QColor(255, 92, 92, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        MainWindow->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-10, 0, 191, 1081));
        QPalette palette1;
        QBrush brush2(QColor(255, 104, 104, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        frame_2->setPalette(palette1);
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #FF6868;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 111, 61));
        QFont font1;
        font1.setPointSize(6);
        label_2->setFont(font1);
        label_2->setPixmap(QPixmap(QString::fromUtf8("Group saadfa19.svg")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 400, 181, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_3->setPalette(palette2);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 330, 181, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_12->setPalette(palette3);
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 260, 181, 61));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_13->setPalette(palette4);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_13->setTextFormat(Qt::TextFormat::PlainText);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_14 = new QLabel(frame_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 190, 181, 61));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_14->setPalette(palette5);
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 120, 181, 61));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_15->setPalette(palette6);
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 470, 181, 61));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_16->setPalette(palette7);
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    color: white; /* Ensures text is visible on a dark background */\n"
"    text-align: center;\n"
"}\n"
"\n"
"QLabel {\n"
"    padding: 5px 10px;\n"
"    transition: background-color 0.3s ease, color 0.3s ease;\n"
"}\n"
"\n"
"QLabel:hover {\n"
"     background-color: rgba(0, 0, 0, 0.96); \n"
"    cursor: pointer;\n"
"}\n"
""));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(180, 0, 981, 1181));
        frame_4->setAutoFillBackground(true);
        frame_4->setStyleSheet(QString::fromUtf8("backgroud-color:rgb(105, 255, 218)rgb(255, 215, 12);"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        labelStatus = new QLabel(frame_4);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(320, 460, 161, 31));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(720, 10, 91, 81));
        label_11->setAutoFillBackground(false);
        label_11->setPixmap(QPixmap(QString::fromUtf8("Capture d'\303\251cran 2024-11-11 135957.png")));
        label_11->setScaledContents(true);
        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(720, 90, 161, 41));
        label_17 = new QLabel(frame_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 20, 261, 81));
        label_17->setMaximumSize(QSize(261, 81));
        label_17->setBaseSize(QSize(0, 1000));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(14);
        font3.setWeight(QFont::Black);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        label_17->setFont(font3);
        tabWidget = new QTabWidget(frame_4);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 160, 801, 511));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);"));
        Add = new QWidget();
        Add->setObjectName("Add");
        gridLayout = new QGridLayout(Add);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(Add);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        lineEditPhone = new QLineEdit(frame);
        lineEditPhone->setObjectName("lineEditPhone");
        QPalette palette8;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush5(QColor(255, 187, 100, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        QBrush brush7(QColor(128, 128, 128, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        QBrush brush8(QColor(255, 255, 255, 12));
        brush8.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        QBrush brush9(QColor(128, 128, 128, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        lineEditPhone->setPalette(palette8);
        lineEditPhone->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_2->addWidget(lineEditPhone, 8, 0, 1, 2);

        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        QFont font4;
        font4.setPointSize(12);
        label_8->setFont(font4);

        gridLayout_2->addWidget(label_8, 9, 0, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        QFont font5;
        font5.setPointSize(11);
        label_9->setFont(font5);

        gridLayout_2->addWidget(label_9, 6, 2, 2, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setFont(font5);

        gridLayout_2->addWidget(label_7, 2, 2, 2, 1);

        lineEditEmail = new QLineEdit(frame);
        lineEditEmail->setObjectName("lineEditEmail");
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        lineEditEmail->setPalette(palette9);
        lineEditEmail->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_2->addWidget(lineEditEmail, 5, 0, 2, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setFont(font5);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        textEditDescription = new QTextEdit(frame);
        textEditDescription->setObjectName("textEditDescription");
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        textEditDescription->setPalette(palette10);
        textEditDescription->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QTextEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_2->addWidget(textEditDescription, 10, 0, 1, 4);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setFont(font5);

        gridLayout_2->addWidget(label_6, 7, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #FF6868;"));

        gridLayout_2->addWidget(pushButton_2, 11, 3, 1, 1);

        btnSubmit = new QPushButton(frame);
        btnSubmit->setObjectName("btnSubmit");
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        btnSubmit->setPalette(palette11);
        btnSubmit->setAutoFillBackground(false);
        btnSubmit->setStyleSheet(QString::fromUtf8("background-color: #FF6868; \n"
"color: #FFFFFF;\n"
""));

        gridLayout_2->addWidget(btnSubmit, 11, 2, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setFont(font5);

        gridLayout_2->addWidget(label_5, 3, 0, 2, 1);

        comboBoxCategory = new QComboBox(frame);
        comboBoxCategory->addItem(QString());
        comboBoxCategory->addItem(QString());
        comboBoxCategory->addItem(QString());
        comboBoxCategory->addItem(QString());
        comboBoxCategory->setObjectName("comboBoxCategory");
        comboBoxCategory->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_2->addWidget(comboBoxCategory, 4, 2, 2, 2);

        comboBoxCategory_2 = new QComboBox(frame);
        comboBoxCategory_2->addItem(QString());
        comboBoxCategory_2->addItem(QString());
        comboBoxCategory_2->addItem(QString());
        comboBoxCategory_2->addItem(QString());
        comboBoxCategory_2->setObjectName("comboBoxCategory_2");
        comboBoxCategory_2->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_2->addWidget(comboBoxCategory_2, 8, 2, 1, 2);

        lineEditName = new QLineEdit(frame);
        lineEditName->setObjectName("lineEditName");
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Active, QPalette::HighlightedText, brush4);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        lineEditName->setPalette(palette12);
        lineEditName->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_2->addWidget(lineEditName, 2, 0, 1, 2);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMaximumSize(QSize(261, 81));
        label->setBaseSize(QSize(0, 1000));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setUnderline(false);
        label->setFont(font6);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        tabWidget->addTab(Add, QString());
        Remove = new QWidget();
        Remove->setObjectName("Remove");
        gridLayout_7 = new QGridLayout(Remove);
        gridLayout_7->setObjectName("gridLayout_7");
        frame_3 = new QFrame(Remove);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setObjectName("gridLayout_6");
        label_31 = new QLabel(frame_3);
        label_31->setObjectName("label_31");
        label_31->setFont(font5);

        gridLayout_6->addWidget(label_31, 2, 4, 2, 1);

        label_29 = new QLabel(frame_3);
        label_29->setObjectName("label_29");
        label_29->setFont(font5);

        gridLayout_6->addWidget(label_29, 2, 0, 2, 1);

        pushButton_6 = new QPushButton(frame_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: #FF6868;"));

        gridLayout_6->addWidget(pushButton_6, 6, 5, 1, 1);

        label_30 = new QLabel(frame_3);
        label_30->setObjectName("label_30");
        label_30->setFont(font5);

        gridLayout_6->addWidget(label_30, 2, 2, 2, 1);

        comboBoxCategory_8 = new QComboBox(frame_3);
        comboBoxCategory_8->addItem(QString());
        comboBoxCategory_8->addItem(QString());
        comboBoxCategory_8->addItem(QString());
        comboBoxCategory_8->addItem(QString());
        comboBoxCategory_8->setObjectName("comboBoxCategory_8");
        comboBoxCategory_8->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_6->addWidget(comboBoxCategory_8, 4, 2, 1, 2);

        tableWidget_2 = new QTableWidget(frame_3);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setAlternatingRowColors(false);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_2->setShowGrid(true);
        tableWidget_2->setCornerButtonEnabled(true);
        tableWidget_2->setRowCount(0);
        tableWidget_2->setColumnCount(7);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(108);

        gridLayout_6->addWidget(tableWidget_2, 5, 0, 1, 6);

        comboBoxCategory_7 = new QComboBox(frame_3);
        comboBoxCategory_7->addItem(QString());
        comboBoxCategory_7->addItem(QString());
        comboBoxCategory_7->addItem(QString());
        comboBoxCategory_7->setObjectName("comboBoxCategory_7");
        comboBoxCategory_7->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_6->addWidget(comboBoxCategory_7, 4, 4, 1, 1);

        btnSubmit_2 = new QPushButton(frame_3);
        btnSubmit_2->setObjectName("btnSubmit_2");
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush10(QColor(68, 68, 68, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        btnSubmit_2->setPalette(palette13);
        btnSubmit_2->setAutoFillBackground(false);
        btnSubmit_2->setStyleSheet(QString::fromUtf8("\n"
"color: #FFFFFF;\n"
""));

        gridLayout_6->addWidget(btnSubmit_2, 6, 0, 1, 1);

        label_22 = new QLabel(frame_3);
        label_22->setObjectName("label_22");
        label_22->setMaximumSize(QSize(261, 81));
        label_22->setBaseSize(QSize(0, 1000));
        label_22->setFont(font6);

        gridLayout_6->addWidget(label_22, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_6->addWidget(lineEdit_2, 4, 0, 1, 1);

        btnSubmit_4 = new QPushButton(frame_3);
        btnSubmit_4->setObjectName("btnSubmit_4");
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        btnSubmit_4->setPalette(palette14);
        btnSubmit_4->setAutoFillBackground(false);
        btnSubmit_4->setStyleSheet(QString::fromUtf8("background-color: #FF6868; \n"
"color: #FFFFFF;\n"
""));

        gridLayout_6->addWidget(btnSubmit_4, 3, 5, 2, 1);


        gridLayout_7->addWidget(frame_3, 0, 0, 1, 1);

        tabWidget->addTab(Remove, QString());
        Edit = new QWidget();
        Edit->setObjectName("Edit");
        gridLayout_4 = new QGridLayout(Edit);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_7 = new QPushButton(Edit);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: #FF6868;"));

        gridLayout_4->addWidget(pushButton_7, 7, 4, 1, 1);

        tableWidget_3 = new QTableWidget(Edit);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setAlternatingRowColors(false);
        tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_3->setShowGrid(true);
        tableWidget_3->setCornerButtonEnabled(true);
        tableWidget_3->setRowCount(0);
        tableWidget_3->setColumnCount(7);
        tableWidget_3->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(108);

        gridLayout_4->addWidget(tableWidget_3, 6, 0, 1, 5);

        label_33 = new QLabel(Edit);
        label_33->setObjectName("label_33");
        label_33->setFont(font5);

        gridLayout_4->addWidget(label_33, 3, 0, 1, 1);

        label_34 = new QLabel(Edit);
        label_34->setObjectName("label_34");
        label_34->setFont(font5);

        gridLayout_4->addWidget(label_34, 3, 2, 1, 1);

        comboBoxCategory_10 = new QComboBox(Edit);
        comboBoxCategory_10->addItem(QString());
        comboBoxCategory_10->addItem(QString());
        comboBoxCategory_10->addItem(QString());
        comboBoxCategory_10->addItem(QString());
        comboBoxCategory_10->setObjectName("comboBoxCategory_10");
        comboBoxCategory_10->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_4->addWidget(comboBoxCategory_10, 5, 2, 1, 1);

        label_32 = new QLabel(Edit);
        label_32->setObjectName("label_32");
        label_32->setFont(font5);

        gridLayout_4->addWidget(label_32, 3, 3, 1, 1);

        lineEdit_3 = new QLineEdit(Edit);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FFBB64; /* Keep the background color as #FFBB64 */\n"
"    border-radius: 5px; /* Rounded corners for the widget */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    border: 2px solid Black;\n"
"    border-radius: 5px;\n"
"    background-color: #FFBB64; /* Light transparent background */\n"
"    color: Black; /* Text color inside the input */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #0000; /* Hover background color */\n"
"    cursor: pointer; /* Changes cursor on hover */\n"
"}\n"
"\n"
"QLineEdit:focus { /* Focus border color */\n"
"    outline: none; /* Removes the outline when focused */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: rgba(255, 255, 255, 0.05); /* Disabled state styling */\n"
"    color: gray; /* Disabled text color */\n"
"    border: 2px solid gray; /* Disabled border */\n"
"}\n"
""));

        gridLayout_4->addWidget(lineEdit_3, 5, 0, 1, 1);

        label_35 = new QLabel(Edit);
        label_35->setObjectName("label_35");
        label_35->setMaximumSize(QSize(261, 81));
        label_35->setBaseSize(QSize(0, 1000));
        label_35->setFont(font6);

        gridLayout_4->addWidget(label_35, 2, 0, 1, 1);

        comboBoxCategory_11 = new QComboBox(Edit);
        comboBoxCategory_11->addItem(QString());
        comboBoxCategory_11->addItem(QString());
        comboBoxCategory_11->addItem(QString());
        comboBoxCategory_11->setObjectName("comboBoxCategory_11");
        comboBoxCategory_11->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_4->addWidget(comboBoxCategory_11, 5, 3, 1, 1);

        btnSubmit_5 = new QPushButton(Edit);
        btnSubmit_5->setObjectName("btnSubmit_5");
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        btnSubmit_5->setPalette(palette15);
        btnSubmit_5->setAutoFillBackground(false);
        btnSubmit_5->setStyleSheet(QString::fromUtf8("background-color: #FF6868; \n"
"color: #FFFFFF;\n"
""));

        gridLayout_4->addWidget(btnSubmit_5, 5, 4, 1, 1);

        tabWidget->addTab(Edit, QString());
        Display = new QWidget();
        Display->setObjectName("Display");
        gridLayout_3 = new QGridLayout(Display);
        gridLayout_3->setObjectName("gridLayout_3");
        comboBoxCategory_9 = new QComboBox(Display);
        comboBoxCategory_9->addItem(QString());
        comboBoxCategory_9->addItem(QString());
        comboBoxCategory_9->addItem(QString());
        comboBoxCategory_9->addItem(QString());
        comboBoxCategory_9->setObjectName("comboBoxCategory_9");
        comboBoxCategory_9->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_3->addWidget(comboBoxCategory_9, 3, 0, 1, 1);

        label_25 = new QLabel(Display);
        label_25->setObjectName("label_25");
        label_25->setFont(font5);

        gridLayout_3->addWidget(label_25, 2, 1, 1, 1);

        label_27 = new QLabel(Display);
        label_27->setObjectName("label_27");
        label_27->setFont(font5);

        gridLayout_3->addWidget(label_27, 2, 2, 1, 1);

        comboBoxCategory_5 = new QComboBox(Display);
        comboBoxCategory_5->addItem(QString());
        comboBoxCategory_5->addItem(QString());
        comboBoxCategory_5->addItem(QString());
        comboBoxCategory_5->addItem(QString());
        comboBoxCategory_5->setObjectName("comboBoxCategory_5");
        comboBoxCategory_5->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_3->addWidget(comboBoxCategory_5, 3, 1, 1, 1);

        btnSubmit_3 = new QPushButton(Display);
        btnSubmit_3->setObjectName("btnSubmit_3");
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        btnSubmit_3->setPalette(palette16);
        btnSubmit_3->setAutoFillBackground(false);
        btnSubmit_3->setStyleSheet(QString::fromUtf8("background-color: #FF6868; \n"
"color: #FFFFFF;\n"
""));

        gridLayout_3->addWidget(btnSubmit_3, 3, 3, 1, 1);

        label_26 = new QLabel(Display);
        label_26->setObjectName("label_26");
        label_26->setFont(font5);

        gridLayout_3->addWidget(label_26, 2, 0, 1, 1);

        comboBoxCategory_6 = new QComboBox(Display);
        comboBoxCategory_6->addItem(QString());
        comboBoxCategory_6->addItem(QString());
        comboBoxCategory_6->addItem(QString());
        comboBoxCategory_6->setObjectName("comboBoxCategory_6");
        comboBoxCategory_6->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));

        gridLayout_3->addWidget(comboBoxCategory_6, 3, 2, 1, 1);

        tableWidget = new QTableWidget(Display);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setShowGrid(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(7);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(108);

        gridLayout_3->addWidget(tableWidget, 4, 0, 1, 4);

        label_28 = new QLabel(Display);
        label_28->setObjectName("label_28");
        label_28->setMaximumSize(QSize(261, 81));
        label_28->setBaseSize(QSize(0, 1000));
        label_28->setFont(font6);

        gridLayout_3->addWidget(label_28, 1, 0, 1, 1);

        tabWidget->addTab(Display, QString());
        PDF_Status = new QWidget();
        PDF_Status->setObjectName("PDF_Status");
        gridLayout_5 = new QGridLayout(PDF_Status);
        gridLayout_5->setObjectName("gridLayout_5");
        pushButton = new QPushButton(PDF_Status);
        pushButton->setObjectName("pushButton");

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);

        tabWidget->addTab(PDF_Status, QString());
        MainWindow->setCentralWidget(centralwidget);
        frame_4->raise();
        frame_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1121, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", ".......", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", ".....", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Complaint", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Service", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Employers", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", ".........", nullptr));
        labelStatus->setText(QString());
        label_11->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Welcome Mehdi", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "| Complaint Manager", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Full report", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Priority:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Phone:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        btnSubmit->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        comboBoxCategory->setItemText(0, QCoreApplication::translate("MainWindow", "Emergency", nullptr));
        comboBoxCategory->setItemText(1, QCoreApplication::translate("MainWindow", "water leak", nullptr));
        comboBoxCategory->setItemText(2, QCoreApplication::translate("MainWindow", "delay exprired", nullptr));
        comboBoxCategory->setItemText(3, QCoreApplication::translate("MainWindow", "Broken Produuct", nullptr));

        comboBoxCategory_2->setItemText(0, QCoreApplication::translate("MainWindow", "SO IMportant", nullptr));
        comboBoxCategory_2->setItemText(1, QCoreApplication::translate("MainWindow", "Important", nullptr));
        comboBoxCategory_2->setItemText(2, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBoxCategory_2->setItemText(3, QCoreApplication::translate("MainWindow", "Nothing to worry about", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Add a Complaint:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Add), QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "User Id:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        comboBoxCategory_8->setItemText(0, QCoreApplication::translate("MainWindow", "Emergency", nullptr));
        comboBoxCategory_8->setItemText(1, QCoreApplication::translate("MainWindow", "water leak", nullptr));
        comboBoxCategory_8->setItemText(2, QCoreApplication::translate("MainWindow", "delay exprired", nullptr));
        comboBoxCategory_8->setItemText(3, QCoreApplication::translate("MainWindow", "Broken Produuct", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        comboBoxCategory_7->setItemText(0, QCoreApplication::translate("MainWindow", "Done", nullptr));
        comboBoxCategory_7->setItemText(1, QCoreApplication::translate("MainWindow", "on hold\n"
"", nullptr));
        comboBoxCategory_7->setItemText(2, QCoreApplication::translate("MainWindow", "Canceled", nullptr));

        btnSubmit_2->setText(QCoreApplication::translate("MainWindow", "Select All", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Remove a Complaint:", nullptr));
        lineEdit_2->setText(QString());
        btnSubmit_4->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Remove), QCoreApplication::translate("MainWindow", "Remove", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Modify Selected", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "User Id:", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        comboBoxCategory_10->setItemText(0, QCoreApplication::translate("MainWindow", "Emergency", nullptr));
        comboBoxCategory_10->setItemText(1, QCoreApplication::translate("MainWindow", "water leak", nullptr));
        comboBoxCategory_10->setItemText(2, QCoreApplication::translate("MainWindow", "delay exprired", nullptr));
        comboBoxCategory_10->setItemText(3, QCoreApplication::translate("MainWindow", "Broken Produuct", nullptr));

        label_32->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        lineEdit_3->setText(QString());
        label_35->setText(QCoreApplication::translate("MainWindow", "Complain List", nullptr));
        comboBoxCategory_11->setItemText(0, QCoreApplication::translate("MainWindow", "Done", nullptr));
        comboBoxCategory_11->setItemText(1, QCoreApplication::translate("MainWindow", "on hold\n"
"", nullptr));
        comboBoxCategory_11->setItemText(2, QCoreApplication::translate("MainWindow", "Canceled", nullptr));

        btnSubmit_5->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Edit), QCoreApplication::translate("MainWindow", "Edit", nullptr));
        comboBoxCategory_9->setItemText(0, QCoreApplication::translate("MainWindow", "Today", nullptr));
        comboBoxCategory_9->setItemText(1, QCoreApplication::translate("MainWindow", "This Week", nullptr));
        comboBoxCategory_9->setItemText(2, QCoreApplication::translate("MainWindow", "This Month", nullptr));
        comboBoxCategory_9->setItemText(3, QCoreApplication::translate("MainWindow", "This Year", nullptr));

        label_25->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        comboBoxCategory_5->setItemText(0, QCoreApplication::translate("MainWindow", "Emergency", nullptr));
        comboBoxCategory_5->setItemText(1, QCoreApplication::translate("MainWindow", "water leak", nullptr));
        comboBoxCategory_5->setItemText(2, QCoreApplication::translate("MainWindow", "delay exprired", nullptr));
        comboBoxCategory_5->setItemText(3, QCoreApplication::translate("MainWindow", "Broken Produuct", nullptr));

        btnSubmit_3->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        comboBoxCategory_6->setItemText(0, QCoreApplication::translate("MainWindow", "Done", nullptr));
        comboBoxCategory_6->setItemText(1, QCoreApplication::translate("MainWindow", "on hold\n"
"", nullptr));
        comboBoxCategory_6->setItemText(2, QCoreApplication::translate("MainWindow", "Canceled", nullptr));

        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Complain List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Display), QCoreApplication::translate("MainWindow", "Display", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PDF_Status), QCoreApplication::translate("MainWindow", "PDF & Stats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
