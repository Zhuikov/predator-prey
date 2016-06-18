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

void Movement::move()
{
    double distance = getDistance(current, target);

    if (std::floor(distance) <= speed)
    {
        current = target;
        return;
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
            }
        }
    }
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

// мб метод сделать приватным и пусть вызывается, когда дали nullptr в качестве таргета
void Movement::setRandomTarget()
{
    int vertical = 0;
    int horizontal = 0;
    do {
        vertical = std::rand() % field->getLength();
        horizontal = std::rand() % field->getHeight();
    }
    while (field->isEmpty(vertical, horizontal) == false);
    target.setV(vertical);
    target.setH(horizontal);
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

