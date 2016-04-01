#include "predator.h"
#include "point.h"
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
            this->killPrey(target);
        }
        else {
            if ((target.getX() < my_place.getX()) && (target.getY() < my_place.getY())) {
                if (field->isEmpty(my_place.getX() - 1, my_place.getY())) { this->direction = 'l'; }
                else { this->direction = 'u'; }
            }
            if ((target.getX() < my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX() - 1, my_place.getY())) { this->direction = 'l'; }
                else { this->direction = 'd'; }
            }
            if ((target.getX() > my_place.getX()) && (target.getY() < my_place.getY())) {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) { this->direction = 'r'; }
                else { this->direction = 'u'; }
            }
            if ((target.getX() > my_place.getX()) && (target.getY() > my_place.getY())) {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) { this->direction = 'r'; }
                else { this->direction = 'd'; }
            }
        }
    }
    else {
        srand(time(0));
        int flag = rand() % 4;
        switch (flag) {
            case 0: {
                if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) direction = 'u';
                    else direction = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                break;
            }
            case 1: {
                if (field->isEmpty(my_place.getX() + 1, my_place.getY())) direction = 'r';
                    else direction = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                break;
            }
            case 2: {
                if (field->isEmpty(my_place.getX() - 1, my_place.getY())) direction = 'l';
                    else direction = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                break;
            }
            case 3: {
                if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) direction = 'd';
                    else direction = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                break;
            }
        }
    }

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

