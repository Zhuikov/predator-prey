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


    static constexpr double age_coef = 0.07;
    static constexpr double V_0 = 8;
    static constexpr double E_0 = 100;

    int age;
    int energy;
    int maxEnergy;
    // todo добавить все остальное

    double getAge(int step);

    double getMaxEnergy(double age);

    double getMaxSpeed(double age);

    double getLifeProcessEnergy(double age);

    virtual ~Brain() {}
};

#endif // BRAIN_H
