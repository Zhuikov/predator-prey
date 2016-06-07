#ifndef PREY_H
#define PREY_H
#include "animal.h"
#include "modelapi.h"
#include "preysbrain.h"

class Units;
class Grass;

/**
 * @brief класс для реализации жертвы в модели
 */
class Prey : public Animal
{
    PreysBrain brain;

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

    /**
     * @brief метод поиска корма на соседних клетках;
     * в случае успеха, записывает координаты в target
     */
    void findGrass();
    void directionFinding() noexcept;
    void chooseToTargetDirection() noexcept {} //пока нет травки

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
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param field_pointer - указатель на поле, где создается жертва
     * @param units_pointer - указатель на класс с векторами хищников и жертв
     */
    Prey(const int v, const int h, Field* field_pointer, Units* units_pointer);

    Coordinates getPlace();

    /**
     * @brief метод, передвигающий жертву
     */
    void movePrey();

};

#endif // PREY_H
