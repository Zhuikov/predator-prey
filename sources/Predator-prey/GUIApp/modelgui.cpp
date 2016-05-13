#include "modelgui.h"

ModelGUI::ModelGUI(int argc, char *argv[]):
    model(nullptr),
    argc(argc),
    argv(argv)
{
    settings = new Settings;
}

int ModelGUI::startGUI()
{
    model = new Model(settings);

    QApplication GUIapp(argc, argv);
    MainMenu menu(nullptr, settings);
    menu.show();

    return GUIapp.exec();
}

ModelGUI::~ModelGUI()
{
    delete model;
    delete settings;
}
