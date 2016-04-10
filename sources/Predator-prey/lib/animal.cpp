#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseRandomDirection()
{
    srand(time(0));
    char dir;
    int flag = rand() % 4;
    switch (flag) {
        case 0: {
            if (field->isEmpty(my_place.getX() - 1, my_place.getY())) direction = 'u';
                else {
                    dir = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                    if (dir != '0') direction = dir;
                    else didMove = 1;
            }
            break;
        }
        case 1: {
            if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) direction = 'r';
                else {
                    dir = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                    if (dir != '0') direction = dir;
                    else didMove = 1;
            }
            break;
        }
        case 2: {
            if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) direction = 'l';
                else {
                    dir = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                    if (dir != '0') direction = dir;
                    else didMove = 1;
            }
            break;
        }
        case 3: {
            if (field->isEmpty(my_place.getX() + 1, my_place.getY())) direction = 'd';
                else {
                    dir = this->field->whatIsEmpty(my_place.getX(), my_place.getY());
                    if (dir != '0') direction = dir;
                    else didMove = 1;
            }
            break;
        }
    }
}

void Animal::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setX(this->my_place.getX() - 1); break; }
        case 'r': { this->my_place.setY(this->my_place.getY() + 1); break; }
        case 'l': { this->my_place.setY(this->my_place.getY() - 1); break; }
        case 'd': { this->my_place.setX(this->my_place.getX() + 1); break; }
    }
    this->didMove = 1;
}
