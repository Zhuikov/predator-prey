#ifndef GRASS_H
#define GRASS_H
#include "coordinates.h"
#include "modelapi.h"

class Units;

class Grass : public Unit
{

public:
    Grass(const int v, const int h, Units* units);
    Coordinates place;
    bool eaten;
};

#endif // GRASS_H
