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

    if (k > 0.8)
    {
        getReproductionTarget(targets);
    }

    return find(targets, UnitType::PREY);
}

Unit* PredatorsBrain::getReproductionTarget(std::list<std::pair< Unit*, double > > & targets)
{
    double distanceToTarget = 100000; // расстояние до ближайшей цели
    Unit* result = nullptr;
    for (std::list< std::pair< Unit*, double > >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        if ((it->first->getType() == UnitType::PREDATOR) && (it->first->getCurrentStep() >= 200) &&
                (it->first->getCurrentStep() <= 900) && (it->second < distanceToTarget))
        {
            distanceToTarget = it->second;
            result = it->first;
        }
    }
    return result;
}

