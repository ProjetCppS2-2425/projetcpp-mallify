QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MapDialog.cpp \
    SpeechRecognizer.cpp \
    VoiceReceiver.cpp \
    VoiceTransmitter.cpp \
    chartwindow.cpp \
    connection.cpp \
    coordinatehandler.cpp \
    main.cpp \
    mainwindow.cpp \
    reclamation.cpp

HEADERS += \
    MapDialog.h \
    SpeechRecognizer.h \
    VoiceReceiver.h \
    VoiceTransmitter.h \
    chartwindow.h \
    connection.h \
    coordinatehandler.h \
    mainwindow.h \
    reclamation.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += charts
QT += core gui widgets
QT += multimedia
QT += multimedia network

QT += multimedia multimediawidgets

QT += core multimedia
CONFIG += console c++11


QT += charts
QT += quick quickcontrols2 location positioning network
QT += quickwidgets quick network


QT       += core gui widgets quickwidgets positioning location

DISTFILES += \
    MapView.qml

QT       += core gui widgets quick quickwidgets positioning location network qml
RESOURCES += qml.qrc \
    qml.qrc
