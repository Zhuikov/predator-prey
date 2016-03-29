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
    int isEmpty(int a, int b);
    void setPosition(const int a, const int b, char ch);
    char whatIsEmpty(int a, int b);
    char getChar(const int x, const int y) const;

    ~Field();
};

#endif // FIELD_H
