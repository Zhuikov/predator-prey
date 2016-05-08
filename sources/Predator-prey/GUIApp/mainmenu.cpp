#include "mainmenu.h"

MainMenu::MainMenu(QWidget* parent)
{
    this->setFixedSize(SCREEN_SIZE);

    exit_button = new QPushButton(this);
   // exit_button->setStyleSheet(button_style);
    exit_button->setText("Выход");
    exit_button->resize(BUTTON_SIZE);
}
