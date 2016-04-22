#include "consoleDialog.h"
#include "constants.h"
#include "exceptions.h"
#include <iostream>

void ConsoleDialog::changeFieldSize()
{
    char *first_after_num;
    std::cout << "Введите высоту поля: ";
    std::getline(std::cin, this->input_number);
    new_height = strtol(input_number.c_str(), &first_after_num, 10);
    if ((new_height == 0 && input_number.size() > 1) || *first_after_num != '\0') throw InputError();

    std::cout << "Введите длину поля: ";
    std::getline(std::cin, this->input_number);
    new_length = strtol(input_number.c_str(), &first_after_num, 10);
    if ((new_length == 0 && input_number.size() > 1) || *first_after_num != '\0') throw InputError();

    if (new_height < MIN_FIELD_SIZE || new_height > MAX_FIELD_SIZE ||
            new_length < MIN_FIELD_SIZE || new_length > MAX_FIELD_SIZE)
                throw BadFieldCreate();
        else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeMovesWithoutMeal()
{
    char *first_after_num;
    std::cout << "Введите новое время жизни хищника (в ходах): ";
    std::getline(std::cin, this->input_number);
    new_time = strtol(input_number.c_str(), &first_after_num, 10);

    int MAX_MOVES_WITHOUT_MEAL = this->sett->max_moves_without_meal;

    if ((new_time == 0 && input_number.size() > 1) || *first_after_num != '\0') throw InputError();
    if (new_time < 5 || new_time > MAX_MOVES_WITHOUT_MEAL)
        throw BadMovesWithoutMeal(new_time, MAX_MOVES_WITHOUT_MEAL);
         else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPredators()
{
    char *first_after_num;
    std::cout << "Введите новое число хищников: ";
    std::getline(std::cin, this->input_number);
    new_number = strtol(input_number.c_str(), &first_after_num, 10);

    int MAX_PREDATORS_NUM = std::max(sett->field_height, sett->field_length) * 2;

    if ((new_number == 0 && input_number.size() > 1) || *first_after_num != '\0') throw InputError();
    if (new_number > MAX_PREDATORS_NUM || new_number < 1) throw BadNumOfPredators(new_number, MAX_PREDATORS_NUM);
        else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

void ConsoleDialog::changeNumOfPreys()
{
    char *first_after_num;
    std::cout << "Введите новое число жертв: ";
    std::getline(std::cin, this->input_number);
    new_number = strtol(input_number.c_str(), &first_after_num, 10);

    int MAX_PREYS_NUM = std::max(sett->field_height, sett->field_length) * 2;

    if ((new_number == 0 && input_number.size() > 1) || *first_after_num != '\0') throw InputError();
    if (new_number > MAX_PREYS_NUM || new_number < 1) throw BadNumOfPreys(new_number, MAX_PREYS_NUM);
    else std::cout << "Настройки успешно изменены!" << std::endl << std::endl;
}

ConsoleDialog::ConsoleDialog(Settings *sett)
{
    new_number = 3;
    new_height = 10;
    new_length = 10;
    new_time = 3;
    this->sett = sett;
}

void ConsoleDialog::settingsMenuPresentation()
{
    int choice = -1;
    while (choice != 0) {
        choice = this->settingsPresentation();
        try{
        switch (choice) {
            case 1: {
                std::cout << std::endl;
                this->changeFieldSize();
                this->setNewFieldBoundary(new_length, new_height);
                break;
            }
            case 2: {
                std::cout << std::endl;
                this->changeNumOfPredators();
                this->setNumOfPredators(new_number);
                break;
            }
            case 3: {
                std::cout << std::endl;
                this->changeNumOfPreys();
                this->setNumOfPreys(new_number);
               break;
            }
            case 4: {
                std::cout << std::endl;
                this->changeMovesWithoutMeal();
                this->setNewMovesWithoutMeal(new_time);
                break;
            }
            case 0: {
                std::cout << std::endl;
                break;
            }
        }
        }
        catch (InputError &e)
        {
            e.showMessage();;
            choice = -1;
        }
        catch (BadFieldCreate& e)
        {
            e.showMessage();
            choice = -1;
        }
        catch (BadNumOfPredators& e)
        {
            e.showMessage();
            choice = -1;
        }
        catch (BadNumOfPreys& e)
        {
            e.showMessage();
            choice = -1;
        }
        catch (BadMovesWithoutMeal& e)
        {
            e.showMessage();
            choice = -1;
        }
    }
}

void ConsoleDialog::setNewFieldBoundary(const int new_height, const int new_length)
{
    sett->field_length = new_length;
    sett->field_height = new_height;

    if (sett->num_of_predators > std::max(new_height, new_length) * 2)
            sett->num_of_predators = std::max(new_height, new_length) * 2;

    if (sett->num_of_preys > std::max(new_height, new_length) * 2)
            sett->num_of_preys = std::max(new_height, new_length) * 2;
}

void ConsoleDialog::setNumOfPreys(const int new_num)
{
    sett->num_of_preys = new_num;
}

void ConsoleDialog::setNumOfPredators(const int new_num)
{
    sett->num_of_predators = new_num;
}

void ConsoleDialog::setNewMovesWithoutMeal(const int new_val)
{
    sett->moves_without_meal = new_val;
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
            //todo можно все упростить используя if
            switch (command)
            {
                case 1: { return 1; }
                case 2: { return 2; }
                case 0: { return 0; }
                default: { std::cout << "Выбран неверный пункт меню" << std::endl; }
            }
        }
        catch (std::exception &) {
            std::cout << "Выбран неверный пункт меню" << std::endl;
        }
    }

    return 0;
}

int ConsoleDialog::settingsPresentation()
{
    std::cout << "1. Именить размеры поля.                 Текущие размеры ";
    std::cout << sett->field_height << " x " << sett->field_length << std::endl;
    std::cout << "2. Изменить количество хищников.         Текущее число ";
    std::cout << sett->num_of_predators << std::endl;
    std::cout << "3. Изменить количество жертв.            Текущее число ";
    std::cout << sett->num_of_preys << std::endl;
    std::cout << "4. Изменить время жизни хищника без еды. Текущее время ";
    std::cout << sett->moves_without_meal << std::endl;
    std::cout << "0. Назад" << std::endl;

    bool good_choice = false;
    std::string choice;
    while (good_choice == false) {
        std::cout << "Выберите нужный пункт меню: ";
        std::getline(std::cin, choice);
        try {
        int command = consoleCommands.at(choice);
        //todo можно все упростить используя if
        switch (command)
        {
            case 1: { return 1; }
            case 2: { return 2; }
            case 3: { return 3; }
            case 4: { return 4; }
            case 0: { return 0; }
            default: { std::cout << "Выбран неверный пункт меню" << std::endl; }
        }
        }
        catch (std::exception &)
        {
            std::cout << "Выбран неверный пункт меню!" << std::endl;
        }
    }
    return 0;
}
