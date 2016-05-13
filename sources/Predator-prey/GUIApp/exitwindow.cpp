#include "exitwindow.h"

ExitWindow::ExitWindow(QWidget* parent) : QDialog(parent, Qt::WindowTitleHint)
{
    this->parent = parent;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Подтверждение выхода");

    QPixmap background(":/texture.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    exit_label =  new QLabel(this);
    exit_label->setStyleSheet(
                "color: #122faa;"
                "font-size: 15px;"
                "font-weight: bold;");
    exit_label->move(WINDOW_SIZE.width() - 283, WINDOW_SIZE.height()  - 80);
    exit_label->setText("Вы действительно хотите выйти?");
    exit_label->show();

    yes_button = new QPushButton("Да", this);
    yes_button->resize(BUTTON_SIZE);
    yes_button->setStyleSheet(button_style);
    yes_button->move(WINDOW_SIZE.width() - 275, WINDOW_SIZE.height() - 50);
    connect(yes_button, SIGNAL(clicked()), SLOT(closeApp()));

    no_button = new QPushButton("Нет", this);
    no_button->resize(BUTTON_SIZE);
    no_button->setStyleSheet(button_style);
    no_button->move(WINDOW_SIZE.width() - 125, WINDOW_SIZE.height() - 50);
    connect(no_button, SIGNAL(clicked()), SLOT(closeExitWindow()));
}

void ExitWindow::closeApp()
{
    this->close();
    this->parent->close();
    delete this;
}

void ExitWindow::closeExitWindow()
{
    this->close();
    delete this;
}
