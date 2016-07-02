#include "prey.h"

void Prey::killTarget() noexcept
{
    Animal::killTarget();
    units_struct->grassNum = units_struct->grassNum - 1;
}

void Prey::setChild(const int v, const int h) noexcept
{
    new Prey(v, h, field, units_struct, max_life_time);
}

Prey::Prey(const int v, const int h, Field* field_pointer, Units *units_pointer, int TTL):
    Animal(v, h, field_pointer, units_pointer, TTL)
{
    units_struct->preys.push_back(this);
    units_struct->preysNum ++;
    type = UnitType::PREY;
    brain = new PreysBrain();
}

Prey::~Prey()
{
    delete brain;
}

