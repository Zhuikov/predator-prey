#include "preysbrain.h"

PreysBrain::PreysBrain()
{

}

Unit* PreysBrain::getTarget(std::list<Unit *> targets)
{
    for (std::list< Unit* >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        //todo Пусть тут ближайшее выбирает. И не только траву ищет
        if ((*it)->getType() == UnitType::GRASS) {
            return *it;
        }
    }
    return nullptr;
}
