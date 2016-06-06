#include "movement.h"
#include <cmath>

Movement::Movement(Coordinates current, double speed) : current(current), speed(speed)
{

}

Coordinates Movement::getCurrent()
{
    return current;
}

void Movement::move()
{
    double distance = getDistance(current, target);

    if (distance <= speed)
    {
        current = target;
        return;
    }

    int horizontal = round(((target.getH() - current.getH()) / distance) * speed);
    int vertical   = round(((target.getV() - current.getV()) / distance) * speed);

    current.setH(current.getH() + horizontal);
    current.setV(current.getV() + vertical);
}

void Movement::moveApart()
{
    Coordinates tempTarget = target;

    target.setH( 2 * current.getH() - target.getH());
    target.setV( 2 * current.getV() - target.getV());

    move();

    target = tempTarget;
}


void Movement::setTarget(Coordinates target)
{
    this->target = target;
}

void Movement::setSpeed(double speed)
{
    this->speed = speed;
}

double Movement::getDistance(Coordinates source, Coordinates dest)
{
    int horizontal;
    horizontal = source.getH() - dest.getH();

    int vertical;
    vertical = source.getV() - dest.getV();

    double distance;
    distance = std::pow(std::pow(horizontal, 2) + std::pow(vertical, 2), 0.5);
    return distance;
}

int Movement::round(double number)
{
    if (number > 0)
    {
        number = std::ceil(number);
    }
    else
    {
        number = std::floor(number);
    }
    return number;
}

