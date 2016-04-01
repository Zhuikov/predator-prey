#include "prey.h"
#include "units.h"

Prey::Prey(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    energy = 0;
    field->setPosition(a, b, 'O');
    life_time = 0;
    for (unsigned int i = 0; i < units_struct->predators.size(); i++) {
        if (this->my_place - units_struct->predators[i].my_place < 1.1) warning = 1;
        ///
    }

    chooseRandomDirection();
}
