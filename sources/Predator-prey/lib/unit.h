#ifndef UNIT_H
#define UNIT_H
#include "coordinates.h"
#include "field.h"
#include "units.h"

class Field;

/**
 * @brief UnitType - перечисление всех возможных типов юнитов
 */
enum class UnitType
{
    PREDATOR,
    PREY,
    GRASS
};

class Unit
{

protected:

    /**
     * @brief type - тип юнита
     */
    UnitType type;

    /**
     * @brief field - указатель на поле, где находится юнит
     */
    Field* field;

public:

    /**
     * @brief метод, возвращающий координаты юнита на поле
     */
    virtual Coordinates getPlace() = 0;


    virtual int getCurrentStep() = 0;

    /**
     * @brief exist - флаг существования юнита. Если юнит существует на поле, exist = true,
     * в противном случае exist = false
     */
    bool exist;

    /**
     * @brief метод, возвращающий тип юнита
     */
    UnitType getType() { return type; }

    virtual ~Unit() {}
};

#endif // UNIT_H
