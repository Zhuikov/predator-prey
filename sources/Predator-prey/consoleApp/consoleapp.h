#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H
#include "consoleDialog.h"
#include "consoledrawer.h"

/**
 * @brief класс - консольное приложение
 * создает модель, настройки и организует консольное взаимодействие с пользователем
 */

class ConsoleApp
{
    //todo не экономте буковоки
    ConsoleDialog *CD;
    ConsoleDrawer *drawer;
    Settings *sett;
    ModelPP *model;

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
