#include "consoleapp.h"
#include "badfield.h"
#include "unistd.h"

void ConsoleApp::startModel()
{
    this->model = new Model(this->settings);
    this->drawer = new ConsoleDrawer(this->model);

    this->drawer->showModel();
    while (model->isEnd() == false) {
        usleep(TIME_FOR_SLEEP);
        this->model->movePredators();
        this->model->movePreys();
        this->model->remove();
        this->drawer->showModel();
    }
    this->drawer->showResult();
    delete this->drawer;
    delete this->model; // ???
}

ConsoleApp::ConsoleApp():
    drawer(nullptr),
    model(nullptr)
{
    this->settings = new Settings;
    this->dialog = new ConsoleDialog(this->settings);
}

void ConsoleApp::createConsole()
{
    int menuChoice = 0;
    bool end = false;
    while (!end) {
        menuChoice = this->dialog->mainMenuPresentation();
        switch (menuChoice) {
            case 1: {
                this->startModel();
                break;
            }

            case 2: {
                dialog->settingsMenuPresentation();
                break;
            }

            case 0: {
                end = true;
            }
        }
    }
}

ConsoleApp::~ConsoleApp()
{
    delete this->settings;
    delete this->dialog;
}

