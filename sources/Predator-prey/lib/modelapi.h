#ifndef MODELAPI_H
#define MODELAPI_H
#include "predator.h"
#include "prey.h"
#include "settings.h"
#include <vector>

class ModelAPI
{
public:
    virtual void initializeModel(const Settings &sett)=0;
    virtual void saveModel();
    virtual void loadModel();
    virtual void changeTime(int time);
    virtual void changeDay(int day);
    virtual int checkPredators(const std::vector< Predator > &predatorVector);
    virtual int checkPreys(const std::vector< Prey > &preyVector);
};
#endif // MODELAPI_H
