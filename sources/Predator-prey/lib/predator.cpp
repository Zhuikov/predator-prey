#include "predator.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

void Predator::createPredator() noexcept
{
    int vertical = movement.getCurrent().getV() + std::rand() % 3 - 1;
    int horizontal = movement.getCurrent().getH() + std::rand() % 3 - 1;

    if (field->isEmpty(vertical, horizontal)) {
        new Predator(vertical, horizontal, field, units_struct, max_life_time);
    }
    else {
        bool FLAG = false;
        for (int i = movement.getCurrent().getV() - 1; i <= movement.getCurrent().getV() + 1; i++) {
            for (int j = movement.getCurrent().getH() - 1; j <= movement.getCurrent().getH() + 1; j++) {
                if (field->isEmpty(i, j)) {
                    new Predator(i, j, field, units_struct, max_life_time);
                    FLAG = true;
                    break;
                }
            }
            if (FLAG == true) break;
        }
    }

    this->energy = 0;

}

Predator::Predator(int v, int h, Field *field_pointer, Units *units_pointer, int time_of_life) noexcept:
    Animal(v, h, field_pointer),
    units_struct(units_pointer)
{
    max_life_time = time_of_life;
    units_pointer->predators.push_back(this);
    type = UnitType::PREDATOR;
    brain = new PredatorsBrain();
}


void Predator::move() noexcept
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

    if (energy == PREDATOR_CREATE_ENERGY) {
        createPredator();
    }

    life_time++;
    if (life_time == max_life_time) {
        field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
        exist = false;
    }
}
