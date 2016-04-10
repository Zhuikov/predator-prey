#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "modelpp.h"
#include "consoledrawer.h"

class ConsoleDialog
{
    int new_length;
    int new_height;
    int new_number;
    int new_time;

    void changeFieldSize();
    void changeDayWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();

    void setNewDayWithoutMeal(Settings *sett, const int);
    void setNewFieldBoundary(Settings *sett, const int, const int);
    void setNumOfPreys(Settings *sett, const int);
    void setNumOfPredators(Settings *sett, const int);

public:
    ConsoleDialog();
    int menuPresentation();
    void settingsPresentation(Settings *sett);

};

#endif // CONSOLEDIALOG_H
