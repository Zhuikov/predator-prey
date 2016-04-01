#ifndef MODELAPI_H
#define MODELAPI_H
#include "units.h"
#include "field.h"
#include <vector>

class Predator;

class ModelAPI
{
public:
    void initializeModel(const Settings &sett, Units &units, Field &field);
    void saveModel();
    void loadModel();
    virtual void changeTime(int model_time);
    virtual void changeDay(int day);
    virtual int checkPredators(const std::vector< Predator > &predatorVector);
    virtual int checkPreys(const std::vector< Prey > &preyVector);
};
#endif // MODELAPI_H
