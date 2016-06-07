#ifndef SENSE_H
#define SENSE_H
#include "field.h"
#include "unit.h"
#include <list>

class Sense
{
    double senseRadius;
    Field* field;

public:

    Sense(double radius, Field* field);
    void setRadius(double radius) { senseRadius = radius; }
    std::list< Unit* > getTargets(Coordinates current);
};

#endif // SENSE_H
