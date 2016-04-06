#include "modelapi.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

void ModelAPI::initializeModel(const Settings &sett, Units &units, Field &field)
{
    for(int i = 0; i < sett.num_of_predators; i++) {
        srand(time(0));
        Predator *pred;
        pred = new Predator(rand() % sett.field_length, rand() % sett.field_height);
        pred->setPtrs(&units, &field);
        units.predators[i] = pred;
    }

    for(int i = 0; i < sett.num_of_preys; i++) {
        srand(time(0));
        Prey *pr;
        pr = new Prey(rand() % sett.field_length, rand() % sett.field_height);
        pr->setPtrs(&units, &field);
        units.preys[i] = pr;
    }
}
