#ifndef BRAIN_H
#define BRAIN_H
#include "coordinates.h"
#include "unit.h"
#include <list>

class Brain
{
public:
    Brain();

    Coordinates getTarget(std::list< Unit* > targets);


    int age;
    int energy;
    int maxEnergy;
    // todo добавить все остальное
};

#endif // BRAIN_H
