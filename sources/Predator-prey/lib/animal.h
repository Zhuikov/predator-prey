#ifndef ANIMAL_H
#define ANIMAL_H
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
     * @brief life_time - счетчик ходов животного на поле - его возраст в ходах
     */
    // todo: эту штуку в мозг вынести
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
     * @brief target - указатель на текущую цель
     */
    Unit* target = nullptr;

    /**
     * @brief метод, уничтожающий target - цель (если она есть)
     */
    virtual void killTarget() noexcept;

    /**
     * @brief метод поиска корма в радиусе sense
     * в случае успеха, записывает координаты в target
     */
    void findTarget() noexcept;

    /**
     * @brief units_struct - указатель на класс с векторами юнитов,
     * а также их текущим числом
     */
    Units* units_struct;

    /**
     * @brief метод, выбирающий случайную клетку рядом с животным для порождения
     */
    void createChild();

    /**
     * @brief метод, создающий животное определенного типа на клетке с задаными координатами
     */
    virtual Animal* setChild(const int v, const int h) = 0;

    Sense sense {nullptr};
    Movement movement {0, 0};
    Brain* brain;

public:
    
    Animal(const int v, const int h, Field* field_pointer, Units* units_pointer, int TTL);

    Coordinates getPlace();

    int getCurrentStep() override;

    /**
     * @brief метод, реализующий ход животного
     */
    void move() noexcept;

    virtual ~Animal() {}
};

#endif // ANIMAL_H
