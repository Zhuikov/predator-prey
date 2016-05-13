#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T22:32:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIApp
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    mainmenu.cpp \
    exitwindow.cpp \
    settingswindow.cpp \
    modelgui.cpp

HEADERS  += \
    mainmenu.h \
    exitwindow.h \
    settingswindow.h \
    modelgui.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc

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
