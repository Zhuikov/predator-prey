#include "consoleDialog.h"
#include <iostream>

void ConsoleDialog::changeField()
{
    int new_length = 0, new_height = 0;

    std::cout << "Введите высоту поля: ";
    std::cin >> new_height;
    std::cout << "Введите длину поля";
    std::cin >> new_length;
    if ((new_height <= MIN_FIELD_SIZE) || (new_height >= MAX_FIELD_SIZE) ||
            (new_length <= MIN_FIELD_SIZE) || (new_length >= MAX_FIELD_SIZE)) throw BadFieldBoundary;
        else {
            std::cout << "Настройки успешно изменены!" << std::endl;
            this->setNewFieldBoundary(new_length, new_height);
        }
    this->settingsPresentation();
}

void ConsoleDialog::changeDayWithoutMeal()
{
    std::cout << "Введите новое время жизни хищника (в днях): ";
    int new_time = 0;
    std::cin >> new_time;
    if ((new_time <= 0) || (new_time > MAX_DAY_WITHOUT_MEAL)) throw BadDayWithoutMeal();
         else {
                std::cout << "Настройки успешно изменены!" << std::endl;
                this->setNewDayWithoutMeal(new_time);
         }
    this->settingsPresentation();
}

void ConsoleDialog::settingsPresentation()
{
    std::cout << "1. Именить размеры поля" << std::endl;
    std::cout << "2. Изменить время жизни хищника без еды" << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cout << "Выберите нужный пункт меню: ";

    int choice = 0, good_choice = 0;

    while (good_choice == 0) {
        std::cin >> choice;
        switch (choice)
        {
            case 1: { this->changeField(); good_choice = 1; break; }
            case 2: { this->changeDayWithoutMeal(); good_choice = 1; break; }
            case 0: { this->menuPresentation(); good_choice = 1; break; }
            default: { std::cout << "Выбран неверный пункт меню."; }
        }
    }

}

void ConsoleDialog::menuPresentation()
{
    std::cout << "Модель \"Хищник-Жертва\"" << std::endl;
    std::cout << "1. Создать новую модель." << std::endl;
    std::cout << "2. Загрузить модель." << std::endl;
    std::cout << "3. Настройки." << std::endl;
    std::cout << "0. Выход." << std::endl;
    std::cout << "Выберите нужный пункт меню: ";

    int choice = 0, good_choice = 0;

    while(good_choice == 0) {
        std::cin >> choice;
        switch (choice)
        {
            case 3: { this->settingsPresentation(); break; }
        }
    }

}

