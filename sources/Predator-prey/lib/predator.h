#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

class Units;
class Field;
class Prey;

class Predator : public Animal
{
protected:
    static const int PREDATOR_CREATE_ENERGY = 2;
    Prey* target;
    Units* units_struct;
    void directionFinding();
    void chooseOneLineDirection();

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
