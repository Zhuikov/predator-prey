#ifndef PREDATOR_H
#define PREDATOR_H
#include "animal.h"
#include "predatorsbrain.h"

/**
 * @brief класс, реализующий хищника в модели
 */
class Predator : public Animal
{

protected:

    virtual void killTarget() noexcept override;

    virtual void setChild(const int v, const int h) noexcept override;

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

    virtual ~Predator() override;
};

#endif // PREDATOR_H
