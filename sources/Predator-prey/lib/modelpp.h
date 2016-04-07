#ifndef MODELPP_H
#define MODELPP_H
#include "modelapi.h"
#include <vector>

class ModelPP: public ModelAPI
{
    int model_time;
    int day;
    Field field;
    Units units;
    Settings *sett;

public:
    ModelPP(Settings *set);
    void initializeModel();
    void saveModel();
    void loadModel();
    void changeTime(int time);
    void changeDay(int day);
    int checkPredators(const std::vector< Predator > &predatorVec);
    int checkPreys(const std::vector< Prey > &preyVec);
};

#endif // MODELPP_H
