#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H


class ConsoleDialog
{
    void changeField();
    void changeDayWithoutMeal();

public:
    void menuPresentation();
    void settingsPresentation();
    void setNewDayWithoutMeal(int);
    void setNewFieldBoundary(int, int);
};

#endif // CONSOLEDIALOG_H
