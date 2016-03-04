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

    Prey(const int a, const int b);
};

#endif // PREY_H
