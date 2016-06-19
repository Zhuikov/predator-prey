#include "predator.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

void Predator::createChildren() noexcept
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
    CREATE_ENERGY = PREDATOR_CREATE_ENERGY;
    brain = new PredatorsBrain();
}


