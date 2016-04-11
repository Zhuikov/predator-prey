#ifndef ANIMAL_H
#define ANIMAL_H
#include "coordinates.h"
#include "field.h"

/**
 * @brief класс, от которого наследуются хищники и жертвы
 */

class Animal
{
protected:
    /**
     * @brief life_time - время нахождения животного на поле
     */
    int life_time;

    int energy;
    int has_moved;
    char direction;
    Field* field;

    /**
     * @brief метод, выбирающий случайное направление и
     * записывающий его в direction
     */
    void chooseRandomDirection();

    /**
     * @brief метод, выбирающий наилучшее направление,
     * в зависимости от положение на доске
     */
    virtual void directionfinding() = 0;

    /**
     * @brief метод, перемещающий хищника
     * @param ch - направление перемещения
     */
    virtual void go(char ch);

public:
    Coordinates my_place;

    virtual ~Animal() {}
};

#endif // ANIMAL_H
