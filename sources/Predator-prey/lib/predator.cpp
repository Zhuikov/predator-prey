#include "predator.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

void Predator::directionFinding() noexcept
{
    if (target == nullptr){
        chooseRandomDirection();
    }
    else {
        double distance = movement.getCurrent() - target->getPlace();
        if (fabs(distance - DISTANCE_FOR_EAT) < DELTA) {
            killPrey();
        }
        else chooseToTargetDirection();
    }
}

void Predator::chooseToTargetDirection() noexcept
{
    if ((movement.getCurrent().getV() <= target->getPlace().getV()) &&
        (movement.getCurrent().getH() < target->getPlace().getH())) {
            if (setDirection(Direction::RIGHT) == false)
                if (setDirection(Direction::DOWN) == false) chooseRandomDirection();
    }
    if ((movement.getCurrent().getV() < target->getPlace().getV()) &&
        (movement.getCurrent().getH() >= target->getPlace().getH())) {
            if (setDirection(Direction::DOWN) == false)
                if (setDirection(Direction::LEFT) == false) chooseRandomDirection();
    }
    if ((movement.getCurrent().getV() > target->getPlace().getV()) &&
        (movement.getCurrent().getH() <= target->getPlace().getH())) {
            if (setDirection(Direction::UP) == false)
                if (setDirection(Direction::RIGHT) == false) chooseRandomDirection();
    }
    if ((movement.getCurrent().getV() >= target->getPlace().getV()) &&
        (movement.getCurrent().getH() > target->getPlace().getH())) {
            if (setDirection(Direction::LEFT) == false)
                if (setDirection(Direction::UP) == false) chooseRandomDirection();
    }
}

void Predator::findPrey() noexcept
{
    if (target != nullptr && (target->exist == false ||
           target->getPlace() - movement.getCurrent() > DISTANCE_FOR_RESET_TARGET)) target = nullptr;
    
    double distance = 0;
    for (Prey* prey: units_struct->preys) {
        if (prey->exist == true) {
            distance = movement.getCurrent() - prey->getPlace();
            if (distance < DISTANCE_FOR_EAT + DELTA) {
                target = prey;
                break;
            }
            if (distance < DISTANCE_FOR_TARGET + DELTA) {
                target = prey;
            }
        }
    }
}

void Predator::killPrey() noexcept
{
    if (target->getPlace().getV() < movement.getCurrent().getV()) direction = Direction::UP;
    else if (target->getPlace().getV() > movement.getCurrent().getV()) direction = Direction::DOWN;
    else if (target->getPlace().getH() < movement.getCurrent().getH()) direction = Direction::LEFT;
    else if (target->getPlace().getH() > movement.getCurrent().getH()) direction = Direction::RIGHT;

    target->exist = false;
    
    energy ++;
    life_time = -1;
    target = nullptr;

}

void Predator::createPredator() noexcept
{
    chooseRandomDirection();
    switch (direction) {
    case Direction::UP:    {
        new Predator(movement.getCurrent().getV() - 1, movement.getCurrent().getH(), this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::RIGHT: {
        new Predator(movement.getCurrent().getV(), movement.getCurrent().getH() + 1, this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::DOWN:  {
        new Predator(movement.getCurrent().getV() + 1, movement.getCurrent().getH(), this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::LEFT:  {
        new Predator(movement.getCurrent().getV(), movement.getCurrent().getH() - 1, this->field,
                                          this->units_struct, this->max_life_time);
    }
    default: {}
    }

    this->energy = 0;

}

Predator::Predator(int v, int h, Field *field_pointer, Units *units_pointer, int time_of_life) noexcept:
    target(nullptr),
    units_struct(units_pointer)
{
    movement = Movement(Coordinates(v, h));
    life_time = 0;
    max_life_time = time_of_life;
    energy = 0;
    has_moved = false;
    field = field_pointer;
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    direction = Direction::UP;
    units_pointer->predators.push_back(this);
    type = UnitType::PREDATOR;
}

Coordinates Predator::getPlace()
{
    return movement.getCurrent();
}

void Predator::movePredator() noexcept
{
    findPrey();
    directionFinding();
    if (has_moved == false) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        go();
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
    }
    else has_moved = false;

    if (energy == PREDATOR_CREATE_ENERGY) {
        createPredator();
    }

    life_time++;
    if (life_time == max_life_time) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        exist = false;
    }
}
