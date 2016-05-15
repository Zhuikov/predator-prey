#include "modelgui.h"

ModelGUI::ModelGUI(int argc, char *argv[]):
    argc(argc),
    argv(argv)
{
    settings = new Settings;
}

int ModelGUI::startGUI()
{
    QApplication GUIapp(argc, argv);
    MainMenu menu(nullptr, settings);
    menu.show();

    return GUIapp.exec();
}

ModelGUI::~ModelGUI()
{
    delete settings;
}
