#include "predator.h"
#include "point.h"
#include "prey.h"
#include "units.h"
#include <ctime>
#include <cstdlib>
#include <vector>

void Predator::directionfinding()
{
    if (this->target.getX() != -1) {
        double dist;
        dist = this->my_place - this->target;
        if ((dist > 0.9) && (dist < 1.1)) {
      //      this->killPrey(target);
        }
        else {
               //////////////////////////////////////////////
        }
    }

}

void Predator::findPrey()
{
    double dist = 0;
    for (unsigned int i = 0; i < this->units_struct->preys.size(); i++){
        dist = this->my_place - this->units_struct->preys[i].my_place;
        if (dist <= 1.5) { this->target = this->units_struct->preys[i].my_place; }
    }

}

Predator::Predator(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    field->setPosition(a, b, 'X');
    target.setX(-1);
    target.setY(-1);
    life_time = 0;

    srand(time(0));
    int flag = rand() % 4;
    switch (flag) {
        case 0: { direction = 'u'; break; }
        case 1: { direction = 'r'; break; }
        case 2: { direction = 'l'; break; }
        case 3: { direction = 'd'; break; }
    }    
}

void Predator::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setY(this->my_place.getY() - 1); break; }
        case 'r': { this->my_place.setX(this->my_place.getX() + 1); break; }
        case 'l': { this->my_place.setX(this->my_place.getX() - 1); break; }
        case 'd': { this->my_place.setY(this->my_place.getY() + 1); break; }
    }
}

void Predator::setPtrs(Units* ptrU, Field* ptrF)
{
    this->units_struct = ptrU;
    this->field = ptrF;
}

