#include "statusframe.h"
#include <QPainter>

StatusFrame::StatusFrame(QWidget* parent, Model* model) : QFrame(parent)
{
    this->model = model;
    this->setFixedSize(FRAME_SIZE);
    this->move(PLACE);
    this->setLineWidth(2);
    this->setFrameStyle(QFrame::Box | QFrame::Plain);

    predators_number_label = new QLabel(this);
    predators_number_label->resize(50, 30);
    preys_number_label = new QLabel(this);
    preys_number_label->resize(50, 30);
    grass_number_label = new QLabel(this);
    grass_number_label->resize(50, 30);
    day_number_label = new QLabel(this);
    day_number_label->resize(50, 30);
    time_number_label = new QLabel(this);
    time_number_label->resize(65, 30);

    predators = new QLabel(this);
    fillLabel(predators, "Хищники", 10, 10);

    preys = new QLabel(this);
    fillLabel(preys, "Жертвы", 18, 90);

    grass = new QLabel(this);
    fillLabel(grass, "Трава", 33, 170);

    day = new QLabel(this);
    fillLabel(day, "День", 48, 250);

    time = new QLabel(this);
    fillLabel(time, "Время", 43, 330);
}

void StatusFrame::fillLabel(QLabel* label, QString text, int horizontal, int vertical)
{
    label->setStyleSheet(label_style);
    label->move(horizontal, vertical);
    label->setText(text);
    label->show();
}

void StatusFrame::drawStatus()
{
    QString output_string = QString::number(model->getPredatorsNum(), 10);
    if (model->getPredatorsNum() < 10) {
        fillLabel(predators_number_label, output_string, 65, 45);
    }
    else {
        fillLabel(predators_number_label, output_string, 60, 45);
    }

    output_string = QString::number(model->getPreysNum(), 10);
    if (model->getPreysNum() < 10) {
        fillLabel(preys_number_label, output_string, 65, 125);
    }
    else {
        fillLabel(preys_number_label, output_string, 60, 125);
    }

    output_string = QString::number(model->getGrassNum(), 10);
    if (model->getGrassNum() < 10) {
        fillLabel(grass_number_label, output_string, 65, 205);
    }
    else {
        fillLabel(grass_number_label, output_string, 60, 205);
    }

    output_string = QString::number(model->getDay(), 10);
    if (model->getDay() < 10) {
        fillLabel(day_number_label, output_string, 68, 285);
    }
    else {
        fillLabel(day_number_label, output_string, 63, 285);
    }

    output_string = QString::number(model->getTime(), 10);
    if (model->getTime() < 10) {
        output_string = "0" + output_string + ":00";
    }
    else {
        output_string = output_string + ":00";
    }
    fillLabel(time_number_label, output_string, 47, 365);
}

void StatusFrame::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    painter.fillRect(115, 16, 25, 15, brush);
    brush.setColor(Qt::blue);
    painter.fillRect(110, 96, 25, 15, brush);
    brush.setColor(Qt::green);
    painter.fillRect(105, 176, 25, 15, brush);
}
