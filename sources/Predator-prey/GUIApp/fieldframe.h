#ifndef FIELDFRAME_H
#define FIELDFRAME_H

#include "field.h"
#include <QFrame>

class FieldFrame : public QFrame
{
    Q_OBJECT

    QSize field_size;
    Field* field;
    const QPoint FIELD_PLACE { 30, 80 };
    static constexpr int LINE_WIDTH_DELTA = 1;

    QWidget* parent;

    int cell_size;
    void createField(QPainter &painter);
    void createUnits(QPainter &painter);
    void paintEvent(QPaintEvent*);

public:
    FieldFrame(QWidget *parent, Field*);
    static constexpr int FIELD_SIDE = 450;
};

#endif // FIELDFRAME_H
