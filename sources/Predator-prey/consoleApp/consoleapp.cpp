#include "consoleapp.h"
#include "exceptions.h"
#include <iostream>


void ConsoleApp::startModel()
{
    this->model->initializeModel();
    this->drawer->showModel();
    std::string x;
    while (model->isEnd() == false) {
        std::getline(std::cin, x);
        this->model->movePredators();
        this->model->movePreys();
        this->model->moveEnd();
        this->drawer->showModel();
        if (x == "0") break;
    }
    this->drawer->showResult();
}

ConsoleApp::ConsoleApp()
{
    this->sett = new Settings;
    this->CD = new ConsoleDialog(this->sett);
    this->model = new ModelPP(this->sett);
    this->drawer = new ConsoleDrawer(this->model);
}

void ConsoleApp::createConsole()
{
    int menuChoice = -1;
    bool end = false;
    while (!end) {
        menuChoice = this->CD->mainMenuPresentation();
        switch (menuChoice) {
            case 1: {
                this->startModel();
                break;
            }

            case 2: {
                std::cout << std::endl;
                CD->settingsMenuPresentation();
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
    delete this->CD;
    delete this->model;
}

