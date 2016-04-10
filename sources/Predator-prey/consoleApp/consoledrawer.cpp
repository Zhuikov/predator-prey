#include "consoledrawer.h"
#include <iostream>

void ConsoleDrawer::showField()
{
    this->drawHead();
    this->drawField();
}

void ConsoleDrawer::drawHead()
{
    int num_of_stars_left;
    int num_of_stars_right;

    num_of_stars_left = (this->field->getNumOfCols() * 2 - 17) / 2;
    num_of_stars_right = (this->field->getNumOfCols() * 2 - 17 - num_of_stars_left);

    for (int i = 0; i < num_of_stars_left; i++)
        std::cout << '*';

    int day;
    std::cout << "Day ";
    day = this->model->getDay();
    if (day < 10) std::cout << '0' << day << ' ';
        else std::cout << day << ' ';

    int time;
    time = this->model->getTime();
    if (time < 10) std::cout << "Time0" << time;
        else std::cout << "Time" << time;
    std::cout << ':' << "00";

    for (int i = 0; i < num_of_stars_right; i++)
        std::cout << '*';

    std::cout << std::endl;
}

void ConsoleDrawer::drawField()
{
    for (int i = 0; i < this->field->getNumOfRows(); i++) {
        for (int j = 0; j < this->field->getNumOfCols(); j++)
            std::cout << this->field->getChar(i, j) << ' ';
        std::cout << std::endl;
    }
}

