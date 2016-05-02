#ifndef BADNUM_H
#define BADNUM_H
#include <exception>

//TODO: нельзя ли в объекте исключения хранить еще какие-то подробности, почему значение не допустимо
class BadNum : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        const char *string = "Введенное значение недопустимо";
        return string;
    }
};

#endif // BADNUM_H

