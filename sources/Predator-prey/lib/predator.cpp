#include "predator.h"
#include "coordinates.h"
#include "units.h"
#include "constants.h"
#include <vector>
#include <ctime>
#include <cstdlib>

void Predator::directionfinding()
{
    if (this->target == NULL || this->target->my_place - this->my_place > 2.1) {
        chooseRandomDirection();
        this->target = NULL;
    }
    else {
        double dist;
        dist = this->my_place - this->target->my_place;
        if ((dist > 0.9) && (dist < 1.1)) {
            if (target->my_place.getI() < my_place.getI()) direction = 'u';
            else if (target->my_place.getI() > my_place.getI()) direction = 'd';
            else if (target->my_place.getJ() < my_place.getJ()) direction = 'l';
            else if (target->my_place.getJ() > my_place.getJ()) direction = 'r';
            this->killPrey();
        }
        else {
            if ((target->my_place.getI() < my_place.getI()) && (target->my_place.getJ() < my_place.getJ())) {
                if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) this->direction = 'u';
                else if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) this->direction = 'l';
                     else chooseRandomDirection();
            }
            if ((target->my_place.getI() < my_place.getI()) && (target->my_place.getJ() > my_place.getJ())) {
                if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) this->direction = 'r';
                else if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) this->direction = 'u';
                     else chooseRandomDirection();
            }
            if ((target->my_place.getI() > my_place.getI()) && (target->my_place.getJ() < my_place.getJ())) {
                if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) this->direction = 'l';
                else if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) this->direction = 'd';
                     else chooseRandomDirection();
            }
            if ((target->my_place.getI() > my_place.getI()) && (target->my_place.getJ() > my_place.getJ())) {
                if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) this->direction = 'd';
                else if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) this->direction = 'r';
                     else chooseRandomDirection();
            }

            if (this->my_place.getI() - this->target->my_place.getI() == 2 &&
                    this->my_place.getJ() == this->target->my_place.getJ()) {
                if (this->field->isEmpty(this->my_place.getI() - 1, this->my_place.getJ())) direction = 'u';
                    else chooseRandomDirection();
            }
            if (this->my_place.getI() - this->target->my_place.getI() == -2 &&
                    this->my_place.getJ() == this->target->my_place.getJ()) {
                if (this->field->isEmpty(this->my_place.getI() + 1, this->my_place.getJ())) direction = 'd';
                    else chooseRandomDirection();
            }
            if (this->my_place.getJ() - this->target->my_place.getJ() == 2 &&
                    this->my_place.getI() == this->target->my_place.getI()) {
                if (this->field->isEmpty(this->my_place.getI(), this->my_place.getJ() - 1)) direction = 'l';
                else chooseRandomDirection();
            }

            if (this->my_place.getJ() - this->target->my_place.getJ() == -2 &&
                    this->my_place.getI() == this->target->my_place.getI()) {
                if (this->field->isEmpty(this->my_place.getI(), this->my_place.getJ() + 1)) direction = 'r';
                else chooseRandomDirection();
            }
        }
    }
}

void Predator::findPrey()
{
    double dist = 0;
    if (!this->units_struct->preys.empty()) {
        for (std::vector<Prey*>::const_iterator it = this->units_struct->preys.begin();
            it != this->units_struct->preys.end(); ++it) {
            dist = this->my_place - (*it)->my_place;
            if (dist < 1.5) this->target = (*it);
        }
    }
    else this->target = NULL;

}

void Predator::killPrey()
{
    if (this->field->getChar(this->target->my_place.getI(), this->target->my_place.getJ()) == 'O') {
        unsigned int vec_size = this->units_struct->preys.size();
        for (std::vector<Prey*>::iterator i = this->units_struct->preys.begin();
            i != this->units_struct->preys.end(); ++i) {
                if ((*i) == this->target) {
                    if (vec_size != 1) {
                        delete *i;
                        std::swap(*i, units_struct->preys.back());
                        this->units_struct->preys.pop_back();
                    }
                    else {
                        delete *i;
                        this->units_struct->preys.pop_back();
                        }
                    break;
                }
            }

        energy++;
        life_time = -1;
    }
    else chooseRandomDirection();

    target = NULL;

}

void Predator::createPredator()
{
    chooseRandomDirection();
    switch (direction) {
    case 'u': {
        Predator *pred = new Predator(my_place.getI() - 1, my_place.getJ(), this->field, this->max_life_time);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'r': {
        Predator *pred = new Predator(my_place.getI(), my_place.getJ() + 1, this->field, this->max_life_time);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'd': {
        Predator *pred = new Predator(my_place.getI() + 1, my_place.getJ(), this->field, this->max_life_time);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'l': {
        Predator *pred = new Predator(my_place.getI(), my_place.getJ() - 1, this->field, this->max_life_time);
        pred->setPtrs(this->units_struct);
        units_struct->predators.push_back(pred);
    }
    }

    this->energy = 0;

}

void Predator::killHungryPredator()
{
    unsigned int vec_size = this->units_struct->predators.size();
    for (std::vector<Predator*>::iterator it = this->units_struct->predators.begin();
         it != this->units_struct->predators.end(); ++it)
        if ((*it)->my_place == this->my_place) {
            if (vec_size != 1) std::swap(*it, this->units_struct->predators.back());
            this->units_struct->predators.pop_back();
            delete this;
            break;
        }
}

Predator::Predator(int a, int b, Field *ptrF, int time_of_life)
{
    my_place.setI(a);
    my_place.setJ(b);
    target = NULL;
    max_life_time = time_of_life;
    life_time = 0;
    energy = 0;
    has_moved = 0;
    did_move = false;
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
    this->findPrey();
    this->directionfinding();
    if (!has_moved) {
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), '.');
        this->go(direction);
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), 'X');
    }
    else has_moved = 0;
    if (this->energy == PREDATOR_CREATE_ENERGY) this->createPredator();

    life_time++;
    did_move = true;
    if (life_time == max_life_time) {
        this->field->setPosition(this->my_place.getI(), this->my_place.getJ(), '.');
        this->killHungryPredator();
    }
}
