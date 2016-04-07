#ifndef MODELAPI_H
#define MODELAPI_H
#include "units.h"
#include "field.h"
#include <vector>

class Predator;
class Units;
class Prey;

class ModelAPI
{
public:
    virtual void initializeModel() = 0;
    void saveModel();
    void loadModel();
    void changeTime(int model_time);
    void changeDay(int day);
    int checkPredators(const std::vector< Predator > &predatorVector);
    int checkPreys(const std::vector< Prey > &preyVector);

    ~ModelAPI() {}
};
#endif // MODELAPI_H
