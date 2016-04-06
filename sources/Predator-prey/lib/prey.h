#ifndef PREY_H
#define PREY_H
#include "animal.h"

class Units;

class Prey: public Animal
{
protected:
    int warning;
    Point dangerous_pred;
    Units* units_struct;
    void directionfinding();
    void createPrey();
    void isChase();

public:
    Prey(const int a, const int b);
    void setPtrs(Units* ptrU, Field* ptrF);
};

#endif // PREY_H
