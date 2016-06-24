#include "brain.h"

double Brain::getAge(int step)
{
    return step * age_coef;
}

double Brain::getMaxEnergy(double age)
{
    age /= 7;
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 3)) * E_0;
}

double Brain::getMaxSpeed(double age)
{
    return ((std::pow(age, 2) + (2 * age)) / (std::pow(age, 2) + 2.3) + 0.2) * V_0;
}

double Brain::getLifeProcessEnergy(double age)
{
    age /= 6;
    return std::pow(age, 3)/((4.5 * std::pow(age, 3)) - (14 * std::pow(age, 2)) + 18 * age - 0.1) + 2;
}
