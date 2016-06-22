#include "units.h"
#include "predator.h"
#include "prey.h"
#include "grass.h"

Units::Units()
{
    predators.reserve(1);
    preys.reserve(1);
    predatorsNum = 0;
    preysNum = 0;
    grassNum = 0;
}

Units::~Units()
{
    for (Predator* predator: predators) {
       delete predator;
    }

    for (Prey* prey: preys) {
        delete prey;
    }

    for (Grass* grassptr: grass) {
        delete grassptr;
    }
}
