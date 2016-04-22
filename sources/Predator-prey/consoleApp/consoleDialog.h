#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "modelpp.h"
#include "consoledrawer.h"
#include <map>
#include <string>

//todo придерживайтесь одного стиля именования файлов

class ConsoleDialog
{
    int new_length;
    int new_height;
    int new_number;
    int new_time;
    std::string input_number;
    Settings *sett;

    void changeFieldSize();
    void changeMovesWithoutMeal();
    void changeNumOfPredators();
    void changeNumOfPreys();
    int settingsPresentation();

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
    ConsoleDialog(Settings *sett);
    int mainMenuPresentation();
    void settingsMenuPresentation();

};

#endif // CONSOLEDIALOG_H
