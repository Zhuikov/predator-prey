#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"

class ConsoleDialog
{
    Settings* sett;

    void settingsPresentation();
    void changeFieldSize();
    void changeDayWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();

    void setNewDayWithoutMeal(int);
    void setNewFieldBoundary(Settings* sett, int, int);
    void setNumOfPreys(Settings* sett, int);
    void setNumOfPredators(Settings * sett, int);

public:
    ConsoleDialog(Settings* settings);
    int menuPresentation();

};

#endif // CONSOLEDIALOG_H
