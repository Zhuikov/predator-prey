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
    Prey* target;
    Units* units_struct;
    void directionfinding();

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
     * @param координаты точки, вокруг которой создается хищник
     */
    void createPredator();

    /**
     * @brief метод, уничтожающий хищника, оставшегося без еды на определенное время
     */
    void killHungryPredator(Units *units);

public:

    /**
     * @brief конструктор с параметрами; создает хищника на поле с указанными координатами
     * @param a - координата 1
     * @param b - координата 2
     * @param ptrF - указатель на поле
     * @param time_of_life - время жизни хищника без еды
     */
    Predator(const int a, const int b, Field* ptrF, int time_of_life);

    /**
     * @brief метод, устанавливающий хищнику указатель на класс с векторами хищиков и жертв
     */
    void setPtrs(Units* ptrU);

    /**
     * @brief метод, передвигающий хищника
     */
    void movePredator();
};

#endif // PREDATOR_H
