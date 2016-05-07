#ifndef MODEL_H
#define MODEL_H
#include "modelapi.h"
#include <vector>

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
    explicit Model(Settings *settings) noexcept;
    Field* getField() noexcept { return &field; }
    int getTime() const noexcept { return model_time; }
    int getDay() const noexcept { return model_day; }
    unsigned int getPredatorsNum() const noexcept { return this->units.predators.size(); }
    unsigned int getPreysNum() const noexcept { return units.preys.size(); }
    void movePreys() noexcept;
    void movePredators() noexcept;
    bool isEnd() const noexcept;
    void createPredators() noexcept;
    void createPreys() noexcept;
    void removePredators() noexcept;
    void removePreys() noexcept;
    void remove() noexcept;

    void saveModel();
    void loadModel();

};

#endif // MODEL_H
