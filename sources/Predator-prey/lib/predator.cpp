#include "predator.h"

void Predator::killTarget() noexcept
{
    Animal::killTarget();
    units_struct->preysNum = units_struct->preysNum - 1;
}

void Predator::setChild(const int v, const int h) noexcept
{
    new Predator(v, h, field, units_struct, max_life_time);
}

Predator::Predator(int v, int h, Field *field_pointer, Units *units_pointer, int time_of_life) noexcept:
    Animal(v, h, field_pointer, units_pointer, time_of_life)
{
    units_pointer->predators.push_back(this);
    units_pointer->predatorsNum ++;
    type = UnitType::PREDATOR;
    brain = new PredatorsBrain();
}

Predator::~Predator()
{
    delete brain;
}
