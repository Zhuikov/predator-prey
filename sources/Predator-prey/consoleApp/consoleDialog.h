#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"

class ConsoleDialog
{
    void changeField();
    void changeDayWithoutMeal();
    Settings* sett;

public:
    ConsoleDialog(Settings* settings);
    int menuPresentation();
    void settingsPresentation();
    void setNewDayWithoutMeal(int);
    void setNewFieldBoundary(Settings* sett, int, int);
};

#endif // CONSOLEDIALOG_H
