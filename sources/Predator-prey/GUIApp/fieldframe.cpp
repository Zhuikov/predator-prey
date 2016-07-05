#include "fieldframe.h"
#include <QPainter>
#include <QBrush>

FieldFrame::FieldFrame(QWidget *parent, Field* field) :
    QFrame(parent),
    field(field)
{
    this->parent = parent;
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
    Unit* position;
    for (int i = 0; i < field->getHeight(); i++) {
        for (int j = 0; j < field->getLength(); j++) {
            position = field->getPosition(i, j);
            if (position != nullptr)
            {
                drawUnit(painter, position);
            }
        }
    }
}

void FieldFrame::drawUnit(QPainter &painter, Unit* unit)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if ( unit->getType() == UnitType::PREDATOR ) brush.setColor(Qt::red);
    else if ( unit->getType() == UnitType::PREY ) brush.setColor(Qt::blue);
    else if ( unit->getType() == UnitType::GRASS ) brush.setColor(Qt::green);

    int vertical = unit->getPlace().getV();
    int horizontal = unit->getPlace().getH();

//    if (unit->getCurrentStep() <= 50)       /// brain.limit
//    {
//        painter.fillRect(horizontal * cell_size + LINE_WIDTH_DELTA + cell_size / 5,
//                         vertical * cell_size + LINE_WIDTH_DELTA + cell_size / 5,
//                         cell_size - 2 * LINE_WIDTH_DELTA - cell_size / 5,
//                         cell_size - 2 * LINE_WIDTH_DELTA - cell_size / 5,
//                         brush);
//    }
//    else
//    {
        painter.fillRect(horizontal * cell_size + LINE_WIDTH_DELTA,
                         vertical * cell_size + LINE_WIDTH_DELTA,
                         cell_size - 2 * LINE_WIDTH_DELTA,
                         cell_size - 2 * LINE_WIDTH_DELTA,
                         brush);
//    }
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
