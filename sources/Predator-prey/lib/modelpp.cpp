#include "modelpp.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

ModelPP::ModelPP(Settings *set)
{
    this->sett = set;
    Field created_field;
    this->field = created_field;
}

void ModelPP::initializeModel()
{
    Field created_field(sett->field_height, sett->field_length);
    this->field = created_field;

    for(int i = 0; i < sett->num_of_predators; i++) {
        Predator *pred;
        int i_pred, j_pred;
        bool flag = false;
        while (!flag) {
            srand(time(0));
            i_pred = rand() % sett->field_height;
            srand(time(0));
            j_pred = rand() % sett->field_length;
            if (field.isEmpty(i_pred, j_pred)) flag = true;
        }
        pred = new Predator(i_pred, j_pred, &field);
        pred->setPtrs(&units);
        units.predators.push_back(pred);
    }

    for(int i = 0; i < sett->num_of_preys; i++) {
        Prey *pr;
        int i_prey, j_prey;
        bool flag = false;
        while (!flag) {
            srand(time(0));
            i_prey = rand() % sett->field_height;
            srand(time(0));
            j_prey = rand() % sett->field_length;
            if (field.isEmpty(i_prey, j_prey)) flag = true;
        }
        pr = new Prey(i_prey, j_prey, &field);
        pr->setPtrs(&units);
        units.preys[i] = pr;
    }
}

