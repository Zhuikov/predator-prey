#include "grass.h"

Grass::Grass(const int v, const int h, Units *units):
    eaten(false)
{
    place.setV(v);
    place.setH(h);
    units->grass.push_back(this);
}
