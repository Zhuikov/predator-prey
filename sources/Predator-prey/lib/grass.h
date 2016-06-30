#ifndef GRASS_H
#define GRASS_H
#include "unit.h"

/**
 * @brief Класс для представления корма для жертв
 */
class Grass : public Unit
{
public:

    Grass(const int v, const int h, Field* field, Units* units_pointer);

    /**
     * @brief current - координаты корма
     */
    Coordinates current;

    Coordinates getPlace() noexcept override { return current; }

    int getCurrentStep() noexcept override;
};

#endif // GRASS_H
