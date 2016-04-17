#ifndef MODELPP_H
#define MODELPP_H
#include "modelapi.h"
#include <vector>

class ModelPP : public ModelAPI
{
    int model_time;
    int model_day;
    bool has_changed;
    Field field;
    Units units;
    Settings *sett;

public:

    ModelPP(Settings *set);
    Field* getField();
    void initializeModel();
    int getTime();
    int getDay();
    bool isEnd();
    void moveBegin();
    void movePreys();
    void movePredators();
    bool arePredatorsMoved();
    void saveModel();
    void loadModel();

};

#endif // MODELPP_H
