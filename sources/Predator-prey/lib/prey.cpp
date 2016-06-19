#include "prey.h"
#include <ctime>
#include <cstdlib>

void Prey::createChildren() noexcept
{
    // todo сделать это
    this->energy = 0;
}

Prey::Prey(const int v, const int h, Field* field_pointer, Units *units_pointer):
    Animal(v, h, field_pointer),
    warning(false),
    units_struct(units_pointer)
{
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);

    units_struct->preys.push_back(this);
    type = UnitType::PREY;

    CREATE_ENERGY = PREY_CREATE_ENERGY;

    brain = new PreysBrain();
}

