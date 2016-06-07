#ifndef SENSE_H
#define SENSE_H
#include "field.h"
#include "unit.h"
#include <list>

class Sense
{
    Coordinates current;

public:
    Sense();

    void setRadius();
    std::list< Unit* > getTargets(Coordinates current);

    double senseRadius;
    Field* field;
};

#endif // SENSE_H
