#ifndef ANIMAL_H
#define ANIMAL_H
#include "point.h"
#include "field.h"

class Animal
{
protected:
    char direction;
    virtual void directionfinding() = 0;
    Field* field;

public:
    virtual void go(char ch);
    Point my_place;
};

#endif // ANIMAL_H
