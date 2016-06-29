#include "grass.h"

Grass::Grass(const int v, const int h, Field* field, Units* units_pointer)
{
    current.setV(v);
    current.setH(h);
    this->field = field;
    units_pointer->grass.push_back(this);
    type = UnitType::GRASS;
    exist = true;
    field->setPosition(v, h, this);
}

int Grass::getCurrentStep() noexcept
{
    return 100; //было 428
}
