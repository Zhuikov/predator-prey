#include "sense.h"

Sense::Sense(Field *field, double radius):
    senseRadius(radius),
    field(field)
{}

std::list< std::pair< Unit*, double > > Sense::getTargets(Coordinates current)
{
    std::list< std::pair< Unit*, double > > targets;
    for (int i = current.getV() - senseRadius; i <= current.getV() + senseRadius; i++) {
        for (int j = current.getH() - senseRadius; j <= current.getH() + senseRadius; j++) {
            if ((field->checkBoundary(i, j) == true) &&
                    (Coordinates(i, j) - current <= senseRadius) &&
                    (field->getPosition(i, j) != nullptr) &&
                    (field->getPosition(i, j)->exist == true) &&
                    (Coordinates(i, j) != current))
            {
                std::pair< Unit*, double > pair(field->getPosition(i, j), Coordinates(i, j) - current);
                targets.push_back(pair);
            }
        }
    }
    return targets;
}

