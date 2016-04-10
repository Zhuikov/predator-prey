#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include "consoleDialog.h"
#include "consoledrawer.h"

class ConsoleApp
{
    ConsoleDialog *CD;
    ConsoleDrawer *drawer;
    Settings *sett;
    ModelPP *model;

public:
    ConsoleApp();
    void createConsole();

    ~ConsoleApp();
};

#endif // CONSOLEAPP_H
