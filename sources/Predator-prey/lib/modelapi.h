#ifndef MODELAPI_H
#define MODELAPI_H
#include "units.h"
#include "field.h"
#include <vector>

class Predator;
class Units;
class Prey;

class ModelAPI
{
public:
    /**
     * @brief инициализация модели: создание поля, создание векторов с хищниками и жертвами
     */
    virtual void initializeModel() = 0;

    /**
     * @brief метод, возвращающий текущее время
     */
    virtual int getTime() = 0;

    /**
     * @brief метод, вовращающий текущий день
     */
    virtual int getDay() = 0;

    /**
     * @brief метод, проверяющий, не исчезли ли хищники или жертвы
     */
    virtual bool isEnd() = 0;

    /**
     * @brief метод, передвигающий жертв
     */
    virtual void movePreys() = 0;

    /**
     * @brief метод, передвигающий хищников
     */
    virtual void movePredators() = 0;
    void saveModel();
    void loadModel();

    virtual ~ModelAPI() {}
};
#endif // MODELAPI_H
