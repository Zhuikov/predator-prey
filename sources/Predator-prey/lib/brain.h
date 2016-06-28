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

    void reproduct();

    void move(int distance);

    void update(int step);

    double getMaxSpeed();

    double getMaxAvailableSpeed();

    double getComfortableSpeed();

    double getEnergy();

    /**
     * @brief возвращает true, если животное готово к размножению
     */
    bool isReady();

    bool isRuningAway = false;

    virtual ~Brain() {}

protected:

    double getLifeProcessEnergy();

    double getAge(int step);

    double getFoodValue(int step);

    double getMaxEnergy();

    double getMoveEnergy(int distance);

    double getMaxStamina();

    double getMoveStamina(int distance);

    Unit* find(std::list< std::pair< Unit*, double > > &targets, UnitType type);

    //virtual Unit* getReproductionTarget(std::list<std::pair< Unit *, double > > & targets) = 0;

    static constexpr double age_coef = 0.07;
    static constexpr double V_0 = 8;
    static constexpr double E_0 = 100;
    static constexpr double S_0 = 50;
    static constexpr double S_m = 10;
    static constexpr double E_f = 65;
    static constexpr int limit = 50;

    double step = 1;
    double energy = 1;
    double stamina = 1;



};

#endif // BRAIN_H
