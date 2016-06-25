#include "predatorsbrain.h"

PredatorsBrain::PredatorsBrain()
{

}

Unit* PredatorsBrain::getTarget(std::list<std::pair< Unit* , double > > && targets)
{
    if (getEnergy()/getMaxEnergy() > 0.9)
    {
        return nullptr;
    }

    return find(targets, UnitType::PREY);
}

