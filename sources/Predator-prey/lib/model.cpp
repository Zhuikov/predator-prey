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
    for (unsigned int i = 0; i < units.preys.size(); i++) {
        if (units.preys[i]->exist == true) {
                units.preys[i]->move();
        }
    }

}

void Model::movePredators() noexcept
{
    incModelTime();
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
