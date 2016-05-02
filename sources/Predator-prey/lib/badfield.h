#ifndef BADFIELD_H
#define BADFIELD_H
#include <exception>

//TODO: нельзя ли в объекте исключения хранить еще какие-то подробности, почему нельзя такое поле и какое можно?
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
