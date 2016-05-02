#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

class Units;
class Field;
class Prey;

class Predator : public Animal
{
    const double DISTANCE_FOR_KILL = 1.0;
    const double DISTANCE_FOR_TARGET = 1.4;
    const double DISTANCE_FOR_RESET_TARGET = 2.1;
    const double DELTA = 0.1;

protected:
    /**
     * @brief PREDATOR_CREATE_ENERGY - энергия, необходимая для создания хищника
     * энергия пополняется при съедении жертвы
     */
    static const int PREDATOR_CREATE_ENERGY = 2;

    /**
     * @brief target - указатель на текущую цель
     */
    Prey* target;

    /**
     * @brief units_struct - указатель на класс с векторами хищников и жертв
     */
    Units* units_struct;

    void directionFinding();
    void chooseToTargetDirection();

    /**
     * @brief метод поиска жертвы на соседних 8 клетках;
     * в случае успеха записывает координаты жертвы в поле target
     */
    void findPrey();

    /**
     * @brief метод, уничтожающий target - цель (если она есть)
     */
    void killPrey();

    /**
     * @brief метод, создающий хищника на случайной соседней клетке; записывает его в вектор хищников
     */
    void createPredator();

    /**
     * @brief метод, создающий хищника на клетке с данными координатами
     */
    void spawnPredator(int, int);

public:

    /**
     * @brief конструктор с параметрами; создает хищника на поле с указанными координатами
     * @param a - координата 1
     * @param b - координата 2
     * @param field_pointer - указатель на поле
     * @param time_of_life - время жизни хищника без еды
     */
    Predator(const int a, const int b, Field* field_pointer, int time_of_life);

    /**
     * @brief метод, устанавливающий хищнику указатель на класс с векторами хищиков и жертв
     */
    void setUnitsPointer(Units* units_pointer);

    /**
     * @brief метод, передвигающий хищника
     */
    void movePredator();
};

#endif // PREDATOR_H
