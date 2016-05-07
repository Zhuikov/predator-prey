#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection() noexcept
{
    direction = field->whatIsEmpty(place.getV(), place.getH());
    if (direction == Direction::NO_DIRECTION) {
        has_moved = true;
        direction = Direction::UP;
    }
}

bool Animal::setDirection(Direction direction) noexcept
{
    switch (direction)
    {
        case Direction::UP: {
            if (field->isEmpty(place.getV() - 1, place.getH())) {
                this->direction = Direction::UP;
                return true;
            }
        }
        case Direction::DOWN: {
            if (field->isEmpty(place.getV() + 1, place.getH())) {
                this->direction = Direction::DOWN;
                return true;
            }
        }
        case Direction::LEFT: {
            if (field->isEmpty(place.getV(), place.getH() - 1)) {
                this->direction = Direction::LEFT;
                return true;
            }
        }
        case Direction::RIGHT: {
            if (field->isEmpty(place.getV(), place.getH() + 1)) {
                this->direction = Direction::RIGHT;
                return true;
            }
        }
        default: {}
    }
    return false;
}

void Animal::chooseRandomDirection() noexcept
{
    int flag = rand() % 4;
    //TODO: будет понятнее, если в case тоже использовать enum
    switch (flag) {
        case 0: {
            if (setDirection(Direction::UP) == false)
                chooseEmptyDirection();
            break;
        }
        case 1: {
            if (setDirection(Direction::RIGHT) == false)
                chooseEmptyDirection();
            break;
        }
        case 2: {
            if (setDirection(Direction::LEFT) == false)
                chooseEmptyDirection();
            break;
        }
        case 3: {
            if (setDirection(Direction::DOWN) == false)
                chooseEmptyDirection();
            break;
        }
    }
}

void Animal::go() noexcept
{
    switch (direction) {
        case Direction::UP:    { place.setV(place.getV() - 1); break; }
        case Direction::RIGHT: { place.setH(place.getH() + 1); break; }
        case Direction::LEFT:  { place.setH(place.getH() - 1); break; }
        case Direction::DOWN:  { place.setV(place.getV() + 1); break; }
        default: {}
    }
}
