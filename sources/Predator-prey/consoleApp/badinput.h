#ifndef BADINPUT_H
#define BADINPUT_H
#include <exception>

/**
 * @brief класс-исключение, генерируется при неверном вводе
 */
class InputError : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        const char *string = "Ошибка ввода";
        return string;
    }
};

#endif // BADINPUT_H

