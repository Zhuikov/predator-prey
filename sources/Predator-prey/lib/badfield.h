#ifndef BADFIELD_H
#define BADFIELD_H
#include <exception>

class BadFieldCreate : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        const char *string = "Невозможно создать поле с введенными размерами";
        return string;
    }
};

#endif // BADFIELD_H
