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
    new_model_button->move(WINDOW_SIZE.width() - 200,
                           WINDOW_SIZE.height() - 500);

    settings_button = new QPushButton("Настройки", this);
    settings_button->setStyleSheet(button_style);
    settings_button->resize(BUTTON_SIZE);
    settings_button->move(WINDOW_SIZE.width() - 200,
                          WINDOW_SIZE.height() - 450);
    connect(settings_button, SIGNAL(clicked()), SLOT(settings_menu()));

    exit_button = new QPushButton("Выход", this);
    exit_button->setStyleSheet(button_style);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() - 200,
                      WINDOW_SIZE.height() - 400);
    connect(exit_button, SIGNAL(clicked()), SLOT(close_menu()));

}

void MainMenu::close_menu()
{
    ExitWindow* exit_menu = new ExitWindow(this);
    exit_menu->exec();
    delete exit_menu;
}

void MainMenu::settings_menu()
{
    SettingsWindow* settings_menu = new SettingsWindow(this);
    this->hide();
    settings_menu->exec();
    delete settings_menu;
}
