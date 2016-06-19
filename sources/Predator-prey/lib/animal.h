#ifndef ANIMAL_H
#define ANIMAL_H
#include "field.h"
#include "unit.h"
#include "movement.h"
#include "sense.h"
#include "brain.h"

/**
 * @brief класс, от которого наследуются хищники и жертвы
 */

class Animal : public Unit
{

protected:

    int CREATE_ENERGY;

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

    /**
     * @brief метод поиска корма на соседних клетках;
     * в случае успеха, записывает координаты в target
     */
    virtual void findTarget() noexcept;

    virtual void createChildren() = 0;

    Sense sense {nullptr};
    Movement movement {0, 0};
    Brain *brain;

public:
    
    Animal(const int v, const int h, Field* field_pointer);

    Coordinates getPlace();

    virtual void move() noexcept;

    virtual ~Animal() {}
};

#endif // ANIMAL_H
