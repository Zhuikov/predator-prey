#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "model.h"
#include "consoledrawer.h"
#include <map>
#include <string>

class ConsoleDialog
{
    std::string input_number;
    Settings *settings;

    void changeFieldSize();
    void changeMovesWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();
    int settingsPresentation();

    int readInt();

    void setNewMovesWithoutMeal(const int);
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
    ConsoleDialog(Settings *settings);
    int mainMenuPresentation();
    void settingsMenuPresentation();

};

#endif // CONSOLEDIALOG_H
