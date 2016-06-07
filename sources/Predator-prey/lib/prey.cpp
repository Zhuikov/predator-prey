#include "prey.h"
#include <ctime>
#include <cstdlib>

void Prey::findGrass()
{
    if (target != nullptr && target->exist == false) {
        target = nullptr;
    }

    double distance = 0;
    for (Grass* grass: units_struct->grass) {
        if (grass->exist == true) {
            distance = movement.getCurrent() - grass->getPlace();
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
            new Prey(movement.getCurrent().getV() - 1, movement.getCurrent().getH(), this->field, this->units_struct);
            break;
        }
        case Direction::RIGHT: {
            new Prey(movement.getCurrent().getV(), movement.getCurrent().getH() + 1, this->field, this->units_struct);
            break;
        }
        case Direction::DOWN: {
            new Prey(movement.getCurrent().getV() + 1, movement.getCurrent().getH(), this->field, this->units_struct);
            break;
        }
        case Direction::LEFT: {
            new Prey(movement.getCurrent().getV(), movement.getCurrent().getH() - 1, this->field, this->units_struct);
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
            if (movement.getCurrent() - units_struct->predators[i]->getPlace() < 1.1) {
                warning = true;
                dangerous_pred = units_struct->predators[i]->getPlace();
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
    movement = Movement(Coordinates(v, h));
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);
    energy = 0;
    life_time = 0;
    has_moved = false;
    field = field_pointer;
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    direction = Direction::UP;
    units_struct->preys.push_back(this);
    type = UnitType::PREY;
}

Coordinates Prey::getPlace()
{
    return movement.getCurrent();
}

void Prey::movePrey()
{    
    isChase();
    directionFinding();
    if (has_moved == false) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        go();
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    }
    else has_moved = false;
    if (energy == PREY_CREATE_ENERGY) {
        createPrey();
    }
}
