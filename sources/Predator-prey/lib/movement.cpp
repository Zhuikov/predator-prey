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

    if (distance <= speed)
    {
        current = target;
        return;
    }

    //?????????
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

void Movement::setRandomTarget()
{
    target.setH(std::rand() % field->getHeight());
    target.setV(std::rand() % field->getLength());
}

void Movement::setSpeed(double speed)
{
    this->speed = speed;
}

//void Movement::goToDirection(Direction direction)
//{
//    switch (direction) {
//        case Direction::UP:    { current.setV(current.getV() - 1); break; }
//        case Direction::RIGHT: { current.setH(current.getH() + 1); break; }
//        case Direction::LEFT:  { current.setH(current.getH() - 1); break; }
//        case Direction::DOWN:  { current.setV(current.getV() + 1); break; }
//        default: {}
//    }
//}

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

