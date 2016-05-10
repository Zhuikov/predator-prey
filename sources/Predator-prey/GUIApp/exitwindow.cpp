#include "exitwindow.h"

ExitWindow::ExitWindow(QWidget* parent)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Подтверждение выхода");

    yes_button = new QPushButton("Да", this);
    yes_button->resize(BUTTON_SIZE);
    yes_button->setStyleSheet(button_style);
    yes_button->move(WINDOW_SIZE.width() - 175, WINDOW_SIZE.height() - 60);

    no_button = new QPushButton("Нет", this);
    no_button->resize(BUTTON_SIZE);
    no_button->setStyleSheet(button_style);
    no_button->move(WINDOW_SIZE.width() - 125, WINDOW_SIZE.height() - 60);

}
