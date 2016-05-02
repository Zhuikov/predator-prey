#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include "consoledialog.h"
#include "consoledrawer.h"

/**
 * @brief класс - консольное приложение
 * создает модель, настройки и организует консольное взаимодействие с пользователем
 */

class ConsoleApp
{
    ConsoleDialog *dialog;
    ConsoleDrawer *drawer;
    Settings *settings;
    Model *model;

    const int time_for_sleep = 500000;
    void startModel();

public:
    ConsoleApp();

    /**
     * @brief метод, создающий консольное приложение
     */
    void createConsole();

    ~ConsoleApp();
};

#endif // CONSOLEAPP_H
