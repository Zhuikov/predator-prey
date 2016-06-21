#ifndef MODELAPI_H
#define MODELAPI_H
#include "field.h"
#include <vector>

/**
 * @brief класс, предоставляющий методы ядра
 */
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
     * @brief метод, возвращающий текущий шаг
     */
    virtual int getStep() const noexcept = 0;

    /**
     * @brief метод, возвращающий количество хищников на поле
     */
    virtual unsigned int getPredatorsNum() const noexcept = 0;

    /**
     * @brief метод, возвращающий количество жертв на поле
     */
    virtual unsigned int getPreysNum() const noexcept = 0;

    /**
     * @brief метод, возвращающий количество травы на поле
     */
    virtual unsigned int getGrassNum() const noexcept = 0;

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
     * @brief метод, создающий корм для жертв
     */
    virtual void createGrass() noexcept = 0;

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
