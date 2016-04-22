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
     * @brief life_time - счетчик ходов животного на поле
     */
    int life_time;

    /**
     * @brief max_life_time - максимальное время жизни животного без еды
     */
    int max_life_time;

    int energy;
    int has_moved;
  //Direction direction
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
    virtual void directionFinding() = 0;

    /**
     * @brief метод, перемещающий хищника
     * @param ch - направление перемещения
     */
    virtual void go();

public:
    Coordinates place;
    bool died;
    
    virtual ~Animal() {}
};

#endif // ANIMAL_H
