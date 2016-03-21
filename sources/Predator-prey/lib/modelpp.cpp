#include "modelpp.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

void ModelPP::initializeModel(const Settings &sett)
{
    for(int i = 0; i < sett.num_of_predators; i++) {
        srand(time(0));
        Predator pred(rand() % sett.field_length, rand() % sett.field_height);
        this->predatorVector[i] = pred;
    }

    for(int i = 0; i < sett.num_of_preys; i++) {
        srand(time(0));
        Prey pr(rand() % sett.field_length, rand() % sett.field_height);
        this->preyVector[i] = pr;
    }


}
