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
    void showMessage() { std::cerr << "Невозможно создать поле с размерами " <<
                         length << "x" << height << std::endl << "Минимальная длина и ширина поля: " <<
                         MIN_FIELD_SIZE << std::endl << "Максимальная длина и ширина поля: " <<
                         MAX_FIELD_SIZE; }
};

class BadDayWithoutMeal
{
    const int bad_value;

public:
    BadDayWithoutMeal(int a): bad_value(a) {}
    void showMessage() { std::cerr << "Введенное значение недопустимо." << std::endl <<
                         "Число должно быть в диапазоне от 1 до " << MAX_DAY_WITHOUT_MEAL; }
};

#endif // EXCEPTIONS_H
