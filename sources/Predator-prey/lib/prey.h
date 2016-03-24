#ifndef PREY_H
#define PREY_H
#include "point.h"


class Prey
{
    void go();
    int direction;
    int chase;
    int warning;
    char directionfinding(Point);

public:

    Prey(const int a, const int b) { my_place.setX(a); my_place.setY(b); }
    Point my_place;
};

#endif // PREY_H
