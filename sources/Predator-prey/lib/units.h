#ifndef UNITS_H
#define UNITS_H
#include "predator.h"
#include "prey.h"
#include <vector>

class Predator;

class Units
{
public:
    std::vector<Prey*> preys;
    std::vector<Predator*> predators;

    Units();
    ~Units();
};

#endif // UNITS_H

