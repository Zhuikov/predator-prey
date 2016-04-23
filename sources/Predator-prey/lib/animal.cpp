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

void Animal::chooseEmptyDirection()
{
    char dir;
    dir = this->field->whatIsEmpty(place.getI(), place.getJ());
    if (dir != '0') direction = dir;
    else has_moved = 1;

}

void Animal::chooseRandomDirection()
{
    int flag = rand() % 4;
    switch (flag) {
        case 0: {
            if (field->isEmpty(place.getI() - 1, place.getJ())) direction = 'u'; //direction = UP;
                else chooseEmptyDirection();
            break;
        }
        case 1: {
            if (field->isEmpty(place.getI(), place.getJ() + 1)) direction = 'r'; //direction = RIGHT;
                else chooseEmptyDirection();
            break;
        }
        case 2: {
            if (field->isEmpty(place.getI(), place.getJ() - 1)) direction = 'l';
                else chooseEmptyDirection();
            break;
        }
        case 3: {
            if (field->isEmpty(place.getI() + 1, place.getJ())) direction = 'd';
                else chooseEmptyDirection();
            break;
        }
    }
}

void Animal::go()
{
    switch (this->direction) {
      //case UP:
        case 'u': { this->place.setI(this->place.getI() - 1); break; }
        case 'r': { this->place.setJ(this->place.getJ() + 1); break; }
        case 'l': { this->place.setJ(this->place.getJ() - 1); break; }
        case 'd': { this->place.setI(this->place.getI() + 1); break; }
    }
}
