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
    //todo лучше придерживать одного стиля при названии методов
    // directionFinding
    virtual void directionfinding() = 0;

    /**
     * @brief метод, перемещающий хищника
     * @param ch - направление перемещения
     */
    //todo что такое go? а ch? все переименовать
    // мб move и direction
    virtual void go(char ch); // (Direction direction)

public:
    //todo возможно, приствака my не нужна
    // это поле класса и так понятно к чему оно относится
    Coordinates my_place;
    bool died;
    
    virtual ~Animal() {}
};

#endif // ANIMAL_H
