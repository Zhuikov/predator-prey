#include "statusframe.h"
#include <QPainter>

StatusFrame::StatusFrame(QWidget* parent, Model* model) : QFrame(parent)
{
    this->model = model;
    this->setFixedSize(FRAME_SIZE);
    this->move(PLACE);
    this->setLineWidth(2);
    this->setFrameStyle(QFrame::Box | QFrame::Plain);

    number_label = new QLabel(this);
    predators = createLabel("Хищники", 10, 10);
    preys = createLabel("Жертвы", 18, 110);
    day = createLabel("День", 48, 210);
    time = createLabel("Время", 43, 310);
}

QLabel* StatusFrame::createLabel(QString text, int horizontal, int vertical)
{
    QLabel* label = new QLabel(this);
    label->setStyleSheet(label_style);
    label->move(horizontal, vertical);
    label->setText(text);
    label->show();

    return label;
}

//void StatusFrame::drawStatus()
//{
//    QString output_string = QString::number(model->getPredatorsNum(), 10);
//    number_label->setText(output_string);
//    number_label->setStyleSheet(label_style);
//    number_label->move(40, 50);
//    number_label->show();
//}

void StatusFrame::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    painter.fillRect(115, 16, 25, 15, brush);

    brush.setColor(Qt::blue);
    painter.fillRect(110, 116, 25, 15, brush);


   // drawStatus();
}
