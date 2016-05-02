#include "consoleapp.h"
#include "badfield.h"
#include "unistd.h"

void ConsoleApp::startModel()
{
    this->model->initializeModel();
    this->drawer->showModel();
    while (model->isEnd() == false) {
        usleep(time_for_sleep);
        this->model->movePredators();
        this->model->movePreys();
        this->model->remove();
        this->drawer->showModel();
    }
    this->drawer->showResult();
}

ConsoleApp::ConsoleApp()
{
    this->settings = new Settings;
    this->dialog = new ConsoleDialog(this->settings);
    this->model = new Model(this->settings);
    this->drawer = new ConsoleDrawer(this->model);
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
    delete this->drawer;
    delete this->dialog;
    delete this->model;
}

