#ifndef BADNUM_H
#define BADNUM_H
#include <exception>

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

