#include "brain.h"

void Brain::eat(int step)
{
    energy += getFoodValue(step);
    if (energy > getMaxEnergy())
    {
        energy = getMaxEnergy();
    }
}

void Brain::reproduct()
{
    energy = getMaxEnergy() * 0.7;
}

void Brain::move(int distance)
{
    if (step > limit)
    {
        energy -= getMoveEnergy(distance);
        stamina -= getMoveStamina(distance);
        if (stamina > getMaxStamina())
        {
            stamina = getMaxStamina();
        }
    }
}

void Brain::update(int step)
{
    this->step = step;

    if (step > limit)
    {
        energy -= getLifeProcessEnergy();
    }
    if (step == limit)
    {
        energy = getMaxEnergy();
        stamina = getMaxStamina();
    }
}

double Brain::getAge(int step)
{
    return step * age_coef;
}

double Brain::getFoodValue(int step)
{
    double age = getAge(step) / 7;
    return ((5 * std::pow(age, 2)) + (5 * age)) / (7 * (std::pow(age, 2) + 3)) * E_f;
}

double Brain::getMaxEnergy()
{
    double age = getAge(step) / 7;
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 3)) * E_0;
}

double Brain::getMoveEnergy(int distance)
{
    return distance * 0.2;
}

double Brain::getMaxStamina()
{
    return (1 - std::exp((-3*energy)/(getMaxEnergy() + 0.01 - energy))) * S_0;
}

double Brain::getMoveStamina(int distance)
{
    return ((- 2 * (distance/getMaxSpeed())) + 1) * S_m;
}

Unit* Brain::find(std::list< std::pair< Unit*, double > > &targets, UnitType type)
{
    double distanceToTarget = 100000;
    Unit* result = nullptr;
    for (std::list< std::pair< Unit*, double > >::const_iterator it = targets.begin(); it != targets.end(); ++it){
        if ((it->first->getType() == type) && (it->second < distanceToTarget)) {
            distanceToTarget = it->second;
            result = it->first;
        }
    }
    return result;
}

double Brain::getMaxSpeed()
{
    double age = getAge(step);
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 2.3) + 0.2) * V_0;
}

double Brain::getMaxAvailableSpeed()
{
    double speed = getMaxSpeed();
    if (speed < stamina)
    {
        return speed;
    }
    else
    {
        return stamina;
    }
}

double Brain::getComfortableSpeed()
{
    double speed = 0.4 * getMaxSpeed();
    if (speed < stamina)
    {
        return speed;
    }
    else
    {
        return stamina;
    }
}

double Brain::getEnergy()
{
    return energy;
}

bool Brain::isReady()
{
    return ((getEnergy() / getMaxEnergy() > 0.99) && (step >= 200) && (step <= 900));
}

double Brain::getLifeProcessEnergy()
{
    double age = getAge(step) / 6;
    return std::pow(age, 3)/((4.5 * std::pow(age, 3)) - (14 * std::pow(age, 2)) + 18 * age - 0.1) + 2;
}
