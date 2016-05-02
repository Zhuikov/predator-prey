#include "consoledialog.h"
#include "badfield.h"
#include "badnum.h"
#include "badinput.h"
#include <iostream>

//TODO в этом классе надо не забывать про форматирование строк, добавлять пробельные строки для разделения на блоки зрительно и т.п.

int ConsoleDialog::readInt()
{
    std::getline(std::cin, this->input_number);
    char *first_after_num;
    int input = strtol(input_number.c_str(), &first_after_num, 10);
    if ((input == 0 && input_number.size() > 1) || *first_after_num != '\0')
    {
                        throw InputError();
    }
    return input;
}

void ConsoleDialog::changeFieldSize()
{
    std::cout << "Максимальная длина и высота поля: " << Field::MAX_FIELD_SIZE << std::endl;
    std::cout << "Минимальная длина и высота поля: " << Field::MIN_FIELD_SIZE << std::endl;

    std::cout << "Введите высоту поля: ";
    int length = readInt();

    std::cout << "Введите длину поля: ";
    int height = readInt();

    if (height < Field::MIN_FIELD_SIZE || height > Field::MAX_FIELD_SIZE ||
            length < Field::MIN_FIELD_SIZE || length > Field::MAX_FIELD_SIZE)
    {
                throw BadFieldCreate();
    }
    else
    {
        std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
        this->setNewFieldBoundary(length, height);
    }
}

void ConsoleDialog::changeMovesWithoutMeal()
{
    std::cout << "Значение должно быть в пределах от 5 до 1000" << std::endl;
    std::cout << "Введите новое время жизни хищника (в ходах): ";
    int time = readInt();

    if (time < 5 || time > settings->max_moves_without_meal)
    {
        throw BadNum();
    }
    else
    {
        std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
        this->setNewMovesWithoutMeal(time);
    }
}

void ConsoleDialog::changeNumOfPredators()
{
    int MAX_NUM = std::max(settings->field_height, settings->field_length) * 2;

    std::cout << "Значение должно быть в пределах от 1 до " << MAX_NUM << std::endl;
    std::cout << "Введите новое число хищников: ";
    int number = readInt();

    if (number > MAX_NUM || number < 1) throw BadNum();
    else
    {
        std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
        this->setNumOfPredators(number);
    }
}

void ConsoleDialog::changeNumOfPreys()
{
    int MAX_NUM = std::max(settings->field_height, settings->field_length) * 2;

    std::cout << "Значение должно быть в пределах от 1 до " << MAX_NUM << std::endl;
    std::cout << "Введите новое число жертв: ";
    int number = readInt();

    if (number > MAX_NUM || number < 1) throw BadNum();
    else
    {
        std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
        this->setNumOfPreys(number);
    }
}

ConsoleDialog::ConsoleDialog(Settings *sett)
{
    this->settings = sett;
}

void ConsoleDialog::settingsMenuPresentation()
{
    int choice = -1;
    while (choice != 0) {
        choice = this->settingsPresentation();
        try {
        switch (choice) {
            case 1: {
                std::cout << std::endl;
                this->changeFieldSize();
                break;
            }
            case 2: {
                std::cout << std::endl;
                this->changeNumOfPredators();
                break;
            }
            case 3: {
                std::cout << std::endl;
                this->changeNumOfPreys();
               break;
            }
            case 4: {
                std::cout << std::endl;
                this->changeMovesWithoutMeal();
                break;
            }
            case 0: {
                std::cout << std::endl;
                break;
            }
        }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl << std::endl;
        }
    }
}

void ConsoleDialog::setNewFieldBoundary(const int new_height, const int new_length)
{
    settings->field_length = new_length;
    settings->field_height = new_height;

    if (settings->num_of_predators > std::max(new_height, new_length) * 2)
            settings->num_of_predators = std::max(new_height, new_length) * 2;

    if (settings->num_of_preys > std::max(new_height, new_length) * 2)
            settings->num_of_preys = std::max(new_height, new_length) * 2;
}

void ConsoleDialog::setNumOfPreys(const int new_num)
{
    settings->num_of_preys = new_num;
}

void ConsoleDialog::setNumOfPredators(const int new_num)
{
    settings->num_of_predators = new_num;
}

void ConsoleDialog::setNewMovesWithoutMeal(const int new_val)
{
    settings->moves_without_meal = new_val;
}

int ConsoleDialog::mainMenuPresentation()
{
    std::cout << "Модель \"Хищник-Жертва\"" << std::endl;
    std::cout << "1. Создать новую модель." << std::endl;
    std::cout << "2. Настройки." << std::endl;
    std::cout << "0. Выход." << std::endl;

    std::string choice;
    bool good_choice = false;
    while (good_choice == false) {
        std::cout << "Выберите нужный пункт меню: ";
        std::getline(std::cin, choice);
        try {
            int command = consoleCommands.at(choice);
            if (command < 3) return command;
                else std::cout << "Выбран неверный пункт меню" << std::endl;

        }

        catch (std::exception &) {
            std::cout << "Выбран неверный пункт меню" << std::endl;
        }
    }

    return 0;
}

int ConsoleDialog::settingsPresentation()
{
    std::cout << std::endl;
    std::cout << "1. Именить размеры поля.                 Текущие размеры ";
    std::cout << settings->field_height << " x " << settings->field_length << std::endl;
    std::cout << "2. Изменить количество хищников.         Текущее число ";
    std::cout << settings->num_of_predators << std::endl;
    std::cout << "3. Изменить количество жертв.            Текущее число ";
    std::cout << settings->num_of_preys << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды. Текущее время ";
    std::cout << settings->moves_without_meal << std::endl;
    std::cout << "0. Назад" << std::endl;

    bool good_choice = false;
    std::string choice;
    while (good_choice == false) {
        std::cout << "Выберите нужный пункт меню: ";
        std::getline(std::cin, choice);
        try {
            int command = consoleCommands.at(choice);
            if (command < 5) return command;
                else std::cout << "Выбран неверный пункт меню" << std::endl;
        }
        catch (std::exception &) {
            std::cout << "Выбран неверный пункт меню" << std::endl;
        }
    }
    return 0;
}
