#ifndef PREDATOR_H
#define PREDATOR_H
#include "point.h"


class Predator
{
    static const int days_without_meal = 5;
    int direction;
    Point prey_Point;
    void find_prey;
    void go;
public:
    Predator();
};

#endif // PREDATOR_H
