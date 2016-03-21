#ifndef MODELPP_H
#define MODELPP_H
#include "modelapi.h"
#include <vector>

class ModelPP: ModelAPI
{
    vector< Predator > predatorVector;
    vector< Prey > preyVector;
    int time;
    int day;

public:
    void initializeModel(const Settings &sett);
    void saveModel();
    void loadModel();
    void changeTime(int time);
    void changeDay(int day);
    int checkPredators(const std::vector< Predator > &predatorVec);
    int checkPreys(const std::vector< Prey > &preyVec);
};

#endif // MODELPP_H
