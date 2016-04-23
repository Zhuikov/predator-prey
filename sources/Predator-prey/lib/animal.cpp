#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection()
{
    int dir;
    dir = this->field->whatIsEmpty(place.getI(), place.getJ());
    switch (dir) {
        case 0: { direction = UP; break; }
        case 1: { direction = RIGHT; break; }
        case 2: { direction = DOWN; break; }
        case 3: { direction = LEFT; break; }
        default: { has_moved = true; }
    }

}

void Animal::chooseRandomDirection()
{
    int flag = rand() % 4;
    switch (flag) {
        case 0: {
            if (field->isEmpty(place.getI() - 1, place.getJ())) direction = UP;
                else chooseEmptyDirection();
            break;
        }
        case 1: {
            if (field->isEmpty(place.getI(), place.getJ() + 1)) direction = RIGHT;
                else chooseEmptyDirection();
            break;
        }
        case 2: {
            if (field->isEmpty(place.getI(), place.getJ() - 1)) direction = LEFT;
                else chooseEmptyDirection();
            break;
        }
        case 3: {
            if (field->isEmpty(place.getI() + 1, place.getJ())) direction = DOWN;
                else chooseEmptyDirection();
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
