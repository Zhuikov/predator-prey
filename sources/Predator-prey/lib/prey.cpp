#include "prey.h"
#include <ctime>
#include <cstdlib>


//TODO: дублирует метод из predator, можно попытаться вынести общее  в animal
void Prey::createPrey()
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

    brain = new PreysBrain();
}


void Prey::move() noexcept
{
    movement.setRandomTarget();

    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), nullptr);
    movement.move();
    field->setPosition(movement.getCurrent().getV(), movement.getCurrent().getH(), this);

    if (energy == PREY_CREATE_ENERGY) {
        createPrey();
    }
}
