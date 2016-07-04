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
    /**
     * @brief life_time - счетчик ходов животного на поле - его возраст в ходах
     */
    int life_time;

    /**
     * @brief max_life_time - максимальное время жизни животного без еды
     */
    const int max_life_time;

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
    void createChild() noexcept;

    /**
     * @brief метод, создающий животное определенного типа на клетке с задаными координатами
     */
    virtual void setChild(const int v, const int h) const noexcept = 0;

    Sense sense {nullptr};
    Movement movement {0, 0};
    Brain* brain;

public:
    
    /**
     * @brief Конструктор животного в модели
     * @param v - координата на поле по вертикали
     * @param h - координата на поле по горизонтали
     * @param field_pointer - указатель на поле, где находится животное
     * @param units_pointer - указатель на класс с векторами животных и травы
     * @param TTL - максимальное время жизни животного
     */
    Animal(const int v, const int h, Field* field_pointer, Units* units_pointer, int TTL);

    Coordinates getPlace() const noexcept override;

    int getCurrentStep() const noexcept override;

    /**
     * @brief метод, устанавливающий возраст животного
     */
    void setAge(const int age) noexcept { life_time = age; }

    /**
     * @brief метод, реализующий ход животного
     */
    void move() noexcept;

    virtual ~Animal() {}
};

#endif // ANIMAL_H
