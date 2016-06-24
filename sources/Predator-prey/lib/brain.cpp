#include "brain.h"

void Brain::eat(int step)
{
    energy += getFoodValue(step);
    if (energy > getMaxEnergy(this->step))
    {
        energy = getMaxEnergy(this->step);
    }
}

void Brain::move(int distance)
{
    if (step > limit)
    {
        energy -= getMoveEnergy(distance);
    }
}

void Brain::update(int step)
{
    this->step = step;
    if (step > limit)
    {
        energy -= getLifeProcessEnergy(step);
    }
    if (step == limit)
    {
        energy = getMaxEnergy(step);
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

double Brain::getMaxEnergy(int step)
{
    double age = getAge(step) / 7;
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 3)) * E_0;
}

double Brain::getMoveEnergy(int distance)
{
    return distance * 0.2;
}

double Brain::getMaxSpeed(int step)
{
    double age = getAge(step);
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 2.3) + 0.2) * V_0;
}

double Brain::getLifeProcessEnergy(int step)
{
    double age = getAge(step) / 6;
    return std::pow(age, 3)/((4.5 * std::pow(age, 3)) - (14 * std::pow(age, 2)) + 18 * age - 0.1) + 2;
}
