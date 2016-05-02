#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent, Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint)
{
    setFixedSize(screen_size);
}
