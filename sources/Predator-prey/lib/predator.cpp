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
        double distance = place - target->place;
        if (fabs(distance - DISTANCE_FOR_EAT) < DELTA) {
            killPrey();
        }
        else chooseToTargetDirection();
    }
}

void Predator::chooseToTargetDirection() noexcept
{
    if ((place.getV() <= target->place.getV()) && (place.getH() < target->place.getH())) {
            if (setDirection(Direction::RIGHT) == false)
                if (setDirection(Direction::DOWN) == false) chooseRandomDirection();
    }
    if ((place.getV() < target->place.getV()) && (place.getH() >= target->place.getH())) {
            if (setDirection(Direction::DOWN) == false)
                if (setDirection(Direction::LEFT) == false) chooseRandomDirection();
    }
    if ((place.getV() > target->place.getV()) && (place.getH() <= target->place.getH())) {
            if (setDirection(Direction::UP) == false)
                if (setDirection(Direction::RIGHT) == false) chooseRandomDirection();
    }
    if ((place.getV() >= target->place.getV()) && (place.getH() > target->place.getH())) {
            if (setDirection(Direction::LEFT) == false)
                if (setDirection(Direction::UP) == false) chooseRandomDirection();
    }
}

void Predator::findPrey() noexcept
{
    if (target != nullptr && (target->died == true ||
           target->place - place > DISTANCE_FOR_RESET_TARGET)) target = nullptr;
    
    double distance = 0;
    for (Prey* prey: units_struct->preys) {
        if (prey->died == false) {
            distance = place - prey->place;
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
    if (target->place.getV() < place.getV()) direction = Direction::UP;
    else if (target->place.getV() > place.getV()) direction = Direction::DOWN;
    else if (target->place.getH() < place.getH()) direction = Direction::LEFT;
    else if (target->place.getH() > place.getH()) direction = Direction::RIGHT;

    target->died = true;
    
    energy++;
    life_time = -1;
    target = nullptr;

}

void Predator::createPredator() noexcept
{
    chooseRandomDirection();
    switch (direction) {
    case Direction::UP:    {
        new Predator(this->place.getV() - 1, this->place.getH(), this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::RIGHT: {
        new Predator(this->place.getV(), this->place.getH() + 1, this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::DOWN:  {
        new Predator(this->place.getV() + 1, this->place.getH(), this->field,
                                          this->units_struct, this->max_life_time);
        break;
    }
    case Direction::LEFT:  {
        new Predator(this->place.getV(), this->place.getH() - 1, this->field,
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
    place.setV(v);
    place.setH(h);
    life_time = 0;
    max_life_time = time_of_life;
    energy = 0;
    has_moved = false;
    died = false;
    field = field_pointer;
    field->setPosition(place.getV(), place.getH(), Position::PREDATOR);
    direction = Direction::UP;
    units_pointer->predators.push_back(this);
}

void Predator::movePredator() noexcept
{
    findPrey();
    directionFinding();
    if (has_moved == false) {
        field->setPosition(place.getV(), place.getH(), Position::EMPTY);
        go();
        field->setPosition(place.getV(), place.getH(), Position::PREDATOR);
    }
    else has_moved = false;

    if (energy == PREDATOR_CREATE_ENERGY) {
        createPredator();
    }

    life_time++;
    if (life_time == max_life_time) {
        field->setPosition(place.getV(), place.getH(), Position::EMPTY);
        died = true;
    }
}
