#ifndef UNITS_H
#define UNITS_H
#include "predator.h"
#include "prey.h"
#include <vector>

class Predator;

/**
 * @brief класс для содержания векторов хищников и жертв
 */
class Units
{
public:
    /**
     * @brief preys - вектор указателей на жертву
     */
    std::vector<Prey*> preys;

    /**
     * @brief predators - вектор указателей на хищника
     */
    std::vector<Predator*> predators;

    Units();
    ~Units();
};

#endif // UNITS_H

