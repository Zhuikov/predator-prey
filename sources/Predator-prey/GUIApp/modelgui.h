#ifndef MODELGUI_H
#define MODELGUI_H

#include "model.h"
#include "mainmenu.h"
#include "settings.h"
#include <QApplication>

class ModelGUI
{
    Settings* settings;

    int argc;
    char **argv;

public:
    ModelGUI(int, char *[]);
    int startGUI();

    ~ModelGUI();
};

#endif // MODELGUI_H
