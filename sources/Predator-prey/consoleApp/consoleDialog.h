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
    Settings *sett;

    void changeFieldSize();
    void changeDayWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();

    void setNewDayWithoutMeal(const int);
    void setNewFieldBoundary(const int, const int);
    void setNumOfPreys(const int);
    void setNumOfPredators(const int);

public:
    ConsoleDialog(Settings *sett);
    int menuPresentation();
    void settingsPresentation();

};

#endif // CONSOLEDIALOG_H
