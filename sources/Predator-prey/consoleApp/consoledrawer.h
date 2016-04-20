#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H
#include "modelpp.h"

class ConsoleDrawer
{
    Field *field;
    ModelPP *model;

    /**
     * @brief метод выводящий в консоль легенду
     */
    void drawLegend();

    /**
     * @brief метод, выводящий в консоль текущие день и время модели
     */
    void drawHead();

    /**
     * @brief метод, выводящий в консоль статистику:
     * количество хищников и жертв на поле
     */
    void drawStatistics();

    /**
     * @brief метод, рисующий текущее состояние поля
     */
    void drawField();

public:
    ConsoleDrawer(ModelPP *model): field(model->getField()), model(model) {}

    /**
     * @brief метод, выводящий в консоль всю текущую информацию о модели
     */
    void showModel();

    /**
     * @brief метод, выводящий в консоль результат (победителей)
     */
    void showResult();
};

#endif // CONSOLEDRAWER_H
