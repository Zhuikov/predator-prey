#include "predator.h"
#include <ctime>
#include <cstdlib>

Predator::Predator(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
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
