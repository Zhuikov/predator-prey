#include "predator.h"
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>


void Predator::killTarget() noexcept
{
    Animal::killTarget();
    units_struct->preysNum = units_struct->preysNum - 1;
}

Animal* Predator::setChildren(const int v, const int h)
{
    units_struct->predatorsNum ++;
    return new Predator(v, h, field, units_struct, max_life_time);
}

Predator::Predator(int v, int h, Field *field_pointer, Units *units_pointer, int time_of_life) noexcept:
    Animal(v, h, field_pointer, units_pointer)
{
    //max_life_time = time_of_life;
    units_pointer->predators.push_back(this);
    type = UnitType::PREDATOR;
    CREATE_ENERGY = PREDATOR_CREATE_ENERGY;
    brain = new PredatorsBrain();
}

Predator::~Predator()
{
    delete brain;
}
