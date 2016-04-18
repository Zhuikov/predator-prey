#include "modelpp.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

ModelPP::ModelPP(Settings *set)
{
    this->sett = set;
    Field created_field(sett->field_height, sett->field_length);
    this->field = created_field;
    model_day = 0;
    model_time = 0;
    has_changed = false;
}

Field *ModelPP::getField()
{
    return &field;
}

void ModelPP::initializeModel()
{
    this->model_day = 0;
    this->model_time = 0;
    this->has_changed = false;

    if (!units.predators.empty()) {
        for (std::vector<Predator*>::const_iterator i = units.predators.begin();
             i != units.predators.end(); ++i) delete *i;
        units.predators.clear();
    }

    if (!units.preys.empty()) {
        for (std::vector<Prey*>::const_iterator i = units.preys.begin();
             i != units.preys.end(); ++i) delete *i;
        units.preys.clear();
    }

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
        Predator *pred = new Predator(i_pred, j_pred, &field, sett->moves_without_meal);
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

int ModelPP::getTime()
{
    return this->model_time;
}

int ModelPP::getDay()
{
    return this->model_day;
}

bool ModelPP::isEnd()
{
    if (units.predators.empty() || units.preys.empty()) return true;
    return false;
}

void ModelPP::moveEnd()
{
    int num_of_died = 0;
    for (unsigned int i = 0; i < this->units.predators.size(); i++) {
        if (this->units.predators[i]->died == true)
            num_of_died ++;
    }

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (unsigned int i = 0; i < this->units.predators.size(); i++) {
            if (this->units.predators[i]->died == true) {
                delete this->units.predators[i];
                if (this->units.predators[i] != this->units.predators.back())
                    std::swap(this->units.predators[i], this->units.predators.back());
                this->units.predators.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }

    num_of_died = 0;
    for (unsigned int i = 0; i < this->units.preys.size(); i++) {
        if (this->units.preys[i]->died == true)
            num_of_died ++;
    }

    num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (unsigned int i = 0; i < this->units.preys.size(); i++) {
            if (this->units.preys[i]->died == true) {
                delete this->units.preys[i];
                if (this->units.preys[i] != this->units.preys.back())
                    std::swap(this->units.preys[i], this->units.preys.back());
                this->units.preys.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

void ModelPP::movePreys()
{
    if (!this->has_changed) {
        this->model_time = this->model_time + 1;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day++;
        this->model_time = 0;
    }

    for (unsigned int i = 0; i < this->units.preys.size(); i++)
        if (this->units.preys[i]->died == false) this->units.preys[i]->movePrey();

}

void ModelPP::movePredators()
{
    if (!this->has_changed) {
        this->model_time = this->model_time + 1;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day++;
        this->model_time = 0;
    }

    /*
     * Когда кто-то из хищников порождает первого хищника (т.е. если изначально было 3 хищника, а стало 4),
     * то все работает хорошо. Как только появляется еще один хищник, (т.е. становится 5),
     * итератор, видимо, сходит с ума и указывает на несуществующего хищника. Так происходит с любым
     * начальным числом хищников.
     * Дебаг-тест (самый последний) это может продемонстрировать; там еще пояснения есть.
     *
     * Жертвы пока никого не порождают. Никто не умирает "от старости".


    for (std::vector<Predator*>::iterator i = this->units.predators.begin();
         i != this->units.predators.end(); ++i) {
            (*i)->movePredator();
    }
    */

    for (unsigned int i = 0; i < this->units.predators.size(); i++)
        if (this->units.predators[i]->died == false) this->units.predators[i]->movePredator();
}
