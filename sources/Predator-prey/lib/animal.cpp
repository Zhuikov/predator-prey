#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection()
{
    //TODO: dir --> direction
    int dir;
    //TODO: когда этот вызов будет возвращать enum direction, весь switch можно будет удалить
    dir = this->field->whatIsEmpty(place.getI(), place.getJ());
    switch (dir) {
        case 0: { direction = UP;    break; }
        case 1: { direction = RIGHT; break; }
        case 2: { direction = DOWN;  break; }
        case 3: { direction = LEFT;  break; }
        default: { has_moved = true; }
    }
}

bool Animal::setDirection(Direction direction)
{
    switch (direction)
    {
        case UP: {
            if (field->isEmpty(place.getI() - 1, place.getJ())) {
                this->direction = UP;
                return true;
            }
        }
        case DOWN: {
            if (field->isEmpty(place.getI() + 1, place.getJ())) {
                this->direction = DOWN;
                return true;
            }
        }
        case LEFT: {
            if (field->isEmpty(place.getI(), place.getJ() - 1)) {
                this->direction = LEFT;
                return true;
            }
        }
        case RIGHT: {
            if (field->isEmpty(place.getI(), place.getJ() + 1)) {
                this->direction = RIGHT;
                return true;
            }
        }
    }
    return false;
}

void Animal::chooseRandomDirection()
{
    //TODO: srand
    int flag = rand() % 4;
    //TODO: будет понятнее, если в case тоже использовать enum
    switch (flag) {
        case 0: {
            if (setDirection(UP) == false) chooseEmptyDirection();
            break;
        }
        case 1: {
            if (setDirection(RIGHT) == false) chooseEmptyDirection();
            break;
        }
        case 2: {
            if (setDirection(LEFT) == false) chooseEmptyDirection();
            break;
        }
        case 3: {
            if (setDirection(DOWN) == false) chooseEmptyDirection();
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
