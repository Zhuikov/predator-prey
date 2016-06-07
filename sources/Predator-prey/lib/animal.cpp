#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::chooseEmptyDirection() noexcept
{
    direction = field->whatIsEmpty(movement.getCurrent().getV(), movement.getCurrent().getH());
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
            if (field->isEmpty(movement.getCurrent().getV() - 1, movement.getCurrent().getH())) {
                this->direction = Direction::UP;
                return true;
            }
        }
        case Direction::DOWN: {
            if (field->isEmpty(movement.getCurrent().getV() + 1, movement.getCurrent().getH())) {
                this->direction = Direction::DOWN;
                return true;
            }
        }
        case Direction::LEFT: {
            if (field->isEmpty(movement.getCurrent().getV(), movement.getCurrent().getH() - 1)) {
                this->direction = Direction::LEFT;
                return true;
            }
        }
        case Direction::RIGHT: {
            if (field->isEmpty(movement.getCurrent().getV(), movement.getCurrent().getH() + 1)) {
                this->direction = Direction::RIGHT;
                return true;
            }
        }
        default: {}
    }
    return false;
}

void Animal::killTarget() noexcept
{
    if (target->getPlace().getV() < movement.getCurrent().getV()) direction = Direction::UP;
    else if (target->getPlace().getV() > movement.getCurrent().getV()) direction = Direction::DOWN;
    else if (target->getPlace().getH() < movement.getCurrent().getH()) direction = Direction::LEFT;
    else if (target->getPlace().getH() > movement.getCurrent().getH()) direction = Direction::RIGHT;

    target->exist = false;

    energy ++;
    life_time = -1;
    target = nullptr;

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
    movement.setTarget2(direction);
    movement.move();
}
