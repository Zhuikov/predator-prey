#ifndef BADBOUNDARY_H
#define BADBOUNDARY_H
#include <exception>

/**
 * @brief класс-исключение, генерируется при указании неверных индексов
 */
class BadFieldBoundary : public std::exception
{
    int vertical;
    int horizontal;
public:
    BadFieldBoundary(int v, int h): vertical(v), horizontal(h) {}
    virtual const char *what() const throw()
    {
        const char *string = "Элемента с такими индексами не существует";
        return string;
    }
};

#endif // BADBOUNDARY_H

