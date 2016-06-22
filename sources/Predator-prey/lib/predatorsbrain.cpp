#include "predatorsbrain.h"

PredatorsBrain::PredatorsBrain()
{

}

Unit* PredatorsBrain::getTarget(std::vector<std::pair< Unit* , double > > && targets)
{
    double distanceToTarget = 100000; // расстояние до ближайшей цели
    Unit* result = nullptr;
    for (std::vector< std::pair< Unit*, double > >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        if ((it->first->getType() == UnitType::PREY) && (it->second < distanceToTarget)) {
            distanceToTarget = it->second;
            result = it->first;
        }
    }
    return result;
}
