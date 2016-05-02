#include "predator.h"
#include "coordinates.h"
#include "units.h"
#include <vector>
#include <ctime>
#include <cstdlib>

void Predator::directionFinding()
{
    if (this->target == NULL){
        chooseRandomDirection();
    }
    else {
        double dist = (this->place) - (this->target->place);
        //TODO: числовые константы это плохо
        //вынести в класс const double DISTANTION = 1.0 (лучше еще уточнить название)
        // const double DELTA = 0.1
        // dist > DISTANTION - DELTA
        if ((dist > 0.9) && (dist < 1.1)) {
            if (target->place.getI() < place.getI()) direction = UP;
            else if (target->place.getI() > place.getI()) direction = DOWN;
            else if (target->place.getJ() < place.getJ()) direction = LEFT;
            else if (target->place.getJ() > place.getJ()) direction = RIGHT;
            this->killPrey();
        }
        else chooseToTargetDirection();
    }
}

void Predator::chooseToTargetDirection()
{
    if ((place.getI() <= target->place.getI()) && (place.getJ() < target->place.getJ())) {
            if (setDirection(RIGHT) == false)
                if (setDirection(DOWN) == false) chooseRandomDirection();
    }
    if ((place.getI() < target->place.getI()) && (place.getJ() >= target->place.getJ())) {
            if (setDirection(DOWN) == false)
                if (setDirection(LEFT) == false) chooseRandomDirection();
    }
    if ((place.getI() > target->place.getI()) && (place.getJ() <= target->place.getJ())) {
            if (setDirection(UP) == false)
                if (setDirection(RIGHT) == false) chooseRandomDirection();
    }
    if ((place.getI() >= target->place.getI()) && (place.getJ() > target->place.getJ())) {
            if (setDirection(LEFT) == false)
                if (setDirection(UP) == false) chooseRandomDirection();
    }
}

//TODO: использовать символьные константы вместо числовых, foreach синтаксис
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

//TODO: foreach синтаксис
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
        spawnPredator(place.getI(), place.getJ() - 1);
    }
    }

    this->energy = 0;

}

//TODO: h v
void Predator::spawnPredator(int a, int b)
{
    //TODO: pred --> predator
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
