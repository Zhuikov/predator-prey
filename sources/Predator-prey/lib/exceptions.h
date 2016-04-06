#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include "constants.h"

class BadFieldBoundary
{
    const int length;
    const int height;

public:
    BadFieldBoundary(int a, int b): length(a), height(b) {}
    void showMessage() {
        std::cerr << "Невозможно создать поле с размерами " << length << "x" << height <<
        std::endl << "Минимальная длина и ширина поля: " << MIN_FIELD_SIZE <<
        std::endl << "Максимальная длина и ширина поля: " << MAX_FIELD_SIZE << std::endl << std::endl;
    }
};

class BadDayWithoutMeal
{
    const int bad_value;

public:
    BadDayWithoutMeal(int a): bad_value(a) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число должно быть в диапазоне от 1 до " << MAX_DAY_WITHOUT_MEAL << std::endl << std::endl;
    }
};

class BadNumOfPredators
{
    const int bad_value;

public:
    BadNumOfPredators(int a): bad_value(a) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число хищников должно быть в диапазоне от 1 до " << MAX_PREDATORS_NUM << std::endl << std::endl;
    }

};

class BadNumOfPreys
{
    const int bad_value;

public:
    BadNumOfPreys(int a): bad_value(a) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число жертв должно быть в диапазоне от 1 до " << MAX_PREYS_NUM << std::endl << std::endl;
    }
};

#endif // EXCEPTIONS_H
