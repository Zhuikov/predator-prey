#ifndef STATUSFRAME_H
#define STATUSFRAME_H
#include <QtWidgets>
#include "model.h"
#include "modelwindow.h"

class ModelWindow;

class StatusFrame : public QFrame
{
    Q_OBJECT

    const QSize FRAME_SIZE { 150, 450 };
    const QPoint PLACE { 500, 80 };
    Model* model;

    QLabel* predators;
    QLabel* preys;
    QLabel* grass;
    QLabel* step;
//    QLabel* day;
//    QLabel* time;

    QString label_style =
            "color: #122faa;"
            "font-size: 20px;"
            "font-weight: bold;";
    QLabel* predators_number_label;
    QLabel* preys_number_label;
    QLabel* grass_number_label;
    QLabel* step_number_label;
//    QLabel* day_number_label;
//    QLabel* time_number_label;

    void fillLabel(QLabel*, QString, int, int);
    void paintEvent(QPaintEvent*);

public:
    StatusFrame(QWidget* parent, Model* model);
    void drawStatus();
};

#endif // STATUSFRAME_H
