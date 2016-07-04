#ifndef UNITS_H
#define UNITS_H
#include <vector>

class Predator;
class Grass;
class Prey;

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
     * @brief grass - вектор с травой - кормом для жертв
     */
    std::vector< Grass* > grass;

    /**
     * @brief predatorsNum - текущее число хищников на поле
     */
    int predatorsNum;

    /**
     * @brief preysNum - текущее число жертв на поле
     */
    int preysNum;

    /**
     * @brief grassNum - текущее число травы на поле
     */
    int grassNum;


    Units();
    ~Units();
};

#endif // UNITS_H

