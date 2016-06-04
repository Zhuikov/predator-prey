#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T23:32:49
#
#-------------------------------------------------

QT       += testlib
QMAKE_CXXFLAGS += -std=c++11

QT       -= gui

TARGET = tst_modeltest

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_modeltest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -llib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -llib
else:unix: LIBS += -L$$OUT_PWD/../lib/ -llib

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/liblib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/liblib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/liblib.a



