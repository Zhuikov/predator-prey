TEMPLATE = subdirs
QMAKE_CXXFLAGS += -std=c++11

consoleApp.depends = lib
tests.depends = lib

SUBDIRS += \
    consoleApp \
    lib \
    tests \
