#ifndef BRAIN_H
#define BRAIN_H
#include "unit.h"
#include <list>

class Brain
{
public:

    /**
     * @brief метод, возвращающий наиболее подходящую цель из данного списка
     */
    virtual Unit* getTarget(std::list< std::pair< Unit*, double > > && targets) = 0;

    int age;
    int energy;
    int maxEnergy;
    // todo добавить все остальное

    virtual ~Brain() {}
};

#endif // BRAIN_H
