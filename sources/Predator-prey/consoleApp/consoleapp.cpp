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
    std::string x;
    while (!end) {
        if (flag != 10) flag = this->CD->menuPresentation();
                else flag = 2;

        switch (flag) {

            case 1: {
                this->model->initializeModel();
                this->drawer->showModel();
                while (model->isEnd() == false) {
                    std::getline(std::cin, x);
                    this->model->movePredators();
                    this->model->movePreys();
                    this->model->moveEnd();
                    this->drawer->showModel();
                    if (x == "0") break;
                }
                this->drawer->showResult();
                break;
            }

            case 2: {
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

