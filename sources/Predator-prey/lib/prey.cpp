#include "prey.h"
#include <ctime>
#include <cstdlib>

void Prey::killTarget() noexcept
{
    Animal::killTarget();
}

Animal *Prey::setChildren(const int v, const int h)
{
    units_struct->preysNum ++;
    return new Prey(v, h, field, units_struct);
}

Prey::Prey(const int v, const int h, Field* field_pointer, Units *units_pointer):
    Animal(v, h, field_pointer),
    units_struct(units_pointer)
{
    dangerous_pred.setV(-1);
    dangerous_pred.setH(-1);

    units_struct->preys.push_back(this);
    type = UnitType::PREY;

    CREATE_ENERGY = PREY_CREATE_ENERGY;

    brain = new PreysBrain();
}

Prey::~Prey()
{
    delete brain;
}

