#include "predatorsbrain.h"

PredatorsBrain::PredatorsBrain()
{

}

Unit* PredatorsBrain::getTarget(std::list<std::pair< Unit* , double > > && targets)
{
    double k = getEnergy()/getMaxEnergy();

    if (k > 0.9)
    {
        return nullptr;
    }

    Unit* result = nullptr;
    if ((k > 0.8) && (step >= 200) && (step <= 900))
    {
        result = getReproductionTarget(targets);
    }

    if (result != nullptr)
    {
        return result;
    }
    return find(targets, UnitType::PREY);
}

Unit* PredatorsBrain::getReproductionTarget(std::list<std::pair< Unit*, double > > & targets)
{
    double distanceToTarget = 100000;
    Unit* result = nullptr;
    for (std::list< std::pair< Unit*, double > >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        if ((it->first->getType() == UnitType::PREDATOR) && (it->second < distanceToTarget) &&
                (it->first->getCurrentStep() >= 200) && (it->first->getCurrentStep() <= 900))
        {
            distanceToTarget = it->second;
            result = it->first;
        }
    }
    return result;
}

