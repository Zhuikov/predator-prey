#ifndef MODELAPI_H
#define MODELAPI_H
#include "predator.h"
#include "prey.h"
#include <vector>

class ModelAPI
{
public:
    virtual void initializeModel()=0;
    virtual void saveModel()=0;
    virtual void loadModel()=0;
    virtual void changeTime()=0;
    virtual int checkPredators(const std::vector< Predator > &predatorVector)=0;
    virtual int checkPreys(const std::vector< Prey > &preyVector)=0;
};
#endif // MODELAPI_H
