#include "grass.h"

Grass::Grass(const int v, const int h, Units *units)
{
    current.setV(v);
    current.setH(h);
    units->grass.push_back(this);
    type = UnitType::GRASS;
    exist = true;
}
