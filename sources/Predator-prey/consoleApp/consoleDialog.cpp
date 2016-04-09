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
    if ((new_height < MIN_FIELD_SIZE) || (new_height > MAX_FIELD_SIZE) ||
            (new_length < MIN_FIELD_SIZE) || (new_length > MAX_FIELD_SIZE))
                throw BadFieldBoundary(new_height, new_length);
        else {
            std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
            this->setNewFieldBoundary(new_length, new_height);
        }
}

void ConsoleDialog::changeDayWithoutMeal()
{
    int new_time = 0;
    std::cout << "Введите новое время жизни хищника (в днях): ";
    std::cin >> new_time;

    if ((new_time <= 0) || (new_time > MAX_DAY_WITHOUT_MEAL)) throw BadDayWithoutMeal(new_time);
         else {
                std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
                this->setNewDayWithoutMeal(new_time);
         }

}

void ConsoleDialog::changeNumOfPredators()
{
    int new_number = 0;
    std::cout << "Введите новое число хищников ";
    std::cin >> new_number;

    if ((new_number > MAX_PREDATORS_NUM) || (new_number < 1)) throw BadNumOfPredators(new_number);
        else {
                std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
                this->setNumOfPredators(new_number);
    }

}

void ConsoleDialog::changeNumOfPreys()
{
    int new_number = 0;
    std::cout << "Введите новое число жертв ";
    std::cin >> new_number;

    if ((new_number > MAX_PREYS_NUM) || (new_number < 1) )throw BadNumOfPreys(new_number);
        else {
                std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
                this->setNumOfPreys(new_number);
    }

}

void ConsoleDialog::setNewDayWithoutMeal(int new_val)
{
    this->sett->day_without_meal = new_val;
}

ConsoleDialog::ConsoleDialog(ModelPP* modelPP, Settings* settings)
{
    this->sett = settings;
    this->model = modelPP;
}

void ConsoleDialog::settingsPresentation()
{
    int choice = 1;

    while (choice != 0) {
    std::cout << "1. Именить размеры поля. Текущие размеры ";
    std::cout << this->sett->field_height << " x " << this->sett->field_length << std::endl;
    std::cout << "2. Изменить количество хищников. Текущее число ";
    std::cout << this->sett->num_of_predators << std::endl;
    std::cout << "3. Изменить количество жертв. Текущее число ";
    std::cout << this->sett->num_of_preys << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды" << std::endl;
    std::cout << "0. Назад" << std::endl;

    int good_choice = 0;
    while (good_choice != 1) {
        std::cout << "Выберите нужный пункт меню: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1: { std::cout << std::endl; this->changeFieldSize(); good_choice = 1; break; }
            case 2: { std::cout << std::endl; this->changeNumOfPredators(); good_choice = 1; break; }
            case 3: { std::cout << std::endl; this->changeNumOfPreys(); good_choice = 1; break; }
            case 4: { std::cout << std::endl; this->changeDayWithoutMeal(); good_choice = 1; break; }
            case 0: { std::cout << std::endl; good_choice = 1; break; }
            default: { std::cout << "Выбран неверный пункт меню." << std::endl; }
        }
    }
    }
}

void ConsoleDialog::setNewFieldBoundary(int new_height, int new_length)
{
    sett->field_length = new_length;
    sett->field_height = new_height;
}

void ConsoleDialog::setNumOfPreys(int new_num)
{
    sett->num_of_preys = new_num;
}

void ConsoleDialog::setNumOfPredators(int new_num)
{
    sett->num_of_predators = new_num;
}

void ConsoleDialog::menuPresentation()
{
    int choice = 1;

    while (choice != 0) {
    std::cout << "Модель \"Хищник-Жертва\"" << std::endl;
    std::cout << "1. Создать новую модель." << std::endl;
    std::cout << "2. Загрузить модель." << std::endl;
    std::cout << "3. Настройки." << std::endl;
    std::cout << "0. Выход." << std::endl;

    int good_choice = 0;
    while (good_choice != 1) {
        std::cout << "Выберите нужный пункт меню: ";
        std::cin >> choice;
        switch (choice)
        {
            case 1: { std::cout << std::endl; this->model->initializeModel(); break;}
            case 3: { std::cout << std::endl; this->settingsPresentation(); good_choice = 1; break; }
            case 0: { std::cout << std::endl; good_choice = 1; break; }
            default: { std::cout << "Выбран неверный пункт меню" << std::endl; }
        }
    }
    }

}

