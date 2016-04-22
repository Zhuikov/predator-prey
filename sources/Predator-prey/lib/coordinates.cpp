#include "coordinates.h"
#include <cmath>

double Coordinates::operator-(Coordinates &point2)
{
    double distance_between_points = 0;
    distance_between_points = sqrt(pow(this->getI() - point2.getI(), 2) + pow(this->getJ() - point2.getJ(), 2));

    return distance_between_points;
}

bool Coordinates::operator==(Coordinates a)
{

//todo возможно, было бы лучше переделать конструкцию

//    if ((this->i == a.i) && (this->j == a.j)) return true;
//    return false;
    return ((this->i == a.i) && (this->j == a.j));
}

//todo возможно, было бы лучше переделать конструкцию
bool Coordinates::operator!=(Coordinates a)
{
    if ((this->i != a.i) || (this->j != a.j)) return true;
    return false;
}
