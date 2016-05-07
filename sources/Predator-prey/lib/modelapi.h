#ifndef MODELAPI_H
#define MODELAPI_H
#include "units.h"
#include "field.h"
#include <vector>

//TODO расставить модификаторы noexcept для методов, которые не возбуждают исключений
class ModelAPI
{
public:

    /**
     * @brief метод, возвращающий указатель на поле модели
     */
    virtual Field* getField() noexcept = 0;

    /**
     * @brief метод, возвращающий текущее время
     */
    virtual int getTime() const noexcept = 0;

    /**
     * @brief метод, вовращающий текущий день
     */
    virtual int getDay() const noexcept = 0;

    /**
     * @brief метод, возвращающий количество хищников на поле
     */
    virtual unsigned int getPredatorsNum() const noexcept = 0;

    /**
     * @brief метод, возвращающий количество жертв на поле
     */
    virtual unsigned int getPreysNum() const noexcept = 0;

    /**
     * @brief метод, проверяющий, не исчезли ли хищники или жертвы
     */
    virtual bool isEnd() const noexcept = 0;

    /**
     * @brief метод, создающий хищников
     */
    virtual void createPredators() noexcept = 0;

    /**
     * @brief метод, создающий жертв
     */
    virtual void createPreys() noexcept = 0;

    /**
     * @brief метод, удаляющий умерших хищников после хода
     */
    virtual void removePredators() noexcept = 0;

    /**
     * @brief метод, удаляющий умерших жертв после хода
     */
    virtual void removePreys() noexcept = 0;

    /**
     * @brief метод, передвигающий жертв
     */
    virtual void movePreys() noexcept = 0;

    /**
     * @brief метод, передвигающий хищников
     */
    virtual void movePredators() noexcept = 0;

    void saveModel();
    void loadModel();

    virtual ~ModelAPI() {}
};
#endif // MODELAPI_H
