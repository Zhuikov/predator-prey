#ifndef PREY_H
#define PREY_H
#include "animal.h"
#include "preysbrain.h"

/**
 * @brief класс для реализации жертвы в модели
 */
class Prey : public Animal
{

protected:
    /**
     * @brief PREY_CREATE_ENERGY - необходимая энергия для создания жертвы
     */
    static const int PREY_CREATE_ENERGY = 2;

    /**
     * @brief dangerous_pred - координаты преследующего хищника
     */
    Coordinates dangerous_pred;

    virtual void killTarget() noexcept override;

    /**
     * @brief метод, создающий жертву и записывающий ее в вектор
     */

    virtual Animal* setChildren(const int v, const int h) override;


public:

    /**
     * @brief конструктор с параметрами
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param field_pointer - указатель на поле, где создается жертва
     * @param units_pointer - указатель на класс с векторами хищников и жертв
     */
    Prey(const int v, const int h, Field* field_pointer, Units* units_pointer, int TTL);

    virtual ~Prey();

};

#endif // PREY_H
