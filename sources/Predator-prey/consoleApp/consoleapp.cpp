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
    int flag = -1;
    bool end = false;
    int x = 1;
    while (!end) {
        if (flag != 10) flag = this->CD->menuPresentation();
                else flag = 3;
        switch (flag) {
            case 1: {
                this->model->initializeModel();
                while (!model->isEnd()) {
                    this->drawer->showField();
                    this->model->movePredators();
                    this->model->movePreys();
                    std::cin >> x;
                    if (x == 0) break;
                }
                this->drawer->showField();
                break;
            }

            case 3: {
                std::cout << std::endl;
                try {
                    this->CD->settingsPresentation(this->sett);
                }
                catch (BadFieldBoundary& e)
                {
                    e.showMessage();
                    flag = 10;
                }
                catch (BadNumOfPredators& e)
                {
                    e.showMessage();
                    flag = 10;
                }
                catch (BadNumOfPreys& e)
                {
                    e.showMessage();
                    flag = 10;
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

