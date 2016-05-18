#include "modelwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
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
    menu_button->move(WINDOW_SIZE.width() - 620, WINDOW_SIZE.height() - 515);
    connect(menu_button, SIGNAL(clicked()), SLOT(exitToMenu()));

    FieldFrame* field = new FieldFrame(this, model->getField());
    field->show();
}

void ModelWindow::exitToMenu()
{
    MainMenu* menu_window = new MainMenu(0, settings);
    menu_window->move(this->x(), this->y());
    menu_window->show();
    this->close();
}
