#ifndef PREYSBRAIN_H
#define PREYSBRAIN_H
#include "brain.h"

class PreysBrain : public Brain
{
public:
    PreysBrain();

    Unit* getTarget(std::vector<std::pair< Unit *, double > > && targets);
};

#endif // PREYSBRAIN_H
