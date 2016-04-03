#include "predator.h"
#include "point.h"
#include "units.h"
#include "constants.h"
#include <vector>

void Predator::directionfinding()
{
    if (this->target.getX() != -1) {
        double dist;
        dist = this->my_place - this->target;
        if ((dist > 0.9) && (dist < 1.1)) {
            this->killPrey(target);
        }
        else {
            if ((target.getX() < my_place.getX()) && (target.getY() < my_place.getY())) {
                if (field->isEmpty(my_place.getX() - 1, my_place.getY())) this->direction = 'l';
                else if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) this->direction = 'u';
                else chooseRandomDirection();
            }
            if ((target.getX() < my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX() - 1, my_place.getY())) this->direction = 'l';
                else if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) this->direction = 'd';
                else chooseRandomDirection();
            }
            if ((target.getX() > my_place.getX()) && (target.getY() < my_place.getY())) {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) this->direction = 'r';
                else if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) this->direction = 'u';
            }
            if ((target.getX() > my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) this->direction = 'r';
                else if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) this->direction = 'd';
                else chooseRandomDirection();
            }
        }
    }
    else chooseRandomDirection();

}

void Predator::findPrey()
{
    double dist = 0;
    for (unsigned int i = 0; i < this->units_struct->preys.size(); i++){
        dist = this->my_place - this->units_struct->preys[i].my_place;
        if (dist < 1.5) { this->target = this->units_struct->preys[i].my_place; }
    }

}

void Predator::killPrey(Point targ)
{
    unsigned int vec_size = this->units_struct->preys.size();
    for (unsigned int i = 0; i < vec_size; i++) {
        if (this->units_struct->preys[i].my_place == targ) {
            this->units_struct->preys[i] = this->units_struct->preys[vec_size];
            this->units_struct->preys.pop_back();
            break;
        }
    }

    if (targ.getX() < my_place.getX()) direction = 'l';
    else if (targ.getX() > my_place.getX()) direction = 'r';
    else if (targ.getY() < my_place.getY()) direction = 'u';
    else if (targ.getY() > my_place.getY()) direction = 'd';

    target.setX(-1);
    target.setY(-1);
    energy++;


    if (energy == PREDATOR_CREATE_ENERGY) this->createPredator();

}

void Predator::createPredator()
{
    chooseRandomDirection();

    switch (direction) {
    case 'u': {
        Predator pred(my_place.getX(), my_place.getY() - 1);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'r': {
        Predator pred(my_place.getX() + 1, my_place.getY());
        units_struct->predators.push_back(pred);
        break;
    }
    case 'd': {
        Predator pred(my_place.getX(), my_place.getY() + 1);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'l': {
        Predator pred(my_place.getX() - 1, my_place.getY());
        units_struct->predators.push_back(pred);
    }
    }

    unsigned int vec_size = units_struct->predators.size();
    units_struct->predators[vec_size].setPtrs(this->units_struct, this->field);

    chooseRandomDirection();
    this->energy = 0;

}

Predator::Predator(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    field->setPosition(a, b, 'X');
    target.setX(-1);
    target.setY(-1);
    life_time = 0;
    energy = 0;

    chooseRandomDirection();

}

void Predator::setPtrs(Units* ptrU, Field* ptrF)
{
    this->units_struct = ptrU;
    this->field = ptrF;
}

void Predator::movePredator()
{
    this->findPrey();
    this->field->setPosition(this->my_place.getX(), this->my_place.getY(), '.');
    this->directionfinding();
    this->go(direction);
    this->field->setPosition(this->my_place.getX(), this->my_place.getY(), 'X');

}

