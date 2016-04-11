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
    modelpp.cpp \
    field.cpp \
    animal.cpp \
    units.cpp \
    coordinates.cpp

HEADERS += \
    settings.h \
    predator.h \
    prey.h \
    constants.h \
    exceptions.h \
    modelapi.h \
    modelpp.h \
    units.h \
    field.h \
    animal.h \
    coordinates.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
