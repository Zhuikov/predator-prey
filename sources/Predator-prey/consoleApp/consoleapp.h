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

    /**
     * @brief TIME_FOR_SLEEP - время (мкс) между отрисовкой модели
     */
    const int TIME_FOR_SLEEP = 500000;

    /**
     * @brief метод, создающий модель и отрисовывающий информацию о ней в консоль
     */
    void startModel();

public:
    ConsoleApp();
    ConsoleApp(const ConsoleApp&) = delete;

    /**
     * @brief метод, создающий консольное приложение
     */
    void createConsole();

    ~ConsoleApp();
};

#endif // CONSOLEAPP_H
