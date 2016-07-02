#include "grass.h"

Grass::Grass(const int v, const int h, Field* field_pointer, Units* units_pointer)
{
    current.setV(v);
    current.setH(h);
    this->field = field_pointer;
    units_pointer->grass.push_back(this);
    type = UnitType::GRASS;
    exist = true;
    field_pointer->setPosition(v, h, this);
}

int Grass::getCurrentStep() noexcept
{
    return 100; // 428
}
