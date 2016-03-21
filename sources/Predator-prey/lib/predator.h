#ifndef PREDATOR_H
#define PREDATOR_H
#include "point.h"


class Predator
{
    char direction;
    int life_time;
    Point target;
    Point my_place;
    Point find_prey();
    void create_predator(const Point);
    void go(const char);
    char directionfinding(const Point);

public:

    Predator(const int a, const int b);
};

#endif // PREDATOR_H
