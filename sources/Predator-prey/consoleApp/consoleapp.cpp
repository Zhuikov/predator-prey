#include "consoleapp.h"
#include "exceptions.h"
#include <iostream>


ConsoleApp::ConsoleApp()
{
    this->CD = new ConsoleDialog;
    this->sett = new Settings;
    this->model = new ModelPP(this->sett);
    this->drawer = new ConsoleDrawer(this->model->getField(), this->model);
}

void ConsoleApp::createConsole()
{
    int flag;
    bool end = false;
    int x = 0;
    while (!end) {
        flag = this->CD->menuPresentation();
        switch (flag) {
            case 1: {
                this->model->initializeModel();
                while (!model->isEnd()) {
                    this->drawer->showField();
                    this->model->movePreys();
                //    this->drawer->showField();
                    this->model->movePredators();
                    std::cin >> x;
                    if (x == 0) break;
                }
                break;
            }
            case 3: {
                try {
                    this->CD->settingsPresentation(this->sett);
                }
                catch (BadFieldBoundary& e)
                {
                    e.showMessage();
                }
                catch (BadNumOfPredators& e)
                {
                    e.showMessage();
                }
                catch (BadNumOfPreys& e)
                {
                    e.showMessage();
                }

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

