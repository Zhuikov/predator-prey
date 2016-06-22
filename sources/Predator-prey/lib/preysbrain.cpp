#include "preysbrain.h"

PreysBrain::PreysBrain()
{

}

Unit* PreysBrain::getTarget(std::list< std::pair< Unit*, double > > && targets)
{
    double distanceToTarget = 100000; // расстояние до ближайшей цели
    Unit* result = nullptr;
    for (std::list< std::pair< Unit*, double > >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        if ((it->first->getType() == UnitType::GRASS) && (it->second < distanceToTarget)) {
            distanceToTarget = it->second;
            result = it->first;
        }
    }
    return result;
}
