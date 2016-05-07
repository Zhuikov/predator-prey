#include "coordinates.h"
#include <cmath>

void Coordinates::changeToDirection(Direction direction)
{
    switch (direction) {
        case Direction::UP:    { this->setV(this->getV() - 1); break; }
        case Direction::RIGHT: { this->setH(this->getH() + 1); break; }
        case Direction::LEFT:  { this->setH(this->getH() - 1); break; }
        case Direction::DOWN:  { this->setV(this->getV() + 1); break; }
        default: {}
    }
}

double Coordinates::operator-(Coordinates &a)
{
    double distance_between_points = 0;
    distance_between_points = sqrt(pow(vertical - a.getV(), 2) + pow(horizontal - a.getH(), 2));

    return distance_between_points;
}

bool Coordinates::operator==(Coordinates a) const
{
    return (vertical == a.vertical && horizontal == a.horizontal);
}

bool Coordinates::operator!=(Coordinates a) const
{
    return (vertical != a.vertical || horizontal != a.horizontal);
}
