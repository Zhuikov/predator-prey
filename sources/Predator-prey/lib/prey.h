#ifndef PREY_H
#define PREY_H
#include "point.h"


class Prey
{
    void go();
    int direction;
    int chase;
    int warning;
    Point my_place;
    char directionfinding(Point);

public:

    Prey(const int a, const int b) { my_place.setX(a); my_place.setY(b); }
};

#endif // PREY_H
