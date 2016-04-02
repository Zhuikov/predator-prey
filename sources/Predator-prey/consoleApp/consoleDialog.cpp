#include "consoleDialog.h"
#include "constants.h"
#include "exceptions.h"
#include <iostream>

void ConsoleDialog::changeFieldSize()
{
    int new_length = 0, new_height = 0;

    std::cout << "Введите высоту поля: ";
    std::cin >> new_height;
    std::cout << "Введите длину поля ";
    std::cin >> new_length;
    if ((new_height <= MIN_FIELD_SIZE) || (new_height >= MAX_FIELD_SIZE) ||
            (new_length <= MIN_FIELD_SIZE) || (new_length >= MAX_FIELD_SIZE))
                throw BadFieldBoundary(new_height, new_length);
        else {
            std::cout << "Настройки успешно изменены!" << std::endl;
            this->setNewFieldBoundary(sett, new_length, new_height);
        }
}

void ConsoleDialog::changeDayWithoutMeal()
{
    int new_time = 0;
    std::cout << "Введите новое время жизни хищника (в днях): ";
    std::cin >> new_time;

    if ((new_time <= 0) || (new_time > MAX_DAY_WITHOUT_MEAL)) throw BadDayWithoutMeal(new_time);
         else {
                std::cout << "Настройки успешно изменены!" << std::endl;
       ///         this->setNewDayWithoutMeal(new_time);
         }

    this->settingsPresentation();
}

void ConsoleDialog::changeNumOfPredators()
{
    int new_number = 0;
    std::cout << "Введите новое число хищников " << std::endl;
    std::cin >> new_number;

    if ((new_number > MAX_PREDATORS_NUM) || (new_number < 1)) throw BadNumOfPredators(new_number);
        else {
                std::cout << "Настройки успешно изменены!" << std::endl;
                this->setNumOfPredators(sett, new_number);
    }

    this->settingsPresentation();
}

void ConsoleDialog::changeNumOfPreys()
{
    int new_number = 0;
    std::cout << "Введите новое число жертв " << std::endl;
    std::cin >> new_number;

    if ((new_number > MAX_PREYS_NUM) || (new_number < 1) )throw BadNumOfPreys(new_number);
        else {
                std::cout << "Настройки успешно изменены!" << std::endl;
                this->setNumOfPreys(sett, new_number);
    }

    this->settingsPresentation();
}

ConsoleDialog::ConsoleDialog(Settings* settings)
{
    this->sett = settings;
}

void ConsoleDialog::settingsPresentation()
{
    std::cout << "1. Именить размеры поля. Текущие размеры ";
    std::cout << this->sett->field_height << " x " << this->sett->field_length << std::endl;
    std::cout << "2. Изменить количество хищников. Текущее число ";
    std::cout << this->sett->num_of_predators << std::endl;
    std::cout << "3. Изменить количество жертв. Текущее число ";
    std::cout << this->sett->num_of_preys << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды" << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cout << "Выберите нужный пункт меню: ";

    int choice = 0;
    int good_choice = 0;

    while (good_choice == 0) {
        std::cin >> choice;
        switch (choice)
        {
            case 1: { this->changeFieldSize(); good_choice = 1; break; }
            case 2: { this->changeNumOfPredators(); good_choice = 1; break; }
            case 3: { this->changeNumOfPreys(); good_choice = 1; break; }
            case 4: { this->changeDayWithoutMeal(); good_choice = 1; break; }
            case 0: { this->menuPresentation(); good_choice = 1; break; }
            default: { std::cout << "Выбран неверный пункт меню."; }
        }
    }

}

void ConsoleDialog::setNewFieldBoundary(Settings *sett, int new_length, int new_height)
{
    sett->field_length = new_length;
    sett->field_height = new_height;

    this->settingsPresentation();
}

void ConsoleDialog::setNumOfPreys(Settings *sett, int new_num)
{
    sett->num_of_preys = new_num;

    this->settingsPresentation();
}

void ConsoleDialog::setNumOfPredators(Settings* sett, int new_num)
{
    sett->num_of_predators = new_num;

    this->settingsPresentation();
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

    while(good_choice == 0) {
        std::cout << "Выберите нужный пункт меню: ";
        std::cin >> choice;
        switch (choice)
        {
            case 3: { this->settingsPresentation(); break; }
            case 0: { return 0; }
            default: { std::cout << "Выбран неверный пункт меню" << std::endl; }
        }
    }
    return 0;

}

