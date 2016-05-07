#ifndef BADFIELD_H
#define BADFIELD_H
#include <exception>
#include "field.h"

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
    int getMinLength() { return Field::MIN_FIELD_SIZE; }
    int getMaxLength() { return Field::MAX_FIELD_SIZE; }
};

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
    int getMinHeight() { return Field::MIN_FIELD_SIZE; }
    int getMaxHeight() { return Field::MAX_FIELD_SIZE; }
};

#endif // BADFIELD_H
