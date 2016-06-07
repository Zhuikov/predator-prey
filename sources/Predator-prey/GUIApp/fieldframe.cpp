#include "fieldframe.h"
#include <QPainter>
#include <QBrush>

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

    cell_size = FIELD_SIDE / std::max(field->getLength(), field->getHeight());
}

void FieldFrame::createField(QPainter &painter)
{
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    field_size.setHeight(field->getHeight() * cell_size);
    field_size.setWidth (field->getLength() * cell_size);

    int vert_line_coordX = 0;
    painter.drawLine(vert_line_coordX + LINE_WIDTH_DELTA, 0, vert_line_coordX + LINE_WIDTH_DELTA, field_size.height());
    for (int i = 0; i < field->getLength(); i++) {
        vert_line_coordX += cell_size;
        painter.drawLine(vert_line_coordX, 0, vert_line_coordX, field_size.height());
    }

    int horiz_line_coordY = 0;
    painter.drawLine(0, horiz_line_coordY + LINE_WIDTH_DELTA, field_size.width(), horiz_line_coordY + LINE_WIDTH_DELTA);
    for (int i = 0; i < field->getHeight(); i++) {
        horiz_line_coordY += cell_size;
        painter.drawLine(0, horiz_line_coordY, field_size.width(), horiz_line_coordY);
    }
    field_size.setWidth (vert_line_coordX + LINE_WIDTH_DELTA);
    field_size.setHeight(horiz_line_coordY + LINE_WIDTH_DELTA);

    this->setFixedSize(field_size);

}

void FieldFrame::createUnits(QPainter &painter)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    for (int i = 0; i < field->getHeight(); i++) {
        for (int j = 0; j < field->getLength(); j++) {
            switch (field->getPosition(i, j) ) {
            case UnitType::PREDATOR : {
                        brush.setColor(Qt::red);
                        painter.fillRect(j * cell_size + LINE_WIDTH_DELTA,
                                         i * cell_size + LINE_WIDTH_DELTA,
                                         cell_size - 2 * LINE_WIDTH_DELTA,
                                         cell_size - 2 * LINE_WIDTH_DELTA,
                                         brush);
                        break;
            }
            case UnitType::PREY : {
                        brush.setColor(Qt::blue);
                        painter.fillRect(j * cell_size + LINE_WIDTH_DELTA,
                                         i * cell_size + LINE_WIDTH_DELTA,
                                         cell_size - 2 * LINE_WIDTH_DELTA,
                                         cell_size - 2 * LINE_WIDTH_DELTA,
                                         brush);
            }
            default : {}
            }
        }
    }
}

void FieldFrame::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    createField(painter);
    createUnits(painter);
    this->move(FIELD_PLACE.x() + (FieldFrame::FIELD_SIDE - this->width()) / 2,
               FIELD_PLACE.y() + (FieldFrame::FIELD_SIDE - this->height()) / 2);
}
