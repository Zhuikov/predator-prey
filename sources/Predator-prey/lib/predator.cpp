#include "predator.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

void Predator::findPrey() noexcept
{
    std::list< std::pair< Unit*, double > > targets;
    targets = sense.getTargets(movement.getCurrent());
    target = brain.getTarget(targets);
}

void Predator::createPredator() noexcept
{
    //todo сделать как-нибудь

    this->energy = 0;

}

Predator::Predator(int v, int h, Field *field_pointer, Units *units_pointer, int time_of_life) noexcept:
    units_struct(units_pointer)
{
    life_time = 0;
    max_life_time = time_of_life;
    energy = 0;
    has_moved = false;
    target = nullptr;
    field = field_pointer;
    movement = Movement(Coordinates(v, h), field);
    sense = Sense(field);
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    units_pointer->predators.push_back(this);
    type = UnitType::PREDATOR;
    exist = true;
}

Coordinates Predator::getPlace()
{
    return movement.getCurrent();
}

void Predator::movePredator() noexcept
{
    findPrey();

    if (target == nullptr) {
        movement.setRandomTarget();
    }
    else {
        movement.setTarget(target->getPlace());
    }

    movement.move();

    if (target != nullptr && movement.getCurrent() == target->getPlace()) {
        killTarget();
    }

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);

//    if (energy == PREDATOR_CREATE_ENERGY) {
//        createPredator();
//    }

    life_time++;
    if (life_time == max_life_time) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        exist = false;
    }
}
