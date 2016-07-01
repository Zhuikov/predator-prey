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
    step_number_label = new QLabel(this);
    step_number_label->resize(70, 30);

    predators = new QLabel(this);
    fillLabel(predators, "Predators", 10, 10);

    preys = new QLabel(this);
    fillLabel(preys, "Preys", 43, 90);

    grass = new QLabel(this);
    fillLabel(grass, "Grass", 43, 170);

    step = new QLabel(this);
    fillLabel(step, "Step", 50, 250);
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

    output_string = QString::number(model->getStep(), 10);
    fillLabel(step_number_label, output_string, 60, 285);
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
    painter.fillRect(107, 96, 25, 15, brush);
    brush.setColor(Qt::green);
    painter.fillRect(107, 176, 25, 15, brush);
}
