#ifndef GRASS_H
#define GRASS_H
#include "unit.h"

class Grass : public Unit
{
public:

    Grass(const int v, const int h, Field* field, Units* units_pointer);
    Coordinates current;

    Coordinates getPlace() { return current; }
};

#endif // GRASS_H
