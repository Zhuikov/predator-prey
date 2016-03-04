#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T16:40:40
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    predator.cpp \
    prey.cpp

HEADERS += \
    predator.h \
    point.h \
    prey.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
