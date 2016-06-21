#include "model.h"
#include <algorithm>
#include <cstdlib>
#include "predator.h"
#include "prey.h"
#include "grass.h"

Model::Model(Settings *settings, int seed) noexcept:
    settings(settings),
    model_time(0),
    model_day(0),
    has_changed(false),
    field(settings->getFieldHeight(), settings->getFieldLength())
{
    srand(seed);
    createPredators();
    createPreys();
    createGrass();
    units.predatorsNum = settings->getNumOfPredators();
    units.preysNum = settings->getNumOfPreys();
}


bool Model::isEnd() const noexcept
{
   return units.predatorsNum == 0 || units.preysNum == 0;

}

void Model::createPredators() noexcept
{
    for(int i = 0; i < settings->getNumOfPredators(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while(field.isEmpty(v, h) == false);

        new Predator(v, h, &field, &units, settings->getMovesWithoutMeal());
    }
}

void Model::createPreys() noexcept
{
    for(int i = 0; i < settings->getNumOfPreys(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while (field.isEmpty(v, h) == false);

        new Prey(v, h, &field, &units, settings->getMovesWithoutMeal());
    }
}

void Model::createGrass() noexcept
{
    for (int i = 0; i < settings->getNumOfGrass(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while (field.isEmpty(v, h) == false);

        new Grass(v, h, &field, &units);
    }
    units.grassNum += settings->getNumOfGrass();
}

void Model::movePreys() noexcept
{
    incModelTime();

    //std::vector< Prey* >::iterator last = units.preys.end();
    //for (std::vector< Prey* >::iterator i = units.preys.begin(); i != last; ++i) {
    //    if ((*i)->exist == true) (*i)->move();
    //}
    //unsigned int last = units.preys.size();
    for (unsigned int i = 0; i < units.preys.size(); i++) {
        if (units.preys[i]->exist == true) {
                units.preys[i]->move();
        }
    }

}

void Model::movePredators() noexcept
{
    incModelTime();

    //std::vector< Predator* >::iterator last = units.predators.end();
    //for (std::vector< Predator* >::iterator i = units.predators.begin(); i !=last; ++i) {
    //    if ((*i)->exist == true) {
    //        (*i)->move();
    //    }
    //}
    //unsigned int last = units.predators.size();
    for (unsigned int i = 0; i < units.predators.size(); i++) {
        if (units.predators[i]->exist == true) {
                units.predators[i]->move();
        }
    }
}

void Model::move() noexcept
{
    movePredators();
    movePreys();
}

void Model::incModelTime() noexcept
{
    if (this->has_changed == false) {
        this->model_time ++;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day ++;
        this->model_time = 0;
    }
}

//TODO: не говоря о прочем, этот метод и removePreys очень похожи, уверена, что используя наследование от animal, можно попытаться объединить в один полиморфный метод,
//это можно обсудить отдельно после основного и очевидного рефакторинга


void Model::removePredators() noexcept
{
    for (std::vector< Predator* >::iterator it = units.predators.begin(); it != units.predators.end(); ++it) {
        if ( (*it)->exist == false ) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    units.predators.erase( std::remove(units.predators.begin(), units.predators.end(), nullptr),
                            units.predators.end() );
}

void Model::removePreys() noexcept
{
    for (std::vector< Prey* >::iterator it = units.preys.begin(); it != units.preys.end(); ++it) {
        if ( (*it)->exist == false ) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    units.preys.erase( std::remove(units.preys.begin(), units.preys.end(), nullptr),
                            units.preys.end() );
}

void Model::remove() noexcept
{
    removePredators();
    removePreys();
}
