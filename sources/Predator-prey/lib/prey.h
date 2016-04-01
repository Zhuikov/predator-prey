#ifndef PREY_H
#define PREY_H
#include "animal.h"

struct Units;

class Prey: public Animal
{
protected:
    int warning;
    Units* units_struct;
    void directionfinding();
    void CreatePrey(Point);

public:
    Prey(const int a, const int b);
};

#endif // PREY_H
