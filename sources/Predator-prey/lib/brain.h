#ifndef BRAIN_H
#define BRAIN_H
#include "unit.h"
#include <vector>

class Brain
{
public:

    /**
     * @brief метод, возвращающий наиболее подходящую цель из данного списка
     */
    virtual Unit* getTarget(std::vector< std::pair< Unit*, double > > && targets) = 0;

    int age;
    int energy;
    int maxEnergy;
    // todo добавить все остальное

    virtual ~Brain() {}
};

#endif // BRAIN_H
