#ifndef BADFIELD_H
#define BADFIELD_H
#include <exception>
#include "field.h"

/**
 * @brief класс-исключение, генерируется при попытке создания поля со слишком
 * большой (маленькой) длиной
 */
class BadFieldLength : public std::exception
{
    int length;
public:
    BadFieldLength(int length): length(length) {}
    virtual const char *what() const throw()
    {
        const char *string = "Невозможно создать поле с введенной длиной";
        return string;
    }
    /**
     * @brief метод, возвращающий минимальную длину поля
     */
    int getMinLength() { return Field::MIN_FIELD_SIZE; }

    /**
     * @brief метод, возвращающий максимальную длину поля
     */
    int getMaxLength() { return Field::MAX_FIELD_SIZE; }
};

/**
 * @brief класс-исключение, генерируется при попытке создания поля со слишком
 * большой (маленькой) высотой
 */
class BadFieldHeight : public std::exception
{
    int height;
public:
    BadFieldHeight(int height): height(height) {}
    virtual const char *what() const throw()
    {
        const char *string = "Невозможно создать поле с введенной высотой";
        return string;
    }

    /**
     * @brief метод, возвращающий минимальную высоту поля
     */
    int getMinHeight() { return Field::MIN_FIELD_SIZE; }

    /**
     * @brief метод, возвращающий максимальную высоту поля
     */
    int getMaxHeight() { return Field::MAX_FIELD_SIZE; }
};

#endif // BADFIELD_H
