#ifndef FIELD_H
#define FIELD_H
#include "settings.h"

class Settings;

class Field
{
    Settings* sett;
    char** field;
    int length;
    int height;

public:
    Field(int n, int m);
    int isEmpty(int x, int y);
    void setPosition(const int x, const int y, char ch);
    char whatIsEmpty(int x, int y);
    char getChar(const int x, const int y) const;

    ~Field();
};

#endif // FIELD_H
