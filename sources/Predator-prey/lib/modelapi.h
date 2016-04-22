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
     * @brief метод, возвращающий указатель на поле модели
     */
    virtual Field* getField() = 0;

    /**
     * @brief метод, возвращающий текущее время
     */
    virtual int getTime() const = 0;

    /**
     * @brief метод, вовращающий текущий день
     */
    virtual int getDay() const = 0;

    /**
     * @brief метод, возвращающий количество хищников на поле
     */
    virtual unsigned int getPredatorsNum() const = 0;

    /**
     * @brief метод, возвращающий количество жертв на поле
     */
    virtual unsigned int getPreysNum() const = 0;

    /**
     * @brief метод, проверяющий, не исчезли ли хищники или жертвы
     */
    virtual bool isEnd() const = 0;

    /**
     * @brief метод, удаляющий умерших хищников и жертв после хода
     */
    virtual void remove() = 0;
    
    virtual void createPredators() = 0;
    virtual void deletePredators() = 0;
    virtual void createPreys() = 0;
    virtual void deletePreys() = 0;

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
