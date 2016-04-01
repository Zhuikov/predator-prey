#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseRandomDirection()
{
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

void Animal::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setY(this->my_place.getY() - 1); break; }
        case 'r': { this->my_place.setX(this->my_place.getX() + 1); break; }
        case 'l': { this->my_place.setX(this->my_place.getX() - 1); break; }
        case 'd': { this->my_place.setY(this->my_place.getY() + 1); break; }
    }
}
