#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"

class Units;
class Field;

class Predator : public Animal
{
protected:
    Point target;
    Units* units_struct;
    void directionfinding();

    /**
     * @brief метод поиска жертвы на соседних 8 клетках;
     * в случае успеха записывает координаты жертвы в поле target
     */
    void findPrey();

    /**
     * @brief метод, уничтожающий жертву с указанными координатами
     */
    void killPrey(Point targ);

    /**
     * @brief метод, создающий хищника на случайной соседней клетке; записывает его в вектор хищников
     */
    void createPredator();

public:

    /**
     * @brief конструктор с параметрами; создает хищника на поле с указанными координатами
     * @param a - координата 1
     * @param b - координата 2
     * @param ptrF - указатель на поле
     */
    Predator(const int a, const int b, Field* ptrF);

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
