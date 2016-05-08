#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include "settings.h"
#include "model.h"
#include "consoledrawer.h"
#include <string>

/**
 * @brief класс, содержащий консольные меню для взаидействия с пользователем
 */
class ConsoleDialog
{
    std::string input_number;
    Settings *settings;

    /**
     * @brief метод, выводящий в консоль меню изменения настроек поля
     */
    void changeFieldSize();

    /**
     * @brief метод, выводящий в консоль меню изменения времени жизни животного без еды
     */
    void changeMovesWithoutMeal();

    /**
     * @brief метод, выводящий в консоль меню изменения числа хищников
     */
    void changeNumOfPredators();

    /**
     * @brief метод, выводящий в консоль меню изменения числа жертв
     */
    void changeNumOfPreys();

    /**
     * @brief метод, выводящий в консоль меню настроек
     * @return int - выбранный пункт меню
     */
    int settingsPresentation();

    /**
     * @brief считывает из консоли число и возвращает его
     */
    int readInt();

public:
    ConsoleDialog(Settings *settings): settings(settings) {}

    /**
     * @brief метод, выводящий в консоль главное меню
     * @return int - выбранный пункт меню
     */
    int mainMenuPresentation();
    /**
     * @brief метод, обрабатывающий выбранный пункт в меню настроек
     */
    void settingsMenuPresentation();

};

#endif // CONSOLEDIALOG_H
