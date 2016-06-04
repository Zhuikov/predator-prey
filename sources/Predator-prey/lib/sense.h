#ifndef SENSE_H
#define SENSE_H
#include "field.h"

class Sense
{
public:
    Sense();

    void setRadius();
    //std::list< Unit* >getTargets(Coordinates current);

    double radius;
    Field* field;

};

#endif // SENSE_H
