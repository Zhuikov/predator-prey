#ifndef BRAIN_H
#define BRAIN_H
//#include "coordinates.h"
#include "unit.h"
#include <list>

class Brain
{
public:

    virtual Unit* getTarget(std::list< Unit* > targets) = 0;

    int age;
    int energy;
    int maxEnergy;
    // todo добавить все остальное
};

#endif // BRAIN_H
