#include "consoledialog.h"
#include "badfield.h"
#include "badnum.h"
#include "badinput.h"
#include <iostream>

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
    std::cout << "Максимальная длина и высота поля: " << Field::MAX_FIELD_SIZE << std::endl
              << "Минимальная длина и высота поля: " << Field::MIN_FIELD_SIZE << std::endl;

    std::cout << "Введите высоту поля: ";
    int length = readInt();
    settings->setFieldLength(length);

    std::cout << "Введите длину поля: ";
    int height = readInt();
    settings->setFieldHeight(height);

    std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeMovesWithoutMeal()
{
    std::cout << "Значение должно быть в пределах от "
              << settings->getMinMovesWithoutMeal() << "до "
              << settings->getMaxMovesWithoutMeal() << std::endl
              << "Введите новое время жизни хищника (в ходах): ";

    int moves = readInt();
    settings->setMovesWithoutMeal(moves);

    std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPredators()
{
    int MAX_NUM = std::max(settings->getFieldHeight(), settings->getFieldLength()) * 2;

    std::cout << "Значение должно быть в пределах от 1 до " << MAX_NUM << std::endl
              << "Введите новое число хищников: ";

    int number = readInt();
    settings->setNumOfPredators(number);

    std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPreys()
{
    int MAX_NUM = std::max(settings->getFieldHeight(), settings->getFieldLength()) * 2;

    std::cout << "Значение должно быть в пределах от 1 до " << MAX_NUM << std::endl
              << "Введите новое число жертв: ";

    int number = readInt();
    settings->setNumOfPreys(number);

    std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
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
    std::cout << settings->getFieldHeight() << " x " << settings->getFieldLength() << std::endl;
    std::cout << "2. Изменить количество хищников.         Текущее число ";
    std::cout << settings->getNumOfPredators() << std::endl;
    std::cout << "3. Изменить количество жертв.            Текущее число ";
    std::cout << settings->getNumOfPreys() << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды. Текущее время ";
    std::cout << settings->getMovesWithoutMeal() << std::endl;
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
