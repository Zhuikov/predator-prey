#ifndef ANIMAL_H
#define ANIMAL_H
#include "coordinates.h"
#include "field.h"

/**
 * @brief класс, от которого наследуются хищники и жертвы
 */

class Animal
{
    /**
     * @brief метод, выбирающий свободное направление;
     * используется, если переход по выбранному направлению невозможен
     */
    void chooseEmptyDirection();

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
    bool has_moved;
    enum Direction
    {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    Direction direction;
    Field* field;

    /**
     * @brief метод, выбирающий случайное направление и
     * записывающий его в direction
     */
    void chooseRandomDirection();

    /**
     * @brief метод, выбирающий наилучшее направление,
     * в зависимости от положения цели на доске (если цель стоит на одной
     * из восьми соседних клеток)
     */
    virtual void directionFinding() = 0;

    /**
     * @brief метод, выбирающий нужное направление к цели
     * (если между животным и целью расстояние одна клетка)
     */
    virtual void chooseFarDirection() = 0;

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
