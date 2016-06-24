#ifndef BRAIN_H
#define BRAIN_H
#include "unit.h"
#include <cmath>
#include <list>

class Brain
{
public:

    /**
     * @brief метод, возвращающий наиболее подходящую цель из данного списка
     */
    virtual Unit* getTarget(std::list< std::pair< Unit*, double > > && targets) = 0;

    void eat(int step);
    void move(int distance);
    void update(int step);

    static constexpr double age_coef = 0.07;
    static constexpr double V_0 = 8;
    static constexpr double E_0 = 100;
    static constexpr double E_f = 65;
    static constexpr int limit = 10;

    double step;
    double energy;
    double stamina;

    // todo добавить все остальное

    double getAge(int step);

    double getFoodValue(int step);

    double getMaxEnergy(int step);

    double getMoveEnergy(int distance);

    double getMaxSpeed(int step);

    double getLifeProcessEnergy(int step);

    virtual ~Brain() {}
};

#endif // BRAIN_H
