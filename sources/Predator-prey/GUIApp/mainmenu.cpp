#include "mainmenu.h"

MainMenu::MainMenu(QWidget* parent)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Хищник-жертва");

    QPixmap background(":/background2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    new_model_button = new QPushButton("Новая модель", this);
    new_model_button->setStyleSheet(button_style);
    new_model_button->resize(BUTTON_SIZE);
    new_model_button->move(WINDOW_SIZE.width() - 170,
                           WINDOW_SIZE.height() / 2 - BUTTON_SIZE.height() / 2 + 135);

    settings_button = new QPushButton("Настройки", this);
    settings_button->setStyleSheet(button_style);
    settings_button->resize(BUTTON_SIZE);
    settings_button->move(WINDOW_SIZE.width() - 170,
                          WINDOW_SIZE.height() / 2 - BUTTON_SIZE.height() / 2 + 180);

    exit_button = new QPushButton("Выход", this);
    exit_button->setStyleSheet(button_style);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() - 170,
                      WINDOW_SIZE.height() / 2 - BUTTON_SIZE.height() / 2 + 225);
    connect(exit_button, SIGNAL(clicked()), SLOT(close_menu()));

}

void MainMenu::close_menu()
{
    exit_menu = new ExitWindow(this);
    exit_menu->exec();
    delete exit_menu;
}
