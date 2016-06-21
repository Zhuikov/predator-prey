#ifndef MODEL_H
#define MODEL_H
#include "modelapi.h"
#include "units.h"
#include "settings.h"
#include <vector>
#include <ctime>

//TODO указывать слово override для перекрывающих функций
class Model : public ModelAPI
{
    Settings *settings;
    int model_time;
    int model_day;
    bool has_changed;
    Field field;
    /**
     * @brief Units - класс, в котором содержатся векторы юнитов: хищников и жертв
     */
    Units units;

    void incModelTime() noexcept;

public:
    explicit Model(Settings *settings, int seed = time(0)) noexcept;
    Field* getField() noexcept { return &field; }
    int getTime() const noexcept { return model_time; }
    int getDay() const noexcept { return model_day; }
    int getStep() const noexcept { return model_day * 24 + model_time; }
    unsigned int getPredatorsNum() const noexcept { return this->units.predatorsNum; }
    unsigned int getPreysNum() const noexcept { return units.preysNum; }
    unsigned int getGrassNum() const noexcept { return units.grassNum; }
    void movePreys() noexcept;
    void movePredators() noexcept;
    void move() noexcept;
    bool isEnd() const noexcept;
    void createPredators() noexcept;
    void createPreys() noexcept;
    void createGrass() noexcept;
    void removePredators() noexcept;
    void removePreys() noexcept;
    void remove() noexcept;


    void saveModel();
    void loadModel();

};



#endif // MODEL_H
