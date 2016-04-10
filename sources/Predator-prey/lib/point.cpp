#include "point.h"
#include <cmath>

double Point::operator-(const Point point2)
{
    double distance_between_points = 0;
    distance_between_points = sqrt(pow(this->getX() - point2.getX(), 2) + pow(this->getY() - point2.getY(), 2));

    return distance_between_points;
}

bool Point::operator==(Point a)
{
    if ((this->x == a.x) && (this->y == a.y)) return true;
    return false;
}

bool Point::operator!=(Point a)
{
    if ((this->x != a.x) || (this->y != a.y)) return true;
    return false;
}
