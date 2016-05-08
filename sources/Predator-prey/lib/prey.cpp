#include "prey.h"
#include <ctime>
#include <cstdlib>

void Prey::findGrass()
{
    if (target != nullptr && target->eaten == true) {
        target = nullptr;
    }

    double distance = 0;
    for (Grass* grass: units_struct->grass) {
        if (grass->eaten == false) {
            distance = place - grass->place;
            if (distance < DISTANCE_FOR_EAT + DELTA) {
                target = grass;
                break;
            }
            if (distance < DISTANCE_FOR_TARGET + DELTA) {
                target = grass;
            }
        }
    }
}

void Prey::directionFinding() noexcept
{
    chooseRandomDirection();
}

//TODO: дублирует метод из predator, можно попытаться вынести общее  в animal
void Prey::createPrey()
{
    chooseRandomDirection();
    switch (direction) {
        case Direction::UP: {
            new Prey(this->place.getV() - 1, this->place.getH(), this->field, this->units_struct);
            break;
        }
        case Direction::RIGHT: {
            new Prey(this->place.getV(), this->place.getH() + 1, this->field, this->units_struct);
            break;
        }
        case Direction::DOWN: {
            new Prey(this->place.getV() + 1, this->place.getH(), this->field, this->units_struct);
            break;
        }
        case Direction::LEFT: {
            new Prey(this->place.getV(), this->place.getH() - 1, this->field, this->units_struct);
        }
        default: {}
    }

    this->energy = 0;
}

void Prey::isChase()
{
    warning = false;
    for (unsigned int i = 0; i < units_struct->predators.size(); ++i) {
//        if (units_struct->predators[i] != nullptr) {
            if (place - units_struct->predators[i]->place < 1.1) {
                warning = true;
                dangerous_pred = units_struct->predators[i]->place;
                break;
            }
//        }
    }
}

Prey::Prey(const int v, const int h, Field* field_pointer, Units *units_pointer):
    warning(false),
    units_struct(units_pointer),
    target(nullptr)
{
    place.setV(v);
    place.setH(h);
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);
    energy = 0;
    life_time = 0;
    has_moved = false;
    died = false;
    field = field_pointer;
    field->setPosition(this->place.getV(), this->place.getH(), Position::PREY);
    direction = Direction::UP;
    units_struct->preys.push_back(this);
}

void Prey::movePrey()
{    
    isChase();
    directionFinding();
    if (has_moved == false) {
        field->setPosition(place.getV(), place.getH(), Position::EMPTY);
        go();
        field->setPosition(place.getV(), place.getH(), Position::PREY);
    }
    else has_moved = false;
    if (energy == PREY_CREATE_ENERGY) {
        createPrey();
    }
}
