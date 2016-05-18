#ifndef MODELWINDOW_H
#define MODELWINDOW_H
#include <QtWidgets>
#include <QPainter>
#include "model.h"
#include "mainmenu.h"

class ModelWindow : public QWidget
{
    Q_OBJECT

    Settings* settings;
    Model* model;

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 180,  30 };

    QPushButton* menu_button;

    void drawField(Field* field);

public:
    ModelWindow(QWidget* parent, Settings *settings);

private slots:
    void exitToMenu();
};

#endif // MODELWINDOW_H
