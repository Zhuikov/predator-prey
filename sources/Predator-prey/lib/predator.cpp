#include "predator.h"
#include "point.h"
#include "units.h"
#include "constants.h"
#include <vector>
#include <ctime>
#include <cstdlib>

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
                if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) this->direction = 'l';
                else if (field->isEmpty(my_place.getX() - 1, my_place.getY())) this->direction = 'u';
                else chooseRandomDirection();
            }
            if ((target.getX() < my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) this->direction = 'r';
                else if (field->isEmpty(my_place.getX() - 1, my_place.getY())) this->direction = 'u';
                else chooseRandomDirection();
            }
            if ((target.getX() > my_place.getX()) && (target.getY() < my_place.getY())) {
                if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) this->direction = 'l';
                else if (field->isEmpty(my_place.getX() + 1, my_place.getY())) this->direction = 'd';
                else chooseRandomDirection();
            }
            if ((target.getX() > my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) this->direction = 'd';
                else if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) this->direction = 'r';
                else chooseRandomDirection();
            }
        }
    }
    else chooseRandomDirection();

}

void Predator::findPrey()
{
    double dist = 0;
    for (std::vector<Prey*>::const_iterator it = this->units_struct->preys.begin();
         it != this->units_struct->preys.end(); it++) {
         dist = this->my_place - (*it)->my_place;
         if (dist < 1.5) this->target = (*it)->my_place;
    }

}

void Predator::killPrey(Point targ)
{
    unsigned int vec_size = this->units_struct->preys.size();
    for (std::vector<Prey*>::iterator i = this->units_struct->preys.begin();
       i != this->units_struct->preys.end(); i++) {
        if ((*i)->my_place == targ) {
            if (vec_size != 1) {
                delete *i;
                std::swap(*i, units_struct->preys[vec_size]);
                this->units_struct->preys.pop_back();
            }
            else {
                delete *i;
                this->units_struct->preys.pop_back();
            }
            break;
        }
    }

    if (targ.getX() < my_place.getX()) direction = 'u';
    else if (targ.getX() > my_place.getX()) direction = 'd';
    else if (targ.getY() < my_place.getY()) direction = 'l';
    else if (targ.getY() > my_place.getY()) direction = 'r';

    this->go(direction);
    this->field->setPosition(my_place.getX(), my_place.getY(), 'X');
    didMove = 1;

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
        Predator *pred = new Predator(my_place.getX() - 1, my_place.getY(), this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'r': {
        Predator *pred = new Predator(my_place.getX(), my_place.getY() + 1, this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'd': {
        Predator *pred = new Predator(my_place.getX() + 1, my_place.getY(), this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'l': {
        Predator *pred = new Predator(my_place.getX(), my_place.getY() - 1, this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
    }
    }

    chooseRandomDirection();
    this->energy = 0;

}

Predator::Predator(const int a, const int b, Field *ptrF)
{
    my_place.setX(a);
    my_place.setY(b);
    target.setX(-1);
    target.setY(-1);
    life_time = 0;
    energy = 0;
    didMove = 0;
    field = ptrF;
    field->setPosition(this->my_place.getX(), this->my_place.getY(), 'X');
    direction = 'u';

}

void Predator::setPtrs(Units* ptrU)
{
    units_struct = ptrU;
}

void Predator::movePredator()
{
    srand(time(0));
    this->findPrey();
    this->field->setPosition(this->my_place.getX(), this->my_place.getY(), '.');
    this->directionfinding();
    if (!didMove) {
        this->go(direction);
        this->field->setPosition(this->my_place.getX(), this->my_place.getY(), 'X');
    }
    else didMove = 0;

}
