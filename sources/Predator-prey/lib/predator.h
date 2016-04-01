#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

struct Units;
class Field;

class Predator: protected Animal
{
protected:
    int life_time;
    Point target;
    Units* units_struct;
    void directionfinding();
    void findPrey();
    void killPrey(Point targ);
    void create_predator(const Point);

public:
    Predator(const int a, const int b);
    void setPtrs(Units* ptrU, Field* ptrF);
    Point my_place;
};

#endif // PREDATOR_H
