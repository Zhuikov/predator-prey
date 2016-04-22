#include "prey.h"
#include "units.h"
#include "constants.h"
#include <ctime>
#include <cstdlib>

void Prey::directionFinding()
{
    chooseRandomDirection();
}

void Prey::createPrey()
{
    chooseRandomDirection();
    //todo выделить метод и вызывать его в кейсах
    switch (direction) {
        case 'u': {
            Prey *prey = new Prey(place.getI() - 1, place.getJ(), this->field);
            prey->setUnitsPointer(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'r': {
            Prey *prey = new Prey(place.getI(), place.getJ() + 1, this->field);
            prey->setUnitsPointer(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'd': {
            Prey *prey = new Prey(place.getI() + 1, place.getJ(), this->field);
            prey->setUnitsPointer(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'l': {
            Prey *prey = new Prey(place.getI(), place.getJ() - 1, this->field);
            prey->setUnitsPointer(this->units_struct);
            units_struct->preys.push_back(prey);
        }
    }

    this->energy = 0;
}

void Prey::isChase()
{
    warning = 0;
    for (unsigned int i = 0; i < this->units_struct->predators.size(); ++i) {
        if (this->units_struct->predators[i] != NULL) {
            if (this->place - units_struct->predators[i]->place < 1.1) {
                warning = 1;
                this->dangerous_pred = units_struct->predators[i]->place;
                break;
            }
        }
    }
}

Prey::Prey(const int a, const int b, Field* ptrF)
{
    place.setI(a);
    place.setJ(b);
    dangerous_pred.setI(-1);
    dangerous_pred.setJ(-1);
    energy = 0;
    life_time = 0;
    has_moved = 0;
    died = false;
    field = ptrF;
    field->setChar(this->place.getI(), this->place.getJ(), 'O');
    direction = 'u';
    warning = 0;
}

void Prey::setUnitsPointer(Units* units_pointer)
{
    this->units_struct = units_pointer;
    isChase();
}

void Prey::movePrey()
{    
    isChase();
    this->directionFinding();
    if (!has_moved) {
        this->field->setChar(this->place.getI(), this->place.getJ(), '.');
        this->go();
        this->field->setChar(this->place.getI(), this->place.getJ(), 'O');
    }
    else has_moved = 0;
    if (this->energy == PREY_CREATE_ENERGY) this->createPrey();
}
