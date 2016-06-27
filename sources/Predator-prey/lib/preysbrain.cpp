#include "preysbrain.h"

PreysBrain::PreysBrain()
{

}

Unit* PreysBrain::getTarget(std::list< std::pair< Unit*, double > > && targets)
{
    if (getEnergy()/getMaxEnergy() > 0.9)
    {
        return nullptr;
    }

    Unit* result = find(targets, UnitType::PREDATOR);

    if(result != nullptr)
    {
        isRuningAway = true;
        return result;
    }

    result = find(targets, UnitType::GRASS);

    isRuningAway = false;
    return result;
}

Unit* PreysBrain::getReproductionTarget(std::list<std::pair<Unit*, double> >&& targets)
{
    // todo реализовать
    return nullptr;
}
