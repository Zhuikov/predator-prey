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

    /**
     * @brief energy - текущая энергия животного
     */
    int energy;

    /**
     * @brief has_moved - флаг; используется в случае, когда все четыре
     * направления заблокированы
     */
    bool has_moved;

    /**
     * @brief Direction - возможные значения направлений
     */

    //TODO: следует использовать перечисления с областью видимости
    //enum class Position
    //TODO: направление не только у животного, оно еще используется в поле, т. о. лучше вынести из этого класса
    enum Direction
    {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    /**
     * @brief direction - текущее направление животного
     */
    Direction direction;

    /**
     * @brief field - указатель на поле, где стоит животное
     */
    Field* field;

    /**
     * @brief метод устанавливает направление, если соответствующая клетка свободна
     * @return
     */

    bool setDirection(Direction);

    /**
     * @brief метод, выбирающий случайное направление,
     * записывает его в direction
     */
    void chooseRandomDirection();

    /**
     * @brief метод, выбирающий направление для следующего хода,
     * записывает его в directon
     */
    virtual void directionFinding() = 0;

    /**
     * @brief метод, выбирающий направление, в зависимости от положения цели
     */
    virtual void chooseToTargetDirection() = 0;

    /**
     * @brief метод, перемещающий хищника
     * @param ch - направление перемещения
     */
    virtual void go();

public:

    /**
     * @brief place - координаты животного на поле
     */
    Coordinates place;

    /**
     * @brief died - флаг; died = true, если животное умерло,
     * died = false если животное живое
     */
    bool died;
    
    virtual ~Animal() {}
};

#endif // ANIMAL_H
