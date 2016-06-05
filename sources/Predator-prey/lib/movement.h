#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "coordinates.h"

class Movement
{
public:
    Movement(Coordinates current, double speed = 1.0);

    Coordinates getCurrent();

    void move();
    void moveApart();
    void setTarget(Coordinates target);
    void setRandomTarget() {}
    void setSpeed(double speed);

private:

    double getDistance(Coordinates source, Coordinates dest);
    int round(double number);

    Coordinates current;
    Coordinates target;
    double speed;

};

#endif // MOVEMENT_H
