#include "prey.h"
#include <ctime>
#include <cstdlib>

void Prey::findGrass()
{
    std::list< std::pair< Unit*, double > > targets;
    targets = sense.getTargets(movement.getCurrent());
    target = brain.getTarget(targets);
}

//TODO: дублирует метод из predator, можно попытаться вынести общее  в animal
void Prey::createPrey()
{
    // todo сделать это
    this->energy = 0;
}

Prey::Prey(const int v, const int h, Field* field_pointer, Units *units_pointer):
    warning(false),
    units_struct(units_pointer)
{
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);
    energy = 0;
    life_time = 0;
    has_moved = false;
    target = nullptr;
    field = field_pointer;
    movement = Movement(Coordinates(v, h), field);
    sense = Sense(field);
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    units_struct->preys.push_back(this);
    type = UnitType::PREY;
    exist = true;
}

Coordinates Prey::getPlace()
{
    return movement.getCurrent();
}

void Prey::movePrey()
{
    movement.setRandomTarget();
    movement.move();

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);

    if (energy == PREY_CREATE_ENERGY) {
        createPrey();
    }
}
