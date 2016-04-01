#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

struct Units;
class Field;

class Predator: public Animal
{
    char direction;
    int life_time;
    Point target;
    Point my_place;
    Field* field;
    Units* units_struct;
    void directionfinding();
    void findPrey();
    void killPrey(Point targ);

public:
    Predator(const int a, const int b);
    void go(const char);
    void create_predator(const Point);
    void setPtrs(Units* ptrU, Field* ptrF);
};

#endif // PREDATOR_H
