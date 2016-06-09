#include "sense.h"

Sense::Sense(double radius, Field *field):
    senseRadius(radius),
    field(field)
{}

std::list< Unit* > Sense::getTargets(Coordinates current)
{
    std::list< Unit* > targets;
    for (int i = current.getV() - senseRadius; i <= current.getV() + senseRadius; i++) {
        for (int j = current.getH() - senseRadius; j <= current.getH() + senseRadius; j++) {
            if ((field->checkBoundary(i, j) == true) && (Coordinates(i, j) - current <= senseRadius) &&
                    (field->getPosition(i, j) != nullptr) && (field->getPosition(i, j)->exist == true)) {
                targets.push_back(field->getPosition(i, j));
            }
        }
    }
    return targets;
}

