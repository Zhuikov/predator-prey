#include "mainmenu.h"
#include "unistd.h"

MainMenu::MainMenu(QWidget* parent, Settings* settings) : QWidget(parent, Qt::WindowTitleHint)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Хищник-жертва");
    this->settings = settings;

    QPixmap background(":/background2.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);

    new_model_button = new QPushButton("Новая модель", this);
    new_model_button->setStyleSheet(button_style);
    new_model_button->resize(BUTTON_SIZE);
    new_model_button->move(WINDOW_SIZE.width() - 200,
                           WINDOW_SIZE.height() - 500);
    connect(new_model_button, SIGNAL(clicked()), SLOT(createModel()));

    settings_button = new QPushButton("Настройки", this);
    settings_button->setStyleSheet(button_style);
    settings_button->resize(BUTTON_SIZE);
    settings_button->move(WINDOW_SIZE.width() - 200,
                          WINDOW_SIZE.height() - 450);
    connect(settings_button, SIGNAL(clicked()), SLOT(settingsMenu()));

    exit_button = new QPushButton("Выход", this);
    exit_button->setStyleSheet(button_style);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() - 200,
                      WINDOW_SIZE.height() - 400);
    connect(exit_button, SIGNAL(clicked()), SLOT(closeMenu()));

}

void MainMenu::closeMenu()
{
    ExitWindow* exit_menu = new ExitWindow(this);
    exit_menu->exec();
    delete exit_menu;
}

void MainMenu::settingsMenu()
{
    SettingsWindow* settings_menu = new SettingsWindow(0, settings);
    settings_menu->move(this->x(), this->y());
    settings_menu->show();
    this->close();
}

void MainMenu::createModel()
{
    ModelWindow* model_window = new ModelWindow(0, settings);
    model_window->move(this->x(), this->y());
    model_window->show();
    this->close();
}
