#include "modelwindow.h"

ModelWindow::ModelWindow(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
    this->settings = settings;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Хищник-жертва");

    model = new Model(this->settings);

    QPixmap background(":/settings_texture2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    menu_button = new QPushButton("Выйти в меню", this);
    menu_button->setStyleSheet(button_style);
    menu_button->resize(BUTTON_SIZE);
    menu_button->move(WINDOW_SIZE.width() - 640, WINDOW_SIZE.height() - 515);
    connect(menu_button, SIGNAL(clicked()), SLOT(exitToMenu()));

    FieldFrame* field = new FieldFrame(this, model->getField());
    field->show();

    StatusFrame* status = new StatusFrame(this, model);
    status->show();
}

void ModelWindow::exitToMenu()
{
    MainMenu* menu_window = new MainMenu(0, settings);
    menu_window->move(this->x(), this->y());
    menu_window->show();
    this->close();
}
