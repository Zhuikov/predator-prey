#include "units.h"
#include <iostream>

Units::Units()
{
    predators.reserve(1);
    preys.reserve(1);
}

//TODO: foreach syntax
Units::~Units()
{
    for (Predator* predator: predators) {
       delete predator;
    }
    for (Prey* prey: preys) {
        delete prey;
    }

}
