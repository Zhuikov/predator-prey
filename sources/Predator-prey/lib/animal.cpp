#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::killTarget() noexcept
{
    target->exist = false;

    energy ++;
    life_time = -1;
    target = nullptr;
}

void Animal::findTarget() noexcept
{
    //std::list< std::pair< Unit*, double > > targets;
    //targets = sense.getTargets(movement.getCurrent());
    target = brain->getTarget(sense.getTargets(movement.getCurrent()));
}

Coordinates Animal::getPlace()
{
    return movement.getCurrent();
}

Animal::Animal(const int v, const int h, Field *field_pointer)
{
    energy = 0;
    life_time = 0;
    has_moved = false;
    target = nullptr;
    field = field_pointer;
    movement = Movement(Coordinates(v, h), field);
    sense = Sense(field);
    exist = true;
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
}
