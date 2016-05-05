#include "coordinates.h"
#include <cmath>

double Coordinates::operator-(Coordinates &coord2)
{
    double distance_between_points = 0;
    distance_between_points = sqrt(pow(this->getV() - coord2.getV(), 2) + pow(this->getH() - coord2.getH(), 2));

    return distance_between_points;
}

bool Coordinates::operator==(Coordinates a) const
{
    return (this->vertical == a.vertical && this->horizontal == a.horizontal);
}

bool Coordinates::operator!=(Coordinates a) const
{
    return (this->vertical != a.vertical || this->horizontal != a.horizontal);
}
