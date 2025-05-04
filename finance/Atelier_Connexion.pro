#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    editingsalarydialog.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    transaction.cpp

HEADERS += \
    editingsalarydialog.h \
    mainwindow.h \
    connection.h \
    transaction.h

FORMS += \
    ../Atelier_Connexion/editingsalarydialog.ui \
    editingsalarydialog.ui \
    editingsalarydialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
