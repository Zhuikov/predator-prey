#include "modelapi.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

void ModelAPI::initializeModel(const Settings &sett, Units &units)
{
    for(int i = 0; i < sett.num_of_predators; i++) {
        srand(time(0));
        Predator pred(rand() % sett.field_length, rand() % sett.field_height);
        pred.setPtrToUnitsStruct(&units);
        units.predators[i] = pred;
    }

    for(int i = 0; i < sett.num_of_preys; i++) {
        srand(time(0));
        Prey pr(rand() % sett.field_length, rand() % sett.field_height);
        units.preys[i] = pr;
    }
}
