#include "mainmenu.h"
#include <QtWidgets>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainMenu menu(0);
    menu.show();

    return a.exec();
}
