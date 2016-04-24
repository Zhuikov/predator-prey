#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection()
{
    int dir;
    dir = this->field->whatIsEmpty(place.getI(), place.getJ());
    switch (dir) {
        case 0: { direction = UP;    break; }
        case 1: { direction = RIGHT; break; }
        case 2: { direction = DOWN;  break; }
        case 3: { direction = LEFT;  break; }
        default: { has_moved = true; }
    }
}

bool Animal::setRIGHTdirection()
{
    if (field->isEmpty(place.getI(), place.getJ() + 1)) {
        this->direction = RIGHT;
        return true;
    }
    return false;
}

bool Animal::setUPdirection()
{
    if (field->isEmpty(place.getI() - 1, place.getJ())) {
        this->direction = UP;
        return true;
    }
    return false;
}

bool Animal::setDOWNdirection()
{
    if (field->isEmpty(place.getI() + 1, place.getJ())) {
        this->direction = DOWN;
        return true;
    }
    return false;
}

bool Animal::setLEFTdirection()
{
    if (field->isEmpty(place.getI(), place.getJ() - 1)) {
        this->direction = LEFT;
        return true;
    }
    return false;
}

void Animal::chooseRandomDirection()
{
    int flag = rand() % 4;
    switch (flag) {
        case 0: {
            if (setUPdirection() == false) chooseEmptyDirection();
            break;
        }
        case 1: {
            if (setRIGHTdirection() == false) chooseEmptyDirection();
            break;
        }
        case 2: {
            if (setLEFTdirection() == false) chooseEmptyDirection();
            break;
        }
        case 3: {
            if (setDOWNdirection() == false) chooseEmptyDirection();
            break;
        }
    }
}

void Animal::go()
{
    switch (this->direction) {
        case UP:    { this->place.setI(this->place.getI() - 1); break; }
        case RIGHT: { this->place.setJ(this->place.getJ() + 1); break; }
        case LEFT:  { this->place.setJ(this->place.getJ() - 1); break; }
        case DOWN:  { this->place.setI(this->place.getI() + 1); break; }
    }
}
