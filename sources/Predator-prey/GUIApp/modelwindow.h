#ifndef MODELWINDOW_H
#define MODELWINDOW_H
#include <QtWidgets>
#include "model.h"
#include "mainmenu.h"

class ModelWindow : public QDialog
{
    Q_OBJECT

    QWidget* parent;
    Model* model;

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 180,  30 };

    QPushButton* menu_button;

public:
    ModelWindow(QWidget* parent, Model* model);

private slots:
    void exitToMenu();
};

#endif // MODELWINDOW_H
