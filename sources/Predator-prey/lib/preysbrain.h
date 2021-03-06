#ifndef PREYSBRAIN_H
#define PREYSBRAIN_H
#include "brain.h"

class PreysBrain : public Brain
{
protected:

    //virtual Unit* getReproductionTarget(std::list<std::pair< Unit *, double > > & targets);

public:
    PreysBrain();

    Unit* getTarget(std::list<std::pair< Unit *, double > > && targets) noexcept override;
    bool isReady() noexcept override;
};

#endif // PREYSBRAIN_H
