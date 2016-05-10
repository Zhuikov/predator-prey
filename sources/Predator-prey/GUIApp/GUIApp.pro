#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T22:32:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIApp
TEMPLATE = app


SOURCES += main.cpp \
    mainmenu.cpp \
    exitwindow.cpp

HEADERS  += \
    mainmenu.h \
    exitwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc
