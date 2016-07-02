#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "coordinates.h"
#include "field.h"

/**
 * @brief Класс для реализации передвижения животного по полю
 */
class Movement
{
public:
    Movement(Coordinates current, Field* field, double speed = 1.0);

    /**
     * @brief метод, возвращающий текущие координаты цели
     */
    Coordinates getCurrent();

    /**
     * @brief метод, передвигающий из текущих координат в координаты,
     * наиболее близкие к цели (или в цель)
     */
    int move();

    /**
     * @brief moveApart метод, передвигающий из текущих координат
     * в противоположную сторону от цели
     */
    int moveApart();

    /**
     * @brief метод, устанавливающий цель движения
     * @param координаты цели
     */
    void setTarget(Coordinates target);

    /**
     * @brief метод, выбирающий случайную цель на поле
     */
    void setRandomTarget();

    /**
     * @brief метод, устанавливающий радиус движения
     */
    void setSpeed(double speed);

private:

    /**
     * @brief метод, вычисляющий дистанцию между двумя координатами на поле
     */
    double getDistance(Coordinates source, Coordinates dest);

    /**
     * @brief метод, округляющий число в большую по модулю сторону
     */
    int round(double number);

    /**
     * @brief current - текущие координаты
     */
    Coordinates current;

    /**
     * @brief target - координаты цели движения
     */
    Coordinates target;

    /**
     * @brief speed - радиус движения
     */
    double speed;

    /**
     * @brief field - указатель на поле, где происходит движение
     */
    Field *field;

};

#endif // MOVEMENT_H
