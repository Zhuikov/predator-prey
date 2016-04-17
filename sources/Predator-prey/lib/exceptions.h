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
        std::endl << "Максимальная длина и ширина поля: " << MAX_FIELD_SIZE << std::endl;
    }
};

class BadMovesWithoutMeal
{
    const int bad_value;
    const int max_value;

public:
    BadMovesWithoutMeal(int a, int b): bad_value(a), max_value(b) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число должно быть в диапазоне от 1 до " << max_value << std::endl;
    }
};

class BadNumOfPredators
{
    const int bad_value;
    const int max_value;

public:
    BadNumOfPredators(int a, int b): bad_value(a), max_value(b) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число хищников должно быть в диапазоне от 1 до " << max_value << std::endl;
    }

};

class BadNumOfPreys
{
    const int bad_value;
    const int max_value;

public:
    BadNumOfPreys(int a, int b): bad_value(a), max_value(b) {}
    void showMessage() {
        std::cerr << "Введенное значение недопустимо!" <<
        std::endl << "Число жертв должно быть в диапазоне от 10 до " << max_value << std::endl;
    }
};

#endif // EXCEPTIONS_H
