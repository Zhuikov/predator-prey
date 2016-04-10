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
    virtual int getTime() = 0;
    virtual int getDay() = 0;
    virtual bool isEnd() = 0;
    virtual void movePreys() = 0;
    virtual void movePredators() = 0;
    void saveModel();
    void loadModel();

    virtual ~ModelAPI() {}
};
#endif // MODELAPI_H
