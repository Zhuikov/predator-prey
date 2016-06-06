#include "sense.h"

Sense::Sense()
{

}

std::list< Unit* > Sense::getTargets(Coordinates current)
{
    this->current = current;
    std::list< Unit* > targets;

    return targets;
}

