#include "predator.h"
#include "point.h"
#include "prey.h"
#include "units.h"
#include <ctime>
#include <cstdlib>

Predator::Predator(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    target.setX(0);
    target.setY(0);
    life_time = 0;

    srand(time(0));
    int flag = rand() % 4;
    switch (flag) {
        case 0: { direction = 'u'; break; }
        case 1: { direction = 'r'; break; }
        case 2: { direction = 'l'; break; }
        case 3: { direction = 'd'; break; }
    }    
}

void Predator::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setY(this->my_place.getY() - 1); break; }
        case 'r': { this->my_place.setX(this->my_place.getX() + 1); break; }
        case 'l': { this->my_place.setX(this->my_place.getX() - 1); break; }
        case 'd': { this->my_place.setY(this->my_place.getY() + 1); break; }
    }
}

void Predator::setPtrToUnitsStruct(Units *ptr)
{
    this->units_struct = ptr;
}

