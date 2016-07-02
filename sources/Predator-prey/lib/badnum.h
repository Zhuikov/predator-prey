#ifndef BADNUM_H
#define BADNUM_H
#include <exception>

/**
 * @brief класс-исключение, генерируется при вводе числа, не принадлежащего
 * указанному промежутку
 */
class BadNum : public std::exception
{
    const int bad_number;

    /**
     * @brief min_boundary - нижняя граница промежутка
     */
    const int min_boundary;

    /**
     * @brief max_boundary - верхняя граница промежутка
     */
    const int max_boundary;

public:
    BadNum(const int bad_number, const int min_boundary, const int max_boundary):
        bad_number(bad_number),
        min_boundary(min_boundary),
        max_boundary(max_boundary)
    {}
    virtual const char *what() const throw()
    {
        const char *string;
        if (bad_number < min_boundary) {
            string = "Введенное значение меньше допустимого";
        }
        if (bad_number > max_boundary) {
            string = "Введенное значение больше допустимого";
        }
        return string;
    }

    /**
     * @brief метод, возвращающий верхнюю границу промежутка
     */
    int getMaxBoundary() const { return max_boundary; }

    /**
     * @brief метод, возвращающий нижнюю границу промежутка
     */
    int getMinBoundary() const { return min_boundary; }
};

#endif // BADNUM_H

