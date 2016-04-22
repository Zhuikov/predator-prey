#include "model.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

Model::Model(Settings *set)
{
    this->sett = set;
    Field created_field;
    this->field = created_field;
    model_day = 0;
    model_time = 0;
    has_changed = false;
}

void Model::initializeModel()
{
    this->model_day = 0;
    this->model_time = 0;
    this->has_changed = false;
    
    Field created_field(sett->field_height, sett->field_length);
    this->field = created_field;
    srand(time(0));  
    
    deletePredators();
    deletePreys();
    
    createPredators();
    createPreys();
}

bool Model::isEnd() const
{
    if (units.predators.empty() || units.preys.empty()) return true;
    return false;
}

void Model::createPredators()
{
    for(int i = 0; i < sett->num_of_predators; i++) {
        int i_pred = 0;
        int j_pred = 0;
        while (1 == 1) {
            i_pred = rand() % sett->field_height;
            j_pred = rand() % sett->field_length;
            if (field.isEmpty(i_pred, j_pred)) break;
        }
        Predator *pred = new Predator(i_pred, j_pred, &field, sett->moves_without_meal);
        pred->setUnitsPointer(&units);
        units.predators.push_back(pred);
    }
}

void Model::deletePredators()
{
    if (!units.predators.empty()) {
        for (std::vector<Predator*>::const_iterator i = units.predators.begin();
             i != units.predators.end(); ++i) delete *i;
        units.predators.clear();
    }
}

void Model::createPreys()
{
    for(int i = 0; i < sett->num_of_preys; i++) {
        int i_prey = 0;
        int j_prey = 0;
        while (1 == 1) {
            i_prey = rand() % sett->field_height;
            j_prey = rand() % sett->field_length;
            if (field.isEmpty(i_prey, j_prey)) break;
        }
        Prey *pr = new Prey(i_prey, j_prey, &field);
        pr->setUnitsPointer(&units);
        units.preys.push_back(pr);
    }
}

void Model::deletePreys()
{
    if (!units.preys.empty()) {
        for (std::vector<Prey*>::const_iterator i = units.preys.begin();
             i != units.preys.end(); ++i) delete *i;
        units.preys.clear();
    }
}

void Model::movePreys()
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

    std::vector<Prey*>::iterator last = units.preys.end();
    for (std::vector<Prey*>::iterator i = units.preys.begin(); i != last; ++i)
        if ((*i)->died == false) (*i)->movePrey();

}

void Model::movePredators()
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

    std::vector<Predator*>::iterator last = units.predators.end();
    for (std::vector<Predator*>::iterator i = units.predators.begin(); i !=last; ++i)
        if ((*i)->died == false) (*i)->movePredator();
}

void Model::remove()
{
    unsigned int vec_size = units.predators.size();

    //todo выделить в отдельные методы
    //тут похоже даже одним може обойтись, ему просто передавать разные вектора
    int num_of_died = 0;
    for (std::vector<Predator*>::const_iterator it = units.predators.begin(); it != units.predators.end(); ++it)
        if ((*it)->died == true) num_of_died++;

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (unsigned int i = 0; i < vec_size; i++) {
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
    for (std::vector<Prey*>::const_iterator it = units.preys.begin(); it != units.preys.end(); ++it)
        if ((*it)->died == true) num_of_died++;

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
