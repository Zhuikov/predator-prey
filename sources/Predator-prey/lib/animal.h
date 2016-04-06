#ifndef ANIMAL_H
#define ANIMAL_H
#include "point.h"
#include "field.h"

class Animal
{
protected:
    int life_time;
    int energy;
    char direction;
    void chooseRandomDirection();
    virtual void directionfinding() = 0;
    Field* field;

public:
    virtual void go(char ch);
    Point my_place;

    virtual ~Animal() {}
};

#endif // ANIMAL_H
