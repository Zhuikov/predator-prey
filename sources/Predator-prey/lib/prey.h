#ifndef PREY_H
#define PREY_H
#include "animal.h"

class Units;

class Prey : public Animal
{
protected:
    int warning;
    Coordinates dangerous_pred;
    Units* units_struct;
    void directionfinding();

    /**
     * @brief метод, создающий жертву и записывающий ее в вектор
     */
    void createPrey();

    /**
     * @brief метод, проверяющий, не преследуется ли жертва
     */
    void isChase();

public:

    /**
     * @brief конструктор с параметрами
     * @param a - координата 1
     * @param b - координата 2
     * @param ptrF - указатель на поле, где создается жертва
     */
    Prey(const int a, const int b, Field* ptrF);

    /**
     * @brief метод, устанавливающий указатель на класс с хищниками и жертвами
     */
    //todo ptrU?
    //todo что такое Ptrs? переименовать
    void setPtrs(Units* ptrU);

    /**
     * @brief метод, передвигающий жертву
     */
    void movePrey();

    ~Prey() {}
};

#endif // PREY_H
