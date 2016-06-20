#ifndef UNITS_H
#define UNITS_H
#include "predator.h"
#include "prey.h"
#include "grass.h"
#include <vector>

class Predator;
class Grass;

/**
 * @brief класс для содержания векторов хищников и жертв, а также корма для жертв
 */
class Units
{
public:
    /**
     * @brief preys - вектор указателей на жертву
     */
    std::vector< Prey* > preys;

    /**
     * @brief predators - вектор указателей на хищника
     */
    std::vector< Predator* > predators;

    /**
     * @brief Units
     */
    std::vector< Grass* > grass;

    int predatorsNum;
    int preysNum;


    Units();
    ~Units();
};

#endif // UNITS_H

