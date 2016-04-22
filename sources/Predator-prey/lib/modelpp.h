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
    //todo переименоват, не понятно что за юниты такие
    Units units;
    Settings *sett;

public:

    //todo PP? что такое PP? лучше переименовать
    //todo добавить модификатор explicit
    //если конечно вы не хотите чтобы у вас настройки сами преобразововались в модель
    ModelPP(Settings *set);
    void initializeModel();
    Field* getField() { return &field; }
    int getTime() { return model_time; }
    int getDay()  { return model_day; }
    unsigned int getPredatorsNum() { return this->units.predators.size(); }
    unsigned int getPreysNum()     { return units.preys.size(); }
    void movePreys();
    void movePredators();
    bool isEnd();
    void moveEnd();
    void saveModel();
    void loadModel();

};

#endif // MODELPP_H
