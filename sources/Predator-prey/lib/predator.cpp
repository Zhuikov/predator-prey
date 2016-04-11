#include "predator.h"
#include "coordinates.h"
#include "units.h"
#include "constants.h"
#include <vector>
#include <ctime>
#include <cstdlib>

void Predator::directionfinding()
{
    if (this->target.getI() != -1) {
        double dist;
        dist = this->my_place - this->target;
        if ((dist > 0.9) && (dist < 1.1)) {
            this->killPrey(target);
        }
        else {
            if ((target.getI() < my_place.getI()) && (target.getJ() < my_place.getJ())) {
                if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) this->direction = 'l';
                else if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) this->direction = 'u';
                else chooseRandomDirection();
            }
            if ((target.getI() < my_place.getI()) && (target.getJ() > my_place.getJ())) {
                if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) this->direction = 'r';
                else if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) this->direction = 'u';
                else chooseRandomDirection();
            }
            if ((target.getI() > my_place.getI()) && (target.getJ() < my_place.getJ())) {
                if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) this->direction = 'l';
                else if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) this->direction = 'd';
                else chooseRandomDirection();
            }
            if ((target.getI() > my_place.getI()) && (target.getJ() > my_place.getJ())) {
                if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) this->direction = 'd';
                else if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) this->direction = 'r';
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

void Predator::killPrey(Coordinates targ)
{
    if (this->field->getChar(this->target.getI(), this->target.getJ()) == 'O') {
        unsigned int vec_size = this->units_struct->preys.size();
        for (std::vector<Prey*>::iterator i = this->units_struct->preys.begin();
            i != this->units_struct->preys.end(); i++) {
                if ((*i)->my_place == targ) {
                    if (vec_size != 1) {
                    delete *i;
                    std::swap(*i, units_struct->preys[vec_size - 1]);
                    this->units_struct->preys.pop_back();
                }
                else {
                    delete *i;
                    this->units_struct->preys.pop_back();
                }
                break;
            }
        }
        if (targ.getI() < my_place.getI()) direction = 'u';
        else if (targ.getI() > my_place.getI()) direction = 'd';
        else if (targ.getJ() < my_place.getJ()) direction = 'l';
        else if (targ.getJ() > my_place.getJ()) direction = 'r';

        have_direction = 1;
        energy++;
    }
    else chooseRandomDirection();

    target.setI(-1);
    target.setJ(-1);

}

void Predator::createPredator()
{
    chooseRandomDirection();
    switch (direction) {
    case 'u': {
        Predator *pred = new Predator(my_place.getI() - 1, my_place.getJ(), this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'r': {
        Predator *pred = new Predator(my_place.getI(), my_place.getJ() + 1, this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'd': {
        Predator *pred = new Predator(my_place.getI() + 1, my_place.getJ(), this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'l': {
        Predator *pred = new Predator(my_place.getI(), my_place.getJ() - 1, this->field);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
    }
    }

    chooseRandomDirection();
    this->energy = 0;

}

Predator::Predator(const int a, const int b, Field *ptrF)
{
    my_place.setI(a);
    my_place.setJ(b);
    target.setI(-1);
    target.setJ(-1);
    life_time = 0;
    energy = 0;
    have_direction = 0;
    has_moved = 0;
    field = ptrF;
    field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'X');
    direction = 'u';

}

void Predator::setPtrs(Units* ptrU)
{
    units_struct = ptrU;
}

void Predator::movePredator()
{
    //srand(time(0));
    this->findPrey();
    this->directionfinding();
    if (this->energy == PREDATOR_CREATE_ENERGY) {
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), '.');
        this->go(direction);
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'X');
        this->has_moved = 1;
        this->createPredator();
    }
    if ((!have_direction) || (!has_moved)) {
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), '.');
        this->go(direction);
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'X');
    }
    has_moved = 0;
    have_direction = 0;

}
