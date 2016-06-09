#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "coordinates.h"
#include "field.h"

class Movement
{
public:
    Movement(Coordinates current, double speed = 1.0);

    Coordinates getCurrent();

    void move();
    void moveApart();
    void setTarget(Coordinates target);
    void setRandomTarget();
    void setSpeed(double speed);

    //todo убрать когда не будет Direction
    void goToDirection(Direction);

private:

    double getDistance(Coordinates source, Coordinates dest);
    int round(double number);

    Coordinates current;
    Coordinates target;
    double speed;
    Field *field;

};

#endif // MOVEMENT_H
