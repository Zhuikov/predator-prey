#ifndef UNITS_H
#define UNITS_H
#include "prey.h"

#include <vector>

class Predator;

struct Units
{
    std::vector<Prey> preys;
    std::vector<Predator> predators;
};

#endif // UNITS_H

