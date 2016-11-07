#ifndef SENSE_H
#define SENSE_H
#include <vector>
#include "unit.h"
#include "field.h"
#include "coordinates.h"

class Sense
{

    std::vector<std::pair< Unit*, double >> targets;

    /**
     * @brief senseRadius - радиус, в пределах которого происходит поиск целей на поле
     */
    double senseRadius;

    /**
     * @brief field - указатель на поле, на котором происходит поиск целей
     */
    Field* field;

public:

    Sense(Field* field, double radius = 2.0);

    /**
     * @brief метод, устанавливающий радиус поиска
     */
    void setRadius(double radius) { senseRadius = radius; targets.reserve(radius * radius + 1); }

    /**
     * @brief метод, реализующий поиск целей на поле в радиусе senseRadius
     * @param current - координаты, вокруг которых происходит поиск
     * @return список пар < Unit* , double >, где первый аргумент -
     * указатель на юнита, второй - расстояние до него;
     */
    std::vector< std::pair< Unit*, double > > getTargets(Coordinates current);
};

#endif // SENSE_H
