#ifndef PREDATOR_H
#define PREDATOR_H
#include "point.h"
#include "prey.h"
#include "units.h"
#include <vector>

class Predator
{
    char direction;
    int life_time;
    Point target;
    Point my_place;
    const Units *units_struct;
    char directionfinding(const Point);

public:
    Predator(const int a, const int b);
    void go(const char);
    void create_predator(const Point);
    void setPtrToUnitsStruct(Units *ptr);
};

#endif // PREDATOR_H
