#ifndef PREDATORSBRAIN_H
#define PREDATORSBRAIN_H
#include "brain.h"

class PredatorsBrain : public Brain
{
protected:

    //virtual Unit* getReproductionTarget(std::list<std::pair< Unit*, double > >& targets);

public:
    PredatorsBrain();

    Unit* getTarget(std::list<std::pair< Unit *, double > > && targets);
    bool isReady() noexcept;
};

#endif // PREDATORSBRAIN_H
