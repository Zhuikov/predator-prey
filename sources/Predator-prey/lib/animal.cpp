#include "animal.h"
#include <ctime>
#include <cstdlib>

void Animal::killTarget() noexcept
{
    target->exist = false;

    energy ++;
    life_time = -1;
    target = nullptr;
}
