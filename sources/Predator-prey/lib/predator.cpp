#include "predator.h"

Predator::Predator(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    life_time = 0;
    did_turn = 0;
    direction = 'u';

}
