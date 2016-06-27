#ifndef PREDATORSBRAIN_H
#define PREDATORSBRAIN_H
#include "brain.h"

class PredatorsBrain : public Brain
{
public:
    PredatorsBrain();

    Unit* getTarget(std::list<std::pair< Unit *, double > > && targets);

    virtual Unit* getReproductionTarget(std::list<std::pair< Unit *, double > > && targets);
};

#endif // PREDATORSBRAIN_H
