#ifndef STATUSFRAME_H
#define STATUSFRAME_H
#include <QtWidgets>
#include "model.h"

class StatusFrame : public QFrame
{
    Q_OBJECT

    const QSize FRAME_SIZE { 150, 450 };
    const QPoint PLACE { 500, 80 };
    Model* model;

    QString label_style =
                "color: #122faa;"
                "font-size: 20px;"
                "font-weight: bold;";
    QLabel* predators;
    QLabel* preys;
    QLabel* day;
    QLabel* time;
    QLabel* number_label;

    QLabel* createLabel(QString, int, int);
//    void drawStatus();
    void paintEvent(QPaintEvent*);

public:
    StatusFrame(QWidget* parent, Model* model);
};

#endif // STATUSFRAME_H
