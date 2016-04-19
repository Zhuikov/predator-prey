#include "units.h"
#include <iostream>

Units::Units()
{
    predators.reserve(1);
    preys.reserve(1);
}

Units::~Units()
{
    for (std::vector<Predator*>::const_iterator i = predators.begin(); i != predators.end(); ++i) {
       delete *i;
    }
    for (std::vector<Prey*>::const_iterator i = preys.begin(); i != preys.end(); ++i) {
        delete *i;
    }

}
