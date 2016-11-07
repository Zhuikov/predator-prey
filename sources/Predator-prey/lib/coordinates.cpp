#include "coordinates.h"
#include <cmath>

double Coordinates::operator-(const Coordinates &a)
{
    double distance_between_points = 0;

    double relativeV = vertical - a.getV();
    double relativeH = horizontal - a.getH();

    distance_between_points = sqrt(relativeV * relativeV + relativeH * relativeH);

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
