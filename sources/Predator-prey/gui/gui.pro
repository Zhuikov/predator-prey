#-------------------------------------------------
#
# Project created by QtCreator 2016-04-30T22:26:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    mainmenu.cpp

HEADERS  += \
    mainmenu.h

FORMS    += mainwindow.ui
