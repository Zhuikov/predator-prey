#include "prey.h"
#include "units.h"
#include <ctime>
#include <cstdlib>

void Prey::directionFinding()
{
    chooseRandomDirection();
}

void Prey::chooseFarDirection()
{
    direction = UP; // пока нет травки
}

void Prey::createPrey()
{
    chooseRandomDirection();
    switch (direction) {
        case UP: {
            spawnPrey(place.getI() - 1, place.getJ());
            break;
        }
        case RIGHT: {
            spawnPrey(place.getI() - 1, place.getJ());
            break;
        }
        case DOWN: {
            spawnPrey(place.getI() - 1, place.getJ());
            break;
        }
        case LEFT: {
            spawnPrey(place.getI(), place.getJ() - 1);
        }
    }

    this->energy = 0;
}

void Prey::spawnPrey(int a, int b)
{
    Prey *prey = new Prey(a, b, this->field);
    prey->setUnitsPointer(this->units_struct);
    units_struct->preys.push_back(prey);
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
    has_moved = false;
    died = false;
    field = ptrF;
    field->setChar(this->place.getI(), this->place.getJ(), 'O');
    direction = UP;
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
    if (has_moved == false) {
        this->field->setChar(this->place.getI(), this->place.getJ(), '.');
        this->go();
        this->field->setChar(this->place.getI(), this->place.getJ(), 'O');
    }
    else has_moved = false;
    if (this->energy == PREY_CREATE_ENERGY) this->createPrey();
}
