#ifndef PREY_H
#define PREY_H
#include "animal.h"

class Prey: public Animal
{
    int direction;
    int warning;
    char directionfinding(Point);

public:

    Prey(const int a, const int b) { my_place.setX(a); my_place.setY(b); }
    Point my_place;
    int chase;
    void go(char ch);
};

#endif // PREY_H
