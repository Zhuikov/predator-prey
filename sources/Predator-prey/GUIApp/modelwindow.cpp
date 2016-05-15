#include "modelwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Model* model)
{
    this->parent = parent;
    this->model = model;
    this->setFixedSize(WINDOW_SIZE);

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    menu_button = new QPushButton("Выйти в меню", this);
    menu_button->setStyleSheet(button_style);
    menu_button->resize(BUTTON_SIZE);
    menu_button->move(WINDOW_SIZE.width() - 600, WINDOW_SIZE.height() - 500);
    connect(menu_button, SIGNAL(clicked()), SLOT(exitToMenu()));

}

void ModelWindow::exitToMenu()
{
    parent->move(this->x(), this->y());
    parent->show();
    this->close();
}
