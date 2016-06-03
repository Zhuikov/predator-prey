#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "coordinates.h"

class Movement
{
public:
    Movement(Coordinates current, double speed = 1);


    Coordinates nextCoordinates();
    Coordinates getCurrent();
    void move();
    void moveApart();
    void setTarget(Coordinates target);
    void setRandomTarget();
    void setSpeed(double speed);

    Coordinates current;
    Coordinates target;
    double speed;

};

#endif // MOVEMENT_H
