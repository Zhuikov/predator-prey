#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

class Units;
class Field;

class Predator: public Animal
{
protected:
    Point target;
    Units* units_struct;
    void directionfinding();
    void findPrey();
    void killPrey(Point targ);
    void createPredator();

public:
    Predator(const int a, const int b);
    void setPtrs(Units* ptrU, Field* ptrF);
    void movePredator();

};

#endif // PREDATOR_H
