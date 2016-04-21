#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "modelpp.h"
#include "consoledrawer.h"
#include <map>
#include <string>

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
    int settingsPresentation();

    void setNewDayWithoutMeal(const int);
    void setNewFieldBoundary(const int, const int);
    void setNumOfPreys(const int);
    void setNumOfPredators(const int);

    const std::map< std::string, int > consoleCommands =
    {
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"0", 0},
    };

public:
    ConsoleDialog(Settings *sett);
    int mainMenuPresentation();
    void settingsMenuPresentation();

};

#endif // CONSOLEDIALOG_H
