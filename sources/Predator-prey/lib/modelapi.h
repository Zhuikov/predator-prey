#ifndef MODELAPI_H
#define MODELAPI_H
#include "units.h"
#include "field.h"
#include <vector>


//TODO я в точности не знаю, зачем здесь эти объявления, ведь и без них все ок вроде
//class Predator;
//class Units;
//class Prey;

//TODO расставить модификаторы noexcept для методов, которые не возбуждают исключений
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
     * @brief метод, создающий хищников
     */
    virtual void createPredators() = 0;

    /**
     * @brief метод, полностью очищающий вектор хищников
     */
    virtual void deletePredators() = 0;

    /**
     * @brief метод, создающий жертв
     */
    virtual void createPreys() = 0;

    /**
     * @brief dметод, полностью очищающий вектор жертв
     */
    virtual void deletePreys() = 0;

    /**
     * @brief метод, удаляющий умерших хищников после хода
     */
    virtual void removePredators() = 0;

    /**
     * @brief метод, удаляющий умерших жертв после хода
     */
    virtual void removePreys() = 0;

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
