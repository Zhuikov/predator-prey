#ifndef PREDATOR_H
#define PREDATOR_H
#include "modelapi.h"
#include "animal.h"
#include "predatorsbrain.h"

class Units;
class Prey;

/**
 * @brief класс, реализующий хищника в модели
 */
class Predator : public Animal
{

protected:
    /**
     * @brief PREDATOR_CREATE_ENERGY - энергия, необходимая для создания хищника
     */
    static const int PREDATOR_CREATE_ENERGY = 2;

    /**
     * @brief units_struct - указатель на класс с векторами хищников и жертв
     */
    Units* units_struct;

    virtual Animal* setChildren(const int v, const int h) override;

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

    virtual ~Predator();
};

#endif // PREDATOR_H
