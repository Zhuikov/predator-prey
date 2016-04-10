#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H
#include "modelpp.h"

class ConsoleDrawer
{
    Field *field;
    ModelPP *model;

    void drawHead();
    void drawField();

public:
    ConsoleDrawer(Field *field, ModelPP *model): field(field), model(model) {}
    void showField();
};

#endif // CONSOLEDRAWER_H
