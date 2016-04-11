#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseRandomDirection()
{
    //srand(time(0));
    char dir;
    int flag = rand() % 4;
    switch (flag) {
        case 0: {
            if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) direction = 'u';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else have_direction = 1;
            }
            break;
        }
        case 1: {
            if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) direction = 'r';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else have_direction = 1;
            }
            break;
        }
        case 2: {
            if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) direction = 'l';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else have_direction = 1;
            }
            break;
        }
        case 3: {
            if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) direction = 'd';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else have_direction = 1;
            }
            break;
        }
    }
}

void Animal::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setI(this->my_place.getI() - 1); break; }
        case 'r': { this->my_place.setJ(this->my_place.getJ() + 1); break; }
        case 'l': { this->my_place.setJ(this->my_place.getJ() - 1); break; }
        case 'd': { this->my_place.setI(this->my_place.getI() + 1); break; }
    }
    this->have_direction = 1;
}
