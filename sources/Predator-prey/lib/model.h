#ifndef MODEL_H
#define MODEL_H
#include "modelapi.h"
#include <vector>

class Model : public ModelAPI
{
    int model_time;
    int model_day;
    bool has_changed;
    Field field;
    /**
     * @brief Units - класс, в котором содержатся векторы юнитов: хищников и жертв
     */
    Units units;
    Settings *sett;

public:

    explicit Model(Settings *set);
    void initializeModel();
    Field* getField() { return &field; }
    int getTime() const { return model_time; }
    int getDay() const  { return model_day; }
    unsigned int getPredatorsNum() const { return this->units.predators.size(); }
    unsigned int getPreysNum() const     { return units.preys.size(); }
    void movePreys();
    void movePredators();
    bool isEnd() const;
    void createPredators();
    void deletePredators();
    void createPreys();
    void deletePreys();
    void removePredators();
    void removePreys();
    void remove();
    void saveModel();
    void loadModel();

};

#endif // MODEL_H
