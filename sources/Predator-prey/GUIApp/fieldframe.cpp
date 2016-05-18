#include "fieldframe.h"
#include <QPainter>

FieldFrame::FieldFrame(QWidget *parent, Field* field) : QFrame(parent)
{
    this->field = field;
    this->parent = parent;
    cell_size = 0;
    field_size.setHeight(FIELD_SIDE);
    field_size.setWidth(FIELD_SIDE);

    QPalette pal;
    pal.setBrush(this->backgroundRole(), Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void FieldFrame::createField(QPainter &painter)
{
    cell_size = FIELD_SIDE / std::max(field->getLength(), field->getHeight());

    field_size.setHeight(field->getHeight() * cell_size);
    field_size.setWidth (field->getLength() * cell_size);

    int vert_line_coordX = 0;
    painter.drawLine(vert_line_coordX + 1, 0, vert_line_coordX + 1, field_size.height());
    for (int i = 0; i < field->getLength(); i++) {
        vert_line_coordX += cell_size;
        painter.drawLine(vert_line_coordX, 0, vert_line_coordX, field_size.height());
    }

    int horiz_line_coordY = 0;
    painter.drawLine(0, horiz_line_coordY + 1, field_size.width(), horiz_line_coordY + 1);
    for (int i = 0; i < field->getHeight(); i++) {
        horiz_line_coordY += cell_size;
        painter.drawLine(0, horiz_line_coordY, field_size.width(), horiz_line_coordY);
    }
    field_size.setWidth (vert_line_coordX + 1);
    field_size.setHeight(horiz_line_coordY + 1);

    this->setFixedSize(field_size);
    this->move(field_place.x() + (FieldFrame::FIELD_SIDE - this->width()) / 2,
               field_place.y() + (FieldFrame::FIELD_SIDE - this->height()) / 2);
}

void FieldFrame::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    createField(painter);
    this->setFixedSize(field_size);
}
