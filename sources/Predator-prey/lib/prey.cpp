#include "prey.h"
#include "units.h"
#include <ctime>
#include <cstdlib>

void Prey::directionFinding()
{
    chooseRandomDirection();
}

//TODO: дублирует метод из predator, можно попытаться вынести общее  в animal
void Prey::createPrey()
{
    chooseRandomDirection();
    switch (direction) {
        case UP: {
            spawnPrey(place.getV() - 1, place.getH());
            break;
        }
        case RIGHT: {
            spawnPrey(place.getV(), place.getH() + 1);
            break;
        }
        case DOWN: {
            spawnPrey(place.getV() + 1, place.getH());
            break;
        }
        case LEFT: {
            spawnPrey(place.getV(), place.getH() - 1);
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
    warning = false;
    for (unsigned int i = 0; i < this->units_struct->predators.size(); ++i) {
        if (this->units_struct->predators[i] != NULL) {
            if (this->place - units_struct->predators[i]->place < 1.1) {
                warning = true;
                this->dangerous_pred = units_struct->predators[i]->place;
                break;
            }
        }
    }
}

Prey::Prey(const int v, const int h, Field* ptrF)
{
    place.setV(v);
    place.setH(h);
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);
    energy = 0;
    life_time = 0;
    has_moved = false;
    died = false;
    field = ptrF;
    field->setPosition(this->place.getV(), this->place.getH(), PREY);
    direction = UP;
    warning = false;
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
        this->field->setPosition(this->place.getV(), this->place.getH(), EMPTY);
        this->go();
        this->field->setPosition(this->place.getV(), this->place.getH(), PREY);
    }
    else has_moved = false;
    if (this->energy == PREY_CREATE_ENERGY) this->createPrey();
}
