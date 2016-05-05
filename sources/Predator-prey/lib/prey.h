#ifndef PREY_H
#define PREY_H
#include "animal.h"

class Units;

class Prey : public Animal
{
protected:
    /**
     * @brief PREY_CREATE_ENERGY - необходимая энергия для создания жертвы
     */
    static const int PREY_CREATE_ENERGY = 2;

    /**
     * @brief warning - флаг, преследуется ли данная жертва
     */
    bool warning;

    /**
     * @brief dangerous_pred - координаты преследующего хищника
     */
    Coordinates dangerous_pred;

    /**
     * @brief units_struct - указатель на класс с векторами хищников и жертв
     */
    Units* units_struct;
    void directionFinding();
    void chooseToTargetDirection() {} //пока нет травки

    /**
     * @brief метод, создающий жертву и записывающий ее в вектор
     */
    void createPrey();

    /**
     * @brief метод, создающий жертву на клетке с данными координатами
     */
    void spawnPrey(int, int);

    /**
     * @brief метод, проверяющий, не преследуется ли жертва
     */
    void isChase();

public:

    /**
     * @brief конструктор с параметрами
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param ptrF - указатель на поле, где создается жертва
     */
    Prey(const int v, const int h, Field* ptrF);

    /**
     * @brief метод, устанавливающий указатель на класс с хищниками и жертвами
     */
    void setUnitsPointer(Units* units_pointer);

    /**
     * @brief метод, передвигающий жертву
     */
    void movePrey();

    ~Prey() {}
};

#endif // PREY_H
