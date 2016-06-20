#ifndef SENSE_H
#define SENSE_H
#include <list>
#include "unit.h"
#include "field.h"
#include "coordinates.h"

class Sense
{
    double senseRadius;
    Field* field;

public:

    Sense(Field* field, double radius = 2.0);
    void setRadius(double radius) { senseRadius = radius; }
    std::list< std::pair< Unit*, double > > getTargets(Coordinates current);
};

#endif // SENSE_H
