#ifndef PREY_H
#define PREY_H
#include "point.h"


class Prey
{
    void go();
    int direction;
    int warning;
    char directionfinding(Point);

public:

    Prey(const int a, const int b) { my_place.setX(a); my_place.setY(b); }
    Point my_place;
    int chase;

};

#endif // PREY_H
