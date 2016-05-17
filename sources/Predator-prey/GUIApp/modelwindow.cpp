#include "modelwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
    this->parent = parent;
    this->settings = settings;
    this->setFixedSize(WINDOW_SIZE);
    model = new Model(this->settings);

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    menu_button = new QPushButton("Выйти в меню", this);
    menu_button->setStyleSheet(button_style);
    menu_button->resize(BUTTON_SIZE);
    menu_button->move(WINDOW_SIZE.width() - 600, WINDOW_SIZE.height() - 500);
    connect(menu_button, SIGNAL(clicked()), SLOT(exitToMenu()));

    //drawField(model->getField());

}

void ModelWindow::drawField(Field *field)
{
//    QPainter painter(this);
//    QBrush brush(Qt::black, Qt::SolidPattern);
//    painter.drawRect(100, 100, 200, 200);
//    wgt = new QWidget(this);
//    wgt->setFixedSize(200, 300);
//    wgt->move(200, 200);
//    wgt->show();
}

void ModelWindow::exitToMenu()
{
    parent->move(this->x(), this->y());
    parent->show();
    this->close();
}
