#include "coordinates.h"
#include <cmath>

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
