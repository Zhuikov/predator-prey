#ifndef MODEL_H
#define MODEL_H
#include "modelapi.h"
#include <vector>

//TODO расставить модификаторы noexcept для методов, которые не возбуждают исключений
//TODO указывать слово override для перекрывающих функций
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
    Settings *settings;

public:
    explicit Model(Settings *settings);
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
