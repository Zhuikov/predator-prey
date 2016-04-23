#include "predator.h"
#include "coordinates.h"
#include "units.h"
#include <vector>
#include <ctime>
#include <cstdlib>

void Predator::directionFinding()
{
    if (this->target == NULL) chooseRandomDirection();
    else {
        double dist;
        dist = this->place - this->target->place;
        if ((dist > 0.9) && (dist < 1.1)) {
            if (target->place.getI() < place.getI()) direction = UP;
            else if (target->place.getI() > place.getI()) direction = DOWN;
            else if (target->place.getJ() < place.getJ()) direction = LEFT;
            else if (target->place.getJ() > place.getJ()) direction = RIGHT;
            this->killPrey();
        }
        else {
            //todo выделить метод, которому можно передовать направления, и вызывать его с ранзынми парметрами
            if ((target->place.getI() < place.getI()) && (target->place.getJ() < place.getJ())) {
                if (field->isEmpty(place.getI() - 1, place.getJ())) this->direction = UP;
                else if (field->isEmpty(place.getI(), place.getJ() - 1)) this->direction = LEFT;
                     else chooseRandomDirection();
            }
            if ((target->place.getI() < place.getI()) && (target->place.getJ() > place.getJ())) {
                if (field->isEmpty(place.getI(), place.getJ() + 1)) this->direction = RIGHT;
                else if (field->isEmpty(place.getI() - 1, place.getJ())) this->direction = UP;
                     else chooseRandomDirection();
            }
            if ((target->place.getI() > place.getI()) && (target->place.getJ() < place.getJ())) {
                if (field->isEmpty(place.getI(), place.getJ() - 1)) this->direction = LEFT;
                else if (field->isEmpty(place.getI() + 1, place.getJ())) this->direction = DOWN;
                     else chooseRandomDirection();
            }
            if ((target->place.getI() > place.getI()) && (target->place.getJ() > place.getJ())) {
                if (field->isEmpty(place.getI() + 1, place.getJ())) this->direction = DOWN;
                else if (field->isEmpty(place.getI(), place.getJ() + 1)) this->direction = RIGHT;
                     else chooseRandomDirection();
            }

            if (dist > 1.99 && dist < 2.01) chooseFarDirection();
        }
    }
}

void Predator::chooseFarDirection()
{
    if (this->place.getI() - this->target->place.getI() == 2) {
        if (this->field->isEmpty(this->place.getI() - 1, this->place.getJ())) direction = UP;
            else chooseRandomDirection();
    }
    if (this->place.getI() - this->target->place.getI() == -2) {
        if (this->field->isEmpty(this->place.getI() + 1, this->place.getJ())) direction = DOWN;
            else chooseRandomDirection();
    }
    if (this->place.getJ() - this->target->place.getJ() == 2) {
        if (this->field->isEmpty(this->place.getI(), this->place.getJ() - 1)) direction = LEFT;
            else chooseRandomDirection();
    }
    if (this->place.getJ() - this->target->place.getJ() == -2) {
        if (this->field->isEmpty(this->place.getI(), this->place.getJ() + 1)) direction = RIGHT;
            else chooseRandomDirection();
    }
}

void Predator::findPrey()
{
    if (this->target != NULL && (this->target->died == true ||
           this->target->place - this->place > 2.1)) this->target = NULL;
    
    double dist = 0;
    for (std::vector<Prey*>::const_iterator it = this->units_struct->preys.begin();
      it != this->units_struct->preys.end(); ++it) {
        if ((*it)->died == false) {
            dist = this->place - (*it)->place;
            if (dist < 1.1) {
                this->target = (*it);
                break;
            }
            if (dist < 1.5) this->target = (*it);
        }
    }
}

void Predator::killPrey()
{
    for (std::vector<Prey*>::iterator i = this->units_struct->preys.begin();
        i != this->units_struct->preys.end(); ++i)
            if (*i == this->target) (*i)->died = true;
    
    energy++;
    life_time = -1;

    target = NULL;

}

void Predator::createPredator()
{
    chooseRandomDirection();
    switch (direction) {
    case UP:    {
        spawnPredator(place.getI() - 1, place.getJ());
        break;
    }
    case RIGHT: {
        spawnPredator(place.getI(), place.getJ() + 1);
        break;
    }
    case DOWN:  {
        spawnPredator(place.getI() + 1, place.getJ());
        break;
    }
    case LEFT:  {
        spawnPredator(place.getI() + 1, place.getJ());
    }
    }

    this->energy = 0;

}

void Predator::spawnPredator(int a, int b)
{
    Predator *pred = new Predator(a, b, this->field, this->max_life_time);
    pred->setUnitsPointer(this->units_struct);
    units_struct->predators.push_back(pred);
}

Predator::Predator(int a, int b, Field *field_pointer, int time_of_life)
{
    place.setI(a);
    place.setJ(b);
    target = NULL;
    max_life_time = time_of_life;
    life_time = 0;
    energy = 0;
    has_moved = false;
    died = false;
    field = field_pointer;
    field->setPosition(this->place.getI(), this->place.getJ(), PREDATOR);
    direction = UP;

}

void Predator::setUnitsPointer(Units* units_pointer)
{
    units_struct = units_pointer;
}

void Predator::movePredator()
{
    this->findPrey();
    this->directionFinding();
    if (has_moved == false) {
        this->field->setPosition(this->place.getI(), this->place.getJ(), EMPTY);
        this->go();
        this->field->setPosition(this->place.getI(), this->place.getJ(), PREDATOR);
    }
    else has_moved = false;
    if (this->energy == PREDATOR_CREATE_ENERGY) this->createPredator();

    life_time++;
    if (life_time == max_life_time) {
        this->field->setPosition(this->place.getI(), this->place.getJ(), EMPTY);
        this->died = true;
    }
}
