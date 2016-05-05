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
        double distance = (this->place) - (this->target->place);
        //TODO: числовые константы это плохо
        //вынести в класс const double DISTANTION = 1.0 (лучше еще уточнить название)
        // const double DELTA = 0.1
        // dist > DISTANTION - DELTA
        if (abs(DISTANCE_FOR_KILL - distance) < DELTA) {
        /// тут магия: если закомментировать предыдущую строчку и раскомментировать следующую, то тесты проходят;
        /// а так, как сейчас - все падает. Хотя написано то же самое
        //if (distance > 0.9 && distance < 1.1) {
            if (target->place.getV() < place.getV()) direction = UP;
            else if (target->place.getV() > place.getV()) direction = DOWN;
            else if (target->place.getH() < place.getH()) direction = LEFT;
            else if (target->place.getH() > place.getH()) direction = RIGHT;
            this->killPrey();
        }
        else chooseToTargetDirection();
    }
}

void Predator::chooseToTargetDirection()
{
    if ((place.getV() <= target->place.getV()) && (place.getH() < target->place.getH())) {
            if (setDirection(RIGHT) == false)
                if (setDirection(DOWN) == false) chooseRandomDirection();
    }
    if ((place.getV() < target->place.getV()) && (place.getH() >= target->place.getH())) {
            if (setDirection(DOWN) == false)
                if (setDirection(LEFT) == false) chooseRandomDirection();
    }
    if ((place.getV() > target->place.getV()) && (place.getH() <= target->place.getH())) {
            if (setDirection(UP) == false)
                if (setDirection(RIGHT) == false) chooseRandomDirection();
    }
    if ((place.getV() >= target->place.getV()) && (place.getH() > target->place.getH())) {
            if (setDirection(LEFT) == false)
                if (setDirection(UP) == false) chooseRandomDirection();
    }
}

//TODO: foreach синтаксис
void Predator::findPrey()
{
    if (this->target != NULL && (this->target->died == true ||
           this->target->place - this->place > DISTANCE_FOR_RESET_TARGET + DELTA)) this->target = NULL;
    
    double distance = 0;
    for (std::vector<Prey*>::const_iterator it = this->units_struct->preys.begin();
      it != this->units_struct->preys.end(); ++it) {
        if ((*it)->died == false) {
            distance = this->place - (*it)->place;
            if (distance < DISTANCE_FOR_KILL + DELTA) {
                this->target = (*it);
                break;
            }
            if (distance < DISTANCE_FOR_TARGET + DELTA) this->target = (*it);
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
        spawnPredator(place.getV() - 1, place.getH());
        break;
    }
    case RIGHT: {
        spawnPredator(place.getV(), place.getH() + 1);
        break;
    }
    case DOWN:  {
        spawnPredator(place.getV() + 1, place.getH());
        break;
    }
    case LEFT:  {
        spawnPredator(place.getV(), place.getH() - 1);
    }
    }

    this->energy = 0;

}

//TODO: h v
void Predator::spawnPredator(int i, int j)
{
    Predator *predator = new Predator(i, j, this->field, this->max_life_time);
    predator->setUnitsPointer(this->units_struct);
    units_struct->predators.push_back(predator);
}

Predator::Predator(int i, int j, Field *field_pointer, int time_of_life)
{
    place.setV(i);
    place.setH(j);
    target = NULL;
    max_life_time = time_of_life;
    life_time = 0;
    energy = 0;
    has_moved = false;
    died = false;
    field = field_pointer;
    field->setPosition(this->place.getV(), this->place.getH(), PREDATOR);
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
        this->field->setPosition(this->place.getV(), this->place.getH(), EMPTY);
        this->go();
        this->field->setPosition(this->place.getV(), this->place.getH(), PREDATOR);
    }
    else has_moved = false;
    if (this->energy == PREDATOR_CREATE_ENERGY) this->createPredator();

    life_time++;
    if (life_time == max_life_time) {
        this->field->setPosition(this->place.getV(), this->place.getH(), EMPTY);
        this->died = true;
    }
}
