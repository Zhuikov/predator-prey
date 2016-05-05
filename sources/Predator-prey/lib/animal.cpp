#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection()
{
    int new_direction;
    //TODO: когда этот вызов будет возвращать enum direction, весь switch можно будет удалить
    new_direction = this->field->whatIsEmpty(place.getV(), place.getH());
    switch (new_direction) {
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
            if (field->isEmpty(place.getV() - 1, place.getH())) {
                this->direction = UP;
                return true;
            }
        }
        case DOWN: {
            if (field->isEmpty(place.getV() + 1, place.getH())) {
                this->direction = DOWN;
                return true;
            }
        }
        case LEFT: {
            if (field->isEmpty(place.getV(), place.getH() - 1)) {
                this->direction = LEFT;
                return true;
            }
        }
        case RIGHT: {
            if (field->isEmpty(place.getV(), place.getH() + 1)) {
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
        case UP:    { this->place.setV(this->place.getV() - 1); break; }
        case RIGHT: { this->place.setH(this->place.getH() + 1); break; }
        case LEFT:  { this->place.setH(this->place.getH() - 1); break; }
        case DOWN:  { this->place.setV(this->place.getV() + 1); break; }
    }
}
