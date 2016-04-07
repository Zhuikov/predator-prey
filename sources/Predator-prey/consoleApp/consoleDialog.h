#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "modelpp.h"

class ConsoleDialog
{
    Settings *sett;
    ModelPP *model;

    void settingsPresentation();
    void changeFieldSize();
    void changeDayWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();

    void setNewDayWithoutMeal(int);
    void setNewFieldBoundary(int, int);
    void setNumOfPreys(int);
    void setNumOfPredators(int);

public:
    ConsoleDialog(ModelPP *modelPP, Settings* settings);
    void menuPresentation();

};

#endif // CONSOLEDIALOG_H
