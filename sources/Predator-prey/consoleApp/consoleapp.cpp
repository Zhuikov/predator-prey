#include "consoleapp.h"
#include "badfield.h"
#include "unistd.h"
//#include <iostream>

void ConsoleApp::startModel()
{
    this->model->initializeModel();
    this->drawer->showModel();
    while (model->isEnd() == false) {
        usleep(500000);
        this->model->movePredators();
        this->model->movePreys();
        this->model->remove();
        this->drawer->showModel();
    }
    this->drawer->showResult();
    //std::cin.ignore(100, '\n');
}

ConsoleApp::ConsoleApp()
{
    this->sett = new Settings;
    this->dialog = new ConsoleDialog(this->sett);
    this->model = new Model(this->sett);
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
    delete this->sett;
    delete this->drawer;
    delete this->dialog;
    delete this->model;
}

