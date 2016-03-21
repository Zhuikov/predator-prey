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
    prey.cpp \
    settings.cpp \
    modelapi.cpp \
    modelpp.cpp

HEADERS += \
    predator.h \
    point.h \
    prey.h \
    settings.h \
    constants.h \
    exceptions.h \
    modelapi.h \
    modelpp.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
