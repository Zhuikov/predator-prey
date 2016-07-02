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
    virtual Unit* getTarget(std::list< std::pair< Unit*, double > > && targets) noexcept = 0;

    void eat(const int targetsAge) noexcept;

    void reproduct() noexcept;

    void move(int distance) noexcept;

    void update(int step) noexcept;

    double getMaxSpeed() const noexcept;

    double getMaxAvailableSpeed() noexcept;

    double getComfortableSpeed() noexcept;

    double getEnergy() noexcept;

    /**
     * @brief возвращает true, если животное готово к размножению
     */
    virtual bool isReady() const noexcept = 0;

    bool isRuningAway = false;

    virtual ~Brain() {}

protected:

    double getLifeProcessEnergy() const noexcept;

    double getAge(const int step) const noexcept;

    double getFoodValue(const int step) const noexcept;

    double getMaxEnergy() const noexcept;

    double getMoveEnergy(const int distance) const noexcept;

    double getMaxStamina() const noexcept;

    double getMoveStamina(const int distance) const noexcept;

    Unit* find(std::list< std::pair< Unit* , double > > &targets, UnitType type) noexcept;

    //virtual Unit* getReproductionTarget(std::list<std::pair< Unit *, double > > & targets) = 0;

    static constexpr double age_coef = 0.07; // 0.07
    static constexpr double V_0 = 2;         //  8
    static constexpr double E_0 = 100;
    static constexpr double S_0 = 50;
    static constexpr double S_m = 10;
    static constexpr double E_f = 165;       // 65
    static constexpr int limit = 50;         // 50

    double step = 400;
    double energy = getMaxEnergy() * 0.88;
    double stamina = 50;



};

#endif // BRAIN_H
