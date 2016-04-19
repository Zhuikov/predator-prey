#include "consoleapp.h"
#include "exceptions.h"
#include <iostream>


ConsoleApp::ConsoleApp()
{
    this->sett = new Settings;
    this->CD = new ConsoleDialog(this->sett);
    this->model = new ModelPP(this->sett);
    this->drawer = new ConsoleDrawer(this->model);
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
                this->drawer->showField();
                while (!model->isEnd()) {
                    std::cin >> x;
                    this->model->movePredators();
                    this->model->moveEnd();
                    this->model->movePreys();
                    this->model->moveEnd();
                    this->drawer->showField();
                    if (x == 0) break;
                }
                break;
            }

            case 3: {
                std::cout << std::endl;
                try {
                    this->CD->settingsPresentation();
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
                catch (BadMovesWithoutMeal& e)
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

