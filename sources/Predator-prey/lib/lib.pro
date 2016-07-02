#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T16:40:40
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib
TEMPLATE = lib
CONFIG += staticlib c++11

QMAKE_LFLAGS_CONSOLE += -static

SOURCES += \
    predator.cpp \
    prey.cpp \
    settings.cpp \
    field.cpp \
    animal.cpp \
    units.cpp \
    coordinates.cpp \
    model.cpp \
    grass.cpp \
    movement.cpp \
    sense.cpp \
    brain.cpp \
    preysbrain.cpp \
    predatorsbrain.cpp

HEADERS += \
    settings.h \
    predator.h \
    prey.h \
    modelapi.h \
    units.h \
    field.h \
    animal.h \
    coordinates.h \
    model.h \
    badinput.h \
    badfield.h \
    badboundary.h \
    badnum.h \
    grass.h \
    movement.h \
    sense.h \
    brain.h \
    unit.h \
    preysbrain.h \
    predatorsbrain.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
