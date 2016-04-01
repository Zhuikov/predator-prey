#include "animal.h"

void Animal::go(const char)
{
    switch (this->direction) {
        case 'u': { this->my_place.setY(this->my_place.getY() - 1); break; }
        case 'r': { this->my_place.setX(this->my_place.getX() + 1); break; }
        case 'l': { this->my_place.setX(this->my_place.getX() - 1); break; }
        case 'd': { this->my_place.setY(this->my_place.getY() + 1); break; }
    }
}
