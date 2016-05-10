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

    settings_button = new QPushButton("Настройки", this);
    settings_button->setStyleSheet(button_style);
    settings_button->resize(BUTTON_SIZE);
    settings_button->move(WINDOW_SIZE.width() / 2 - BUTTON_SIZE.width() / 2,
                      WINDOW_SIZE.height() / 2 - BUTTON_SIZE.height() / 2 + 150);

    exit_button = new QPushButton("Выход", this);
    exit_button->setStyleSheet(button_style);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() / 2 - BUTTON_SIZE.width() / 2,
                      WINDOW_SIZE.height() / 2 - BUTTON_SIZE.height() / 2 + 200);
    connect(exit_button, SIGNAL(clicked()), SLOT(close_window()));
}

void MainMenu::close_window()
{
    ExitWindow exit_window(this);
    exit_window.show();
}
