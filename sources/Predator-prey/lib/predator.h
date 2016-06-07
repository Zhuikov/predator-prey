#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

class Units;
class Prey;

/**
 * @brief класс, реализующий хищника в модели
 */
class Predator : public Animal
{
    /**
     * @brief DISTANCE_FOR_RESET_TARGET - дистанция, при которой жертва убегает от хищника
     */
    static constexpr double DISTANCE_FOR_RESET_TARGET = 2.1;

protected:
    /**
     * @brief PREDATOR_CREATE_ENERGY - энергия, необходимая для создания хищника
     */
    static const int PREDATOR_CREATE_ENERGY = 2;

    /**
     * @brief units_struct - указатель на класс с векторами хищников и жертв
     */
    Units* units_struct;

    void directionFinding() noexcept;
    void chooseToTargetDirection() noexcept;

    /**
     * @brief метод поиска жертвы на соседних 8 клетках;
     * в случае успеха записывает жертву в поле target
     */
    void findPrey() noexcept;

    /**
     * @brief метод, создающий хищника на случайной соседней клетке; записывает его в вектор хищников
     */
    void createPredator() noexcept;

public:

    /**
     * @brief конструктор с параметрами; создает хищника на поле с указанными координатами
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param field_pointer - указатель на поле
     * @param units_pointer - указатель на класс с векторами хищников и жертв
     * @param time_of_life - время жизни хищника без еды
     */
    Predator(const int v, const int h, Field* field_pointer, Units* units_pointer, int time_of_life) noexcept;

    Coordinates getPlace();

    /**
     * @brief метод, передвигающий хищника
     */
    void movePredator() noexcept;
};

#endif // PREDATOR_H
