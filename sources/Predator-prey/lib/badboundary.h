#ifndef BADBOUNDARY_H
#define BADBOUNDARY_H
#include <exception>

//TODO: можно добавить поля, в которых хранить, какие именно позиции оказались плохими
class BadFieldBoundary : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        const char *string = "Элемента с такими индексами не существует";
        return string;
    }
};

#endif // BADBOUNDARY_H

