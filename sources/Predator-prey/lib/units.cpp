#include "units.h"

Units::Units()
{
    predators.reserve(1);
    preys.reserve(1);
}

Units::~Units()
{
    for (unsigned int i = 0; i < predators.size(); i++) {
       delete predators[i];
    }

    for (unsigned int i = 0; i < preys.size(); i++) {
        delete preys[i];
    }
}
