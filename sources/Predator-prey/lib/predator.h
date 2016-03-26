#ifndef PREDATOR_H
#define PREDATOR_H
#include "point.h"
#include "prey.h"
#include "units.h"
#include "field.h"
#include <vector>

class Field;

class Predator
{
    char direction;
    int life_time;
    Point target;
    Point my_place;
    Field* field;
    const Units* units_struct;
    void directionfinding();
    void findPrey();

public:
    Predator(const int a, const int b);
    void go(const char);
    void create_predator(const Point);
    void setPtrs(Units* ptrU, Field* ptrF);
};

#endif // PREDATOR_H
