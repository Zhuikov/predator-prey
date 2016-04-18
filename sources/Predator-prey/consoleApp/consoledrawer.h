#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H
#include "modelpp.h"

class ConsoleDrawer
{
    Field *field;
    ModelPP *model;

    /**
     * @brief метод, выводящий в консоль текущие день и время модели
     */
    void drawHead();

    /**
     * @brief метод, рисующий текущее состояние поля
     */
    void drawField();

public:
    ConsoleDrawer(Field *field, ModelPP *model): field(field), model(model) {}

    /**
     * @brief метод, выводящий в консоль всю текущую информацию о модели
     */
    void showField();
};

#endif // CONSOLEDRAWER_H
