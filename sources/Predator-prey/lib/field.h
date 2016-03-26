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
    Field();
    int isEmpty(int x, int y);
    void setPosition(int x, int y, char ch);

    ~Field();
};

#endif // FIELD_H
