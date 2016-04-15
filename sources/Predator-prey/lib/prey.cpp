#include "prey.h"
#include "units.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

void Prey::directionfinding()
{
    if (warning == 1) {
        if (my_place.getI() < dangerous_pred.getI()) {
            if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) direction = 'u';
                else chooseRandomDirection(); }
        if (my_place.getI() > dangerous_pred.getI()) {
            if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) direction = 'd';
                else chooseRandomDirection(); }
        if (my_place.getJ() > dangerous_pred.getJ()) {
            if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) direction = 'r';
                else chooseRandomDirection(); }
        if (my_place.getJ() < dangerous_pred.getJ()) {
            if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) direction = 'l';
                else chooseRandomDirection(); }
    }
    else chooseRandomDirection();
}

void Prey::createPrey()
{
    chooseRandomDirection();

    switch (direction) {
        case 'u': {
            Prey *prey = new Prey(my_place.getI() - 1, my_place.getJ(), this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'r': {
            Prey *prey = new Prey(my_place.getI(), my_place.getJ() + 1, this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'd': {
            Prey *prey = new Prey(my_place.getI() + 1, my_place.getJ(), this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'l': {
            Prey *prey = new Prey(my_place.getI(), my_place.getJ() - 1, this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
        }
    }

    this->energy = 0;
}

void Prey::isChase()
{
    warning = 0;
    for (std::vector<Predator*>::const_iterator i = this->units_struct->predators.begin();
         i != this->units_struct->predators.end(); ++i) {
            if (this->my_place - (*i)->my_place < 1.1) {
                warning = 1;
                this->dangerous_pred = (*i)->my_place;
            }
    }
}

Prey::Prey(const int a, const int b, Field* ptrF)
{
    my_place.setI(a);
    my_place.setJ(b);
    dangerous_pred.setI(-1);
    dangerous_pred.setJ(-1);
    energy = 0;
    life_time = 0;
    has_moved = 0;
    field = ptrF;
    field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'O');
    direction = 'u';
    warning = 0;
}

void Prey::setPtrs(Units* ptrU)
{
    this->units_struct = ptrU;
    isChase();
}

void Prey::movePrey()
{    
    isChase();
    this->directionfinding();
    if (!has_moved) {
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), '.');
        this->go(direction);
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'O');
    }
    else has_moved = 0;
    if (this->energy == PREY_CREATE_ENERGY) this->createPrey();
}
