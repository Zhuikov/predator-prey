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
    //todo возможно стоит сделать метод const?
    virtual Field* getField() = 0;

    /**
     * @brief метод, возвращающий текущее время
     */
    //todo возможно стоит сделать метод const?
    virtual int getTime() = 0;

    /**
     * @brief метод, вовращающий текущий день
     */
    //todo возможно стоит сделать метод const?
    virtual int getDay() = 0;

    /**
     * @brief метод, возвращающий количество хищников на поле
     */
    //todo возможно стоит сделать метод const?
    virtual unsigned int getPredatorsNum() = 0;

    /**
     * @brief метод, возвращающий количество жертв на поле
     */
    //todo возможно стоит сделать метод const?
    virtual unsigned int getPreysNum() = 0;

    /**
     * @brief метод, проверяющий, не исчезли ли хищники или жертвы
     */
    //todo возможно стоит сделать метод const?
    virtual bool isEnd() = 0;

    /**
     * @brief метод, удаляющий умерших хищников и жертв после хода
     */
    //todo move? лучше переименовать
    //хотя бы remove боло бы уже лучше
    virtual void moveEnd() = 0;

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
