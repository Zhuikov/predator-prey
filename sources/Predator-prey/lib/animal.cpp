#include "animal.h"
#include <ctime>
#include <cstdlib>

//todo char - не очень, лучше enum
/*
enum Direction
 {
    UP, DOWN, LEFT, RIGHT
 }
 */

void Animal::chooseRandomDirection()
{
    char dir;
    int flag = rand() % 4;
    switch (flag) {
        //todo выделить в отдельный метод
        case 0: {
            if (field->isEmpty(my_place.getI() - 1, my_place.getJ())) direction = 'u'; //direction = UP;
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else has_moved = 1;
                }
            break;
        }
        case 1: {
            if (field->isEmpty(my_place.getI(), my_place.getJ() + 1)) direction = 'r'; //direction = RIGHT;
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else has_moved = 1;
                }
            break;
        }
        case 2: {
            if (field->isEmpty(my_place.getI(), my_place.getJ() - 1)) direction = 'l';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else has_moved = 1;
                }
            break;
        }
        case 3: {
            if (field->isEmpty(my_place.getI() + 1, my_place.getJ())) direction = 'd';
                else {
                    dir = this->field->whatIsEmpty(my_place.getI(), my_place.getJ());
                    if (dir != '0') direction = dir;
                    else has_moved = 1;
                }
            break;
        }
    }
}

void Animal::go(const char) //const Direction
{
    switch (this->direction) {
      //case UP:
        case 'u': { this->my_place.setI(this->my_place.getI() - 1); break; }
        case 'r': { this->my_place.setJ(this->my_place.getJ() + 1); break; }
        case 'l': { this->my_place.setJ(this->my_place.getJ() - 1); break; }
        case 'd': { this->my_place.setI(this->my_place.getI() + 1); break; }
    }
}
