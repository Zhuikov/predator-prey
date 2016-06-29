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

    void eat(int targetsAge) noexcept;

    void reproduct() noexcept;

    void move(int distance) noexcept;

    void update(int step) noexcept;

    double getMaxSpeed() noexcept;

    double getMaxAvailableSpeed() noexcept;

    double getComfortableSpeed() noexcept;

    double getEnergy() noexcept;

    /**
     * @brief возвращает true, если животное готово к размножению
     */
    bool isReady() noexcept;

    bool isRuningAway = false;

    virtual ~Brain() {}

protected:

    double getLifeProcessEnergy() noexcept;

    double getAge(int step) noexcept;

    double getFoodValue(int step) noexcept;

    double getMaxEnergy() noexcept;

    double getMoveEnergy(int distance) noexcept;

    double getMaxStamina() noexcept;

    double getMoveStamina(int distance) noexcept;

    Unit* find(std::list< std::pair< Unit* , double > > &targets, UnitType type) noexcept;

    //virtual Unit* getReproductionTarget(std::list<std::pair< Unit *, double > > & targets) = 0;

    static constexpr double age_coef = 0.07;
    static constexpr double V_0 = 2; //  8
    static constexpr double E_0 = 100;
    static constexpr double S_0 = 50;
    static constexpr double S_m = 10;
    static constexpr double E_f = 165; // 65
    static constexpr int limit = 50; // 50

    double step = 1;
    double energy = 1;
    double stamina = 50;



};

#endif // BRAIN_H
