TEMPLATE = subdirs

app.depends = lib
tests.depends = lib

SUBDIRS += \
    app \
    lib \
    tests
