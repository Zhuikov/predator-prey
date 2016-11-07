#include "coordinates.h"
#include <cmath>

double Coordinates::operator-(const Coordinates &a)
{
    double distance_between_points = 0;
    distance_between_points = sqrt((vertical - a.getV()) * (vertical - a.getV()) +
                                   (horizontal - a.getH()) * (horizontal - a.getH()));

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
