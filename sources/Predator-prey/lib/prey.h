#ifndef PREY_H
#define PREY_H
#include "animal.h"

class Prey: protected Animal
{
protected:
    int warning;
    void directionfinding();

public:
    Prey(const int a, const int b) { my_place.setX(a); my_place.setY(b); }
    int chase;
    Point my_place;
};

#endif // PREY_H
