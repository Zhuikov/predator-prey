#include "modelpp.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

ModelPP::ModelPP(Settings *set)
{
    this->sett = set;
    Field created_field(sett->field_height, sett->field_length);
    this->field = created_field;
    day = 0;
    model_time = 0;
}

void ModelPP::initializeModel()
{
    Field created_field(sett->field_height, sett->field_length);
    this->field = created_field;
    srand(time(0));

    for(int i = 0; i < sett->num_of_predators; i++) {
        int i_pred, j_pred;
        bool flag = false;
        while (!flag) {
            i_pred = rand() % sett->field_height;
            j_pred = rand() % sett->field_length;
            if (field.isEmpty(i_pred, j_pred)) flag = true;
        }
        Predator *pred = new Predator(i_pred, j_pred, &field);
        pred->setPtrs(&units);
        units.predators.push_back(pred);
    }

    for(int i = 0; i < sett->num_of_preys; i++) {
        int i_prey, j_prey;
        bool flag = false;
        while (!flag) {
            i_prey = rand() % sett->field_height;
            j_prey = rand() % sett->field_length;
            if (field.isEmpty(i_prey, j_prey)) flag = true;
        }
        Prey *pr = new Prey(i_prey, j_prey, &field);
        pr->setPtrs(&units);
        units.preys.push_back(pr);
    }
}

