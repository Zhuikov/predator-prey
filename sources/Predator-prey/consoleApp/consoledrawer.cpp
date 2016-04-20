#include "consoledrawer.h"
#include <iostream>

void ConsoleDrawer::showModel()
{
    std::cout << std::endl;
    this->drawLegend();
    this->drawHead();
    this->drawStatistics();
    this->drawField();
}

void ConsoleDrawer::showResult()
{
    int num_of_predators = this->model->getPredatorsNum();
    int num_of_preys = this->model->getPreysNum();

    if (num_of_predators == 0 && num_of_preys > 0) std::cout << "Жертвы победили!";
    else if (num_of_predators > 0 && num_of_preys == 0) std::cout << "Хищники победили!";
    else if (num_of_predators == 0 && num_of_preys == 0) std::cout << "Ничья!";

    std::cout << std::endl << std::endl;

}

void ConsoleDrawer::drawHead()
{
    int num_of_stars_left;
    int num_of_stars_right;

    num_of_stars_left = (this->field->getNumOfCols() * 2 - 20) / 2;
    num_of_stars_right = (this->field->getNumOfCols() * 2 - 20 - num_of_stars_left);

    for (int i = 0; i < num_of_stars_left; i++)
        std::cout << '*';

    int day = this->model->getDay();
    std::cout << "День ";
    if (day < 10) std::cout << '0' << day << ' ';
        else std::cout << day << ' ';

    int time = this->model->getTime();
    std::cout << "Время ";
    if (time < 10) std::cout << '0' << time;
        else std::cout << time;
    std::cout << ':' << "00";

    for (int i = 0; i < num_of_stars_right; i++)
        std::cout << '*';

    std::cout << std::endl;
}

void ConsoleDrawer::drawStatistics()
{
    int num_of_stars_left;
    int num_of_stars_right;

    num_of_stars_left = (this->field->getNumOfCols() * 2 - 20) / 2;
    num_of_stars_right = (this->field->getNumOfCols() * 2 - 20 - num_of_stars_left);

    for (int i = 0; i < num_of_stars_left; i++)
        std::cout << '*';

    int predators = this->model->getPredatorsNum();
    std::cout << "Хищники ";
    if (predators > 10) std::cout << predators;
        else std::cout << '0' << predators;

    int preys = this->model->getPreysNum();
    std::cout << " Жертвы ";
    if (preys > 10) std::cout << preys;
        else std::cout << '0' << preys;

    for (int i = 0; i < num_of_stars_right; i++)
        std::cout << '*';

    std::cout << std::endl;
}

void ConsoleDrawer::drawLegend()
{
    std::cout << "X - хищники" << std::endl;
    std::cout << "O - жертвы" << std::endl;
}

void ConsoleDrawer::drawField()
{
    for (int i = 0; i < this->field->getNumOfRows(); i++) {
        for (int j = 0; j < this->field->getNumOfCols(); j++)
            std::cout << this->field->getChar(i, j) << ' ';
        std::cout << std::endl;
    }
}

