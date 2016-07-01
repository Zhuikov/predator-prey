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
    virtual void killTarget() noexcept override;
    virtual void setChild(const int v, const int h) noexcept override;

public:

    /**
     * @brief конструктор с параметрами
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param field_pointer - указатель на поле, где создается жертва
     * @param units_pointer - указатель на класс с векторами хищников и жертв
     */
    Prey(const int v, const int h, Field* field_pointer, Units* units_pointer, int TTL);

    virtual ~Prey() override;

};

#endif // PREY_H
