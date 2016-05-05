#include "model.h"
#include <ctime>
#include <cstdlib>

Model::Model(Settings *settings): settings(settings),
                                  model_time(0),
                                  model_day(0),
                                  has_changed(false),
                                  field(settings->getFieldHeight(), settings->getFieldLength())
{
    createPredators();
    createPreys();
}


bool Model::isEnd() const
{
    if (units.predators.empty() || units.preys.empty()){
        return true;
    }
    return false;
}

void Model::createPredators()
{
    for(int i = 0; i < settings->getNumOfPredators(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while(field.isEmpty(v, h) == false);

        Predator *predator = new Predator(v, h, &field, settings->getMovesWithoutMeal());
        predator->setUnitsPointer(&units);
        units.predators.push_back(predator);
    }
}

void Model::createPreys()
{
    for(int i = 0; i < settings->getNumOfPreys(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while (field.isEmpty(v, h) == false);

        Prey *prey = new Prey(v, h, &field);
        prey->setUnitsPointer(&units);
        units.preys.push_back(prey);
    }
}

//TODO: это ненужное удалить, но в любом случае можно было использовать foreach синтаксис
void Model::deletePredators()
{
    if (!units.predators.empty()) {
        for (std::vector<Predator*>::const_iterator i = units.predators.begin();
             i != units.predators.end(); ++i) delete *i;
        units.predators.clear();
    }
}

//TODO: это ненужное удалить, но в любом случае можно было использовать foreach синтаксис
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
    incModelTime();

    for(Prey* prey: units.preys){
        if(prey->died == false){
            prey->movePrey();
        }
    }
    //std::vector<Prey*>::iterator last = units.preys.end();
    //for (std::vector<Prey*>::iterator i = units.preys.begin(); i != last; ++i)
    //    if ((*i)->died == false) (*i)->movePrey();

}

void Model::movePredators()
{
    incModelTime();

    for(Predator* predator: units.predators){
        if(predator->died == false){
            predator->movePredator();
        }
    }

//    std::vector<Predator*>::iterator last = units.predators.end();
//    for (std::vector<Predator*>::iterator i = units.predators.begin(); i !=last; ++i)
//        if ((*i)->died == false) (*i)->movePredator();
}

void Model::incModelTime()
{
    if (this->has_changed == false) {
        this->model_time ++;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day++;
        this->model_time = 0;
    }
}

//TODO: не говоря о прочем, этот метод и removePreys очень похожи, уверена, что используя наследование от animal, можно попытаться объединить в один полиморфный метод,
//это можно обсудить отдельно после основного и очевидного рефакторинга
void Model::removePredators()
{
    int num_of_died = 0;
    for (std::vector<Predator*>::const_iterator it = units.predators.begin();
         it != units.predators.end(); ++it)
        if ((*it)->died == true) num_of_died++;

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (std::vector<Predator*>::iterator it = units.predators.begin();
             it != units.predators.end(); ++it) {
            if ((*it)->died == true) {
                delete (*it);
                if ((*it) != units.predators.back()) std::swap((*it), units.predators.back());
                units.predators.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

void Model::removePreys()
{
    int num_of_died = 0;
    for (std::vector<Prey*>::const_iterator it = units.preys.begin(); it != units.preys.end(); ++it)
        if ((*it)->died == true) num_of_died++;

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (std::vector<Prey*>::iterator it = units.preys.begin(); it != units.preys.end(); ++it) {
            if ((*it)->died == true) {
                delete (*it);
                if ((*it) != units.preys.back()) std::swap((*it), units.preys.back());
                units.preys.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

void Model::remove()
{
    removePredators();
    removePreys();
}

Model::~Model()
{
    deletePredators();
    deletePreys();
}
