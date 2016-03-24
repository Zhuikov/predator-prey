#ifndef MODELPP_H
#define MODELPP_H
#include "modelapi.h"
#include "units.h"
#include <vector>

class Settings;

class ModelPP: public ModelAPI
{
    int model_time;
    int day;

public:
    void initializeModel(const Settings &sett, Units &units);
    void saveModel();
    void loadModel();
    void changeTime(int time);
    void changeDay(int day);
    int checkPredators(const std::vector< Predator > &predatorVec);
    int checkPreys(const std::vector< Prey > &preyVec);
};

#endif // MODELPP_H
