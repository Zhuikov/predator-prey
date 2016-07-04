#ifndef MODEL_H
#define MODEL_H
#include "modelapi.h"
#include "units.h"
#include "settings.h"
#include <vector>
#include <ctime>

class Model : public ModelAPI
{
    Settings* settings;
    int model_step;
    Field field;

    /**
     * @brief Units - класс, в котором содержатся векторы юнитов: хищников, жертв и травы
     */
    Units units;

public:
    explicit Model(Settings *settings) noexcept;
    Field* getField() noexcept override { return &field; }
    int getStep() const noexcept override { return model_step; }
    unsigned int getPredatorsNum() const noexcept override { return units.predatorsNum; }
    unsigned int getPreysNum() const noexcept override { return units.preysNum; }
    unsigned int getGrassNum() const noexcept override { return units.grassNum; }
    void movePreys() noexcept override;
    void movePredators() noexcept override;
    bool isEnd() const noexcept override;
    void createPredators() noexcept override;
    void createPreys() noexcept override;
    void createGrass() noexcept override;
    void move() noexcept override;
};



#endif // MODEL_H
