#ifndef UNITS_H
#define UNITS_H
#include "predator.h"
#include "prey.h"
#include <vector>

struct Units
{
    std::vector< Predator > predatorsVector;
    std::vector< Prey > preysVector;
};

#endif // UNITS_H

