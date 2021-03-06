#include "movement.h"
#include <cmath>
#include <cstdlib>

Movement::Movement(Coordinates current, Field *field, double speed) :
    current(current),
    speed(speed),
    field(field)
{
}

Coordinates Movement::getCurrent()
{
    return current;
}

int Movement::move()
{
    double distance = getDistance(current, target);

    if (std::floor(distance) <= speed)
    {
        current = target;
        return std::floor(distance);
    }

    int horizontal = round(((target.getH() - current.getH()) / distance) * speed);
    int vertical   = round(((target.getV() - current.getV()) / distance) * speed);

    bool isEmpty = false;

    for (int i = horizontal; i != ((horizontal > 0) ? -1 : 1) && !isEmpty; i += ((horizontal > 0) ? -1 : 1))
    {
        for (int j = vertical; j != ((vertical > 0) ? -1 : 1) && !isEmpty; j += ((vertical > 0) ? -1 : 1))
        {
            isEmpty = field->isEmpty(current.getV() + j, current.getH() + i);
            if (isEmpty)
            {
                current.setH(current.getH() + i);
                current.setV(current.getV() + j);
                return std::floor(getDistance(current, Coordinates(current.getV() - j, current.getH() - i)));
            }
        }
    }
    return std::floor(distance);
}

int Movement::moveApart()
{
    Coordinates tempTarget = target;

    int horizontal = (current.getH() - target.getH()) * speed;
    int vertical = (current.getV() - target.getV()) * speed;

    target = current;

    bool isEmpty = false;

    for (int i = horizontal; i != ((horizontal > 0) ? -1 : 1) && !isEmpty; i += ((horizontal > 0) ? -1 : 1))
    {
        for (int j = vertical; j != ((vertical > 0) ? -1 : 1) && !isEmpty; j += ((vertical > 0) ? -1 : 1))
        {
            isEmpty = field->isEmpty(current.getV() + j, current.getH() + i);
            if (isEmpty)
            {
                target.setH(current.getH() + i);
                target.setV(current.getV() + j);
            }
        }
    }

    int distance = move();

    target = tempTarget;

    return distance;
}


void Movement::setTarget(Coordinates target)
{
    this->target = target;
}

void Movement::setRandomTarget()
{
    int vertical = 0;
    int horizontal = 0;
    do {
        vertical = std::rand() % field->getLength();
        horizontal = std::rand() % field->getHeight();
    }
    while (((current.getV() + speed) < vertical ||
            (current.getV() - speed) > vertical ||
            (current.getH() + speed) < horizontal ||
            (current.getH() - speed) < horizontal) == false);
    target.setV(vertical);
    target.setH(horizontal);
}

void Movement::setSpeed(double speed)
{
    this->speed = std::fabs(speed);
}

double Movement::getDistance(Coordinates source, Coordinates dest)
{
    int horizontal;
    horizontal = source.getH() - dest.getH();

    int vertical;
    vertical = source.getV() - dest.getV();

    double distance;
    distance = std::sqrt(std::pow(horizontal, 2) + std::pow(vertical, 2));
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

