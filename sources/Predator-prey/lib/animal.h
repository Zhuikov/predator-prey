#ifndef ANIMAL_H
#define ANIMAL_H
#include "field.h"
#include "unit.h"
#include "movement.h"
#include "sense.h"

/**
 * @brief класс, от которого наследуются хищники и жертвы
 */

class Animal : public Unit
{
//    /**
//     * @brief метод, выбирающий свободное направление;
//     * используется, если переход по выбранному направлению невозможен
//     */
//    void chooseEmptyDirection() noexcept;

protected:

    /**
     * @brief DISTANCE_FOR_KILL - дистанция до жертвы, при которой можно ее съесть
     */
    static constexpr double DISTANCE_FOR_EAT = 1;

    /**
     * @brief DISTANCE_FOR_TARGET - дистанция для взятия жертвы в цель
     */
    static constexpr double DISTANCE_FOR_TARGET = 1.4;

    /**
     * @brief DELTA - константа, необходимая для сравнения чисел
     */
    static constexpr double DELTA = 0.1;

    /**
     * @brief life_time - счетчик ходов животного на поле
     */
    int life_time;

    /**
     * @brief max_life_time - максимальное время жизни животного без еды
     */
    int max_life_time;

    /**
     * @brief energy - текущая энергия животного
     */
    int energy;

    /**
     * @brief has_moved - флаг; используется в случае, когда все четыре
     * направления заблокированы
     */
    bool has_moved;

//    /**
//     * @brief direction - текущее направление животного
//     */
//    Direction direction;

    /**
     * @brief field - указатель на поле, где стоит животное
     */
    Field* field;

    /**
     * @brief target - указатель на текущую цель
     */
    Unit* target;

    /**
     * @brief метод, уничтожающий target - цель (если она есть)
     */
    void killTarget() noexcept;

    Sense sense {nullptr};
    Movement movement {0, 0};

public:
    
    //virtual ~Animal() {}
};

#endif // ANIMAL_H
