#ifndef GRASS_H
#define GRASS_H
#include "unit.h"

/**
 * @brief Класс для представления корма для жертв (травы)
 */
class Grass : public Unit
{
public:

    /**
     * @brief конструктор с параметрами; добавляет траву на поле
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param field_pointer - указатель на поле
     * @param units_pointer - указатель на класс с векторами хищников, жертв и травы
     */
    Grass(const int v, const int h, Field* field_pointer, Units* units_pointer);

    /**
     * @brief current - координаты корма
     */
    Coordinates current;
    Coordinates getPlace() noexcept override { return current; }
    int getCurrentStep() noexcept override;
};

#endif // GRASS_H
