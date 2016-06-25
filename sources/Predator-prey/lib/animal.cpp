#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::killTarget() noexcept
{
    target->exist = false;
    //здесь спросим у жертвы возраст
    brain->eat(420);
    energy ++;
    life_time = -1;
    target = nullptr;
}

void Animal::findTarget() noexcept
{
    movement.setSpeed(brain->getMaxAvailableSpeed());
    target = brain->getTarget(sense.getTargets(movement.getCurrent()));
}

void Animal::createChild()
{
    int vertical = movement.getCurrent().getV() + std::rand() % 3 - 1;
    int horizontal = movement.getCurrent().getH() + std::rand() % 3 - 1;

    if (field->isEmpty(vertical, horizontal)) {
        setChild(vertical, horizontal);
    }
    else {
        bool FLAG = false;
        for (int i = movement.getCurrent().getV() - 1; i <= movement.getCurrent().getV() + 1; i++) {
            for (int j = movement.getCurrent().getH() - 1; j <= movement.getCurrent().getH() + 1; j++) {
                if (field->isEmpty(i, j)) {
                    setChild(i, j);
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
    brain->update(life_time);

    sense.setRadius(2 * brain->getMaxSpeed());

    findTarget();

    if (target == nullptr) {
        movement.setRandomTarget();
        movement.setSpeed(brain->getComfortableSpeed());
    }
    else {
        Coordinates targetCoords = target->getPlace();
        movement.setTarget(targetCoords);
    }

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
    if (brain->isRuningAway)
    {
        brain->move(movement.moveApart());
    }
    else
    {
        brain->move(movement.move());
    }
    if (target != nullptr && movement.getCurrent() == target->getPlace()) {
        killTarget();
    }

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);

    if (energy == CREATE_ENERGY) {
        createChild();
    }

    life_time++;
    if (life_time == max_life_time || brain->getEnergy() <= 0) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        exist = false;
        if (type == UnitType::PREDATOR)
        {
            units_struct->predatorsNum--;
        }
        if (type == UnitType::PREY)
        {
            units_struct->preysNum--;
        }
    }
}

Animal::Animal(const int v, const int h, Field* field_pointer, Units *units_pointer, int TTL) :
    max_life_time(TTL),
    units_struct(units_pointer)
{
    energy = 0;
    life_time = 0;
    target = nullptr;
    field = field_pointer;
    movement = Movement(Coordinates(v, h), field);
    sense = Sense(field);
    exist = true;
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);
}
