#ifndef MODELWINDOW_H
#define MODELWINDOW_H
#include <QtWidgets>
#include <QPainter>
#include "model.h"
#include "mainmenu.h"
#include "fieldframe.h"
#include "statusframe.h"

class StatusFrame;

class ModelWindow : public QWidget
{
    Q_OBJECT

    Settings* settings;
    Model* model;

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 180,  30 };
    const int TIME_FOR_MOVE = 250;              // 500

    QPushButton* menu_button;
    QPushButton* start_button;
    QPushButton* generate_button;
    QTimer* timer;

    FieldFrame* field;
    StatusFrame* status;

    void endModel();

public:
    ModelWindow(QWidget* parent, Settings* settings);
    ~ModelWindow();

private slots:
    void exitToMenu();
    void startModel();
    void moveModel();
    void generateModel();
};

#endif // MODELWINDOW_H
