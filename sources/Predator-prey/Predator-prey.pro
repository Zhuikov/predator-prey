TEMPLATE = subdirs
QMAKE_CXXFLAGS += -std=c++11

consoleApp.depends = lib
tests.depends = lib
GUIApp.depends = lib
CLI.depends = lib

SUBDIRS += \
    consoleApp \
    lib \
    tests \
    GUIApp \
    CLI
