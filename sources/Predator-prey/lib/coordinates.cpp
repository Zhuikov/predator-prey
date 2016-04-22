#include "coordinates.h"
#include <cmath>

double Coordinates::operator-(Coordinates &coord2)
{
    double distance_between_points = 0;
    distance_between_points = sqrt(pow(this->getI() - coord2.getI(), 2) + pow(this->getJ() - coord2.getJ(), 2));

    return distance_between_points;
}

bool Coordinates::operator==(Coordinates a) const
{
    return (this->i == a.i && this->j == a.j);
}

bool Coordinates::operator!=(Coordinates a) const
{
    return (this->i != a.i || this->j != a.j);
}
