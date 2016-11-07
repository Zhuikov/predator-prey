#include "sense.h"

Sense::Sense(Field *field, double radius):
    senseRadius(radius),
    field(field)
{targets.reserve(radius * radius + 1);}

std::vector< std::pair< Unit*, double > > Sense::getTargets(Coordinates current)
{
    targets.clear();

    int lowerBound = current.getV() - senseRadius;
    while (!field->checkBoundary(lowerBound, current.getH())) {
        lowerBound++;
    }


    int upperBound = current.getV() + senseRadius;
    while (!field->checkBoundary(upperBound, current.getH())) {
        upperBound--;
    }


    int leftBound = current.getH() - senseRadius;
    while (!field->checkBoundary(current.getV(), leftBound)) {
        leftBound++;
    }


    int rightBound = current.getH() + senseRadius;
    while (!field->checkBoundary(current.getV(), rightBound)) {
        rightBound--;
    }

    for (int i = lowerBound; i <= upperBound; i++)
    {
        for (int j = leftBound; j <= rightBound; j++)
        {
            double distance = Coordinates(i, j) - current;
            if ((distance <= senseRadius) &&
                    (field->getPosition(i, j) != nullptr) &&
                    (field->getPosition(i, j)->exist == true) &&
                    (Coordinates(i, j) != current))
            {
                std::pair< Unit*, double > pair(field->getPosition(i, j), distance);
                targets.push_back(pair);
            }
        }
    }
    return targets;
}

