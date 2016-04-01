TEMPLATE = subdirs

consoleApp.depends = lib
tests.depends = lib

SUBDIRS += \
    consoleApp \
    lib \
    tests
