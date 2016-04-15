#include "consoleDialog.h"
#include "constants.h"
#include "exceptions.h"
#include <iostream>

void ConsoleDialog::changeFieldSize()
{
    std::cout << "Введите высоту поля: ";
    std::cin >> new_height;
    std::cout << "Введите длину поля ";
    std::cin >> new_length;
    if ((new_height < MIN_FIELD_SIZE) || (new_height > MAX_FIELD_SIZE) ||
            (new_length < MIN_FIELD_SIZE) || (new_length > MAX_FIELD_SIZE))
                throw BadFieldBoundary(new_height, new_length);
        else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeDayWithoutMeal()
{
    std::cout << "Введите новое время жизни хищника (в днях): ";
    std::cin >> new_time;

    if ((new_time <= 0) || (new_time > MAX_DAY_WITHOUT_MEAL)) throw BadDayWithoutMeal(new_time);
         else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPredators()
{
    std::cout << "Введите новое число хищников: ";
    std::cin >> new_number;

    if ((new_number > MAX_PREDATORS_NUM) || (new_number < 1)) throw BadNumOfPredators(new_number);
        else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPreys()
{
    std::cout << "Введите новое число жертв: ";
    std::cin >> new_number;

    if ((new_number > MAX_PREYS_NUM) || (new_number < 1) )throw BadNumOfPreys(new_number);
        else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

ConsoleDialog::ConsoleDialog()
{
    new_number = 3;
    new_height = 10;
    new_length = 10;
    new_time = 3;
}

void ConsoleDialog::settingsPresentation(Settings *sett)
{

    std::cout << "1. Именить размеры поля. Текущие размеры ";
    std::cout << sett->field_height << " x " << sett->field_length << std::endl;
    std::cout << "2. Изменить количество хищников. Текущее число ";
    std::cout << sett->num_of_predators << std::endl;
    std::cout << "3. Изменить количество жертв. Текущее число ";
    std::cout << sett->num_of_preys << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды" << std::endl;
    std::cout << "0. Назад" << std::endl;

    int choice = 0;
    int good_choice = 0;
    while (good_choice != 1) {
        std::cout << "Выберите нужный пункт меню: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1: {
                std::cout << std::endl;
                this->changeFieldSize();
                this->setNewFieldBoundary(sett, new_length, new_height);
                good_choice = 1;
                break;
            }
            case 2: {
                std::cout << std::endl;
                this->changeNumOfPredators();
                this->setNumOfPredators(sett, new_number);
                good_choice = 1;
                break;
            }
            case 3: {
                std::cout << std::endl;
                this->changeNumOfPreys();
                this->setNumOfPreys(sett, new_number);
                good_choice = 1;
                break;
            }
            case 4: {
                std::cout << std::endl;
                this->changeDayWithoutMeal();
                this->setNewDayWithoutMeal(sett, new_time);
                good_choice = 1;
                break;
            }
            case 0: {
                std::cout << std::endl;
                good_choice = 1;
                break;
            }
            default: { std::cout << "Выбран неверный пункт меню." << std::endl; }
        }
    }
}

void ConsoleDialog::setNewFieldBoundary(Settings *sett, const int new_height, const int new_length)
{
    sett->field_length = new_length;
    sett->field_height = new_height;
}

void ConsoleDialog::setNumOfPreys(Settings *sett, const int new_num)
{
    sett->num_of_preys = new_num;
}

void ConsoleDialog::setNumOfPredators(Settings *sett, const int new_num)
{
    sett->num_of_predators = new_num;
}

void ConsoleDialog::setNewDayWithoutMeal(Settings *sett, const int new_val)
{
    sett->day_without_meal = new_val;
}

int ConsoleDialog::menuPresentation()
{

    std::cout << "Модель \"Хищник-Жертва\"" << std::endl;
    std::cout << "1. Создать новую модель." << std::endl;
    std::cout << "2. Загрузить модель." << std::endl;
    std::cout << "3. Настройки." << std::endl;
    std::cout << "0. Выход." << std::endl;

    int choice = 0;
    int good_choice = 0;
    while (good_choice != 1) {
        std::cout << "Выберите нужный пункт меню: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1: { return 1; }
            case 3: { return 3; }
            case 0: { return 0; }
            default: { std::cout << "Выбран неверный пункт меню" << std::endl; }
        }
    }
    return 0;
}
