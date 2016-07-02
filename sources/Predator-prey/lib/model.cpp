#include "model.h"
#include <algorithm>
#include <cstdlib>
#include "predator.h"
#include "prey.h"
#include "grass.h"

Model::Model(Settings *settings) noexcept:
    settings(settings),
    model_step(0),
    field(settings->getFieldHeight(), settings->getFieldLength())
{
    srand(settings->getSeed());
    createPredators();
    createPreys();
    createGrass();
}


bool Model::isEnd() const noexcept
{
    return ((units.predatorsNum == 0 || units.preysNum == 0) ||
            (getStep() == 100000));
}

void Model::createPredators() noexcept
{
    if (settings->getNumOfPredators() > (field.getHeight() * field.getLength() -
        settings->getNumOfPreys() - settings->getNumOfPredators() - settings->getNumOfGrass()))
    {
        units.predatorsNum = 0;
        return;
    }
    for (int i = 0; i < settings->getNumOfPredators(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while(field.isEmpty(v, h) == false);

        Predator* predator = new Predator(v, h, &field, &units, settings->getMovesWithoutMeal());
        predator->setAge(400);
    }
    units.predatorsNum = settings->getNumOfPredators();
}

void Model::createPreys() noexcept
{
    if (settings->getNumOfPreys() > (field.getHeight() * field.getLength() -
        settings->getNumOfPreys() - settings->getNumOfPredators() - settings->getNumOfGrass()))
    {
        units.preysNum = 0;
        return;
    }
    for (int i = 0; i < settings->getNumOfPreys(); i++) {
        int v = 0;
        int h = 0;
        do {
            v = rand() % settings->getFieldHeight();
            h = rand() % settings->getFieldLength();
        }
        while (field.isEmpty(v, h) == false);

        Prey* prey = new Prey(v, h, &field, &units, settings->getMovesWithoutMeal());
        prey->setAge(400);
    }
    units.preysNum = settings->getNumOfPreys();
}

void Model::createGrass() noexcept
{
    if (settings->getNumOfGrass() > (field.getHeight() * field.getLength() -
        units.preysNum - units.predatorsNum - units.grassNum))
    {
        return;
    }
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
    for (unsigned int i = 0; i < units.preys.size(); i++) {
        if (units.preys[i]->exist == true) {
                units.preys[i]->move();
        }
    }
}

void Model::movePredators() noexcept
{
    for (unsigned int i = 0; i < units.predators.size(); i++) {
        if (units.predators[i]->exist == true) {
                units.predators[i]->move();
        }
    }
}

void Model::move() noexcept
{
    model_step ++;    // !!!
    movePredators();
    movePreys();
    if (model_step % settings->getGrowInterval() == 0) {
        createGrass();
    }
}
