#include "predator.h"
#include "coordinates.h"
#include "units.h"
#include "constants.h"
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
            if (target->place.getI() < place.getI()) direction = 'u';
            else if (target->place.getI() > place.getI()) direction = 'd';
            else if (target->place.getJ() < place.getJ()) direction = 'l';
            else if (target->place.getJ() > place.getJ()) direction = 'r';
            this->killPrey();
        }
        else {
            //todo выделить метод, которому можно передовать направления, и вызывать его с ранзынми парметрами
            if ((target->place.getI() < place.getI()) && (target->place.getJ() < place.getJ())) {
                if (field->isEmpty(place.getI() - 1, place.getJ())) this->direction = 'u';
                else if (field->isEmpty(place.getI(), place.getJ() - 1)) this->direction = 'l';
                     else chooseRandomDirection();
            }
            if ((target->place.getI() < place.getI()) && (target->place.getJ() > place.getJ())) {
                if (field->isEmpty(place.getI(), place.getJ() + 1)) this->direction = 'r';
                else if (field->isEmpty(place.getI() - 1, place.getJ())) this->direction = 'u';
                     else chooseRandomDirection();
            }
            if ((target->place.getI() > place.getI()) && (target->place.getJ() < place.getJ())) {
                if (field->isEmpty(place.getI(), place.getJ() - 1)) this->direction = 'l';
                else if (field->isEmpty(place.getI() + 1, place.getJ())) this->direction = 'd';
                     else chooseRandomDirection();
            }
            if ((target->place.getI() > place.getI()) && (target->place.getJ() > place.getJ())) {
                if (field->isEmpty(place.getI() + 1, place.getJ())) this->direction = 'd';
                else if (field->isEmpty(place.getI(), place.getJ() + 1)) this->direction = 'r';
                     else chooseRandomDirection();
            }
            //todo выделить метод
            //Простыня какая-то! Простите, эмоции...
            if (this->place.getI() - this->target->place.getI() == 2 &&
                    this->place.getJ() == this->target->place.getJ()) {
                if (this->field->isEmpty(this->place.getI() - 1, this->place.getJ())) direction = 'u';
                    else chooseRandomDirection();
            }
            if (this->place.getI() - this->target->place.getI() == -2 &&
                    this->place.getJ() == this->target->place.getJ()) {
                if (this->field->isEmpty(this->place.getI() + 1, this->place.getJ())) direction = 'd';
                    else chooseRandomDirection();
            }
            if (this->place.getJ() - this->target->place.getJ() == 2 &&
                    this->place.getI() == this->target->place.getI()) {
                if (this->field->isEmpty(this->place.getI(), this->place.getJ() - 1)) direction = 'l';
                else chooseRandomDirection();
            }

            if (this->place.getJ() - this->target->place.getJ() == -2 &&
                    this->place.getI() == this->target->place.getI()) {
                if (this->field->isEmpty(this->place.getI(), this->place.getJ() + 1)) direction = 'r';
                else chooseRandomDirection();
            }
        }
    }
}

void Predator::findPrey()
{   //todo убрать сравнение, тут и так bool
    if (this->target != NULL && (this->target->died == true ||
           this->target->place - this->place > 2.1)) this->target = NULL;
    
    double dist = 0;
    for (std::vector<Prey*>::const_iterator it = this->units_struct->preys.begin();
      it != this->units_struct->preys.end(); ++it) {
        //todo убрать сравнение, тут и так bool
        if ((*it)->died == false) {
            dist = this->place - (*it)->place;
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
    //todo выделить метод и вызывать его в кейсах
    switch (direction) {
    case 'u': {
        Predator *pred = new Predator(place.getI() - 1, place.getJ(), this->field, this->max_life_time);
        pred->setUnitsPointer(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'r': {
        Predator *pred = new Predator(place.getI(), place.getJ() + 1, this->field, this->max_life_time);
        pred->setUnitsPointer(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'd': {
        Predator *pred = new Predator(place.getI() + 1, place.getJ(), this->field, this->max_life_time);
        pred->setUnitsPointer(this->units_struct);
        units_struct->predators.push_back(pred);
        break;
    }
    case 'l': {
        Predator *pred = new Predator(place.getI(), place.getJ() - 1, this->field, this->max_life_time);
        pred->setUnitsPointer(this->units_struct);
        units_struct->predators.push_back(pred);
    }
    }

    this->energy = 0;

}

Predator::Predator(int a, int b, Field *field_pointer, int time_of_life)
{
    place.setI(a);
    place.setJ(b);
    target = NULL;
    max_life_time = time_of_life;
    life_time = 0;
    energy = 0;
    has_moved = 0;
    died = false;
    field = field_pointer;
    field->setChar(this->place.getI(), this->place.getJ(), 'X');
    direction = 'u';

}

void Predator::setUnitsPointer(Units* units_pointer)
{
    units_struct = units_pointer;
}

//todo вместо обозначений символоами можно тоже попробовать enum
void Predator::movePredator()
{
    this->findPrey();
    this->directionFinding();
    if (!has_moved) {
        this->field->setChar(this->place.getI(), this->place.getJ(), '.');
        this->go();
        this->field->setChar(this->place.getI(), this->place.getJ(), 'X');
    }
    else has_moved = 0;
    if (this->energy == PREDATOR_CREATE_ENERGY) this->createPredator();

    life_time++;
    if (life_time == max_life_time) {
        this->field->setChar(this->place.getI(), this->place.getJ(), '.');
        this->died = true;
    }
}
