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
    UnitType type;
    Field* field;

public:

    virtual Coordinates getPlace() = 0;
    bool exist;
    UnitType getType() { return type; }

    virtual ~Unit() {}
};

#endif // UNIT_H
