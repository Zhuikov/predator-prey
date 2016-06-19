#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::killTarget() noexcept
{
    target->exist = false;

    energy ++;
    life_time = -1;
    target = nullptr;
}

void Animal::findTarget() noexcept
{
    //std::list< std::pair< Unit*, double > > targets;
    //targets = sense.getTargets(movement.getCurrent());
    target = brain->getTarget(sense.getTargets(movement.getCurrent()));
}

void Animal::createChildren()
{
    int vertical = movement.getCurrent().getV() + std::rand() % 3 - 1;
    int horizontal = movement.getCurrent().getH() + std::rand() % 3 - 1;

    if (field->isEmpty(vertical, horizontal)) {
        setChildren(vertical, horizontal);
    }
    else {
        bool FLAG = false;
        for (int i = movement.getCurrent().getV() - 1; i <= movement.getCurrent().getV() + 1; i++) {
            for (int j = movement.getCurrent().getH() - 1; j <= movement.getCurrent().getH() + 1; j++) {
                if (field->isEmpty(i, j)) {
                    setChildren(i, j);
                    FLAG = true;
                    break;
                }
            }
            if (FLAG == true) break;
        }
    }

    this->energy = 0;
}

Coordinates Animal::getPlace()
{
    return movement.getCurrent();
}

void Animal::move() noexcept
{

    if (target == nullptr || target->exist == false) {
        findTarget();
    }

    if (target == nullptr) {
        movement.setRandomTarget();
    }
    else {
        movement.setTarget(target->getPlace());
    }

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
    movement.move();

    if (target != nullptr && movement.getCurrent() == target->getPlace()) {
        killTarget();
    }

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);

    if (energy == CREATE_ENERGY) {
        createChildren();
    }

    life_time++;
    if (life_time == max_life_time) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        exist = false;
    }
}

Animal::Animal(const int v, const int h, Field *field_pointer)
{
    energy = 0;
    life_time = 0;
    has_moved = false;
    target = nullptr;
    field = field_pointer;
    movement = Movement(Coordinates(v, h), field);
    sense = Sense(field);
    exist = true;
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
}
