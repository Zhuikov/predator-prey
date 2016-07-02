#include "consoledrawer.h"
#include <iostream>
#include <cstring>

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
    if (model->getPredatorsNum() == 0 && model->getPreysNum() > 0) std::cout << "Preys have run from predators!";
    else if (model->getPredatorsNum() > 0 && model->getPreysNum() == 0) std::cout << "Predators have eaten all preys";
    else if (model->getPredatorsNum() == 0 && model->getPreysNum() == 0) std::cout << "Draw";

    std::cout << std::endl << std::endl;

}

void ConsoleDrawer::drawHead()
{
    int lenght_of_string = std::strlen("step xxx");
    int num_of_stars_left = (this->field->getLength() * 2 - lenght_of_string) / 2;
    int num_of_stars_right = this->field->getLength() * 2 - lenght_of_string - num_of_stars_left;

    for (int i = 0; i < num_of_stars_left; i++) {
        std::cout << '*';
    }

    int step = this->model->getStep();
    std::cout << "step ";
    std::cout << step << ' ';

    for (int i = 0; i < num_of_stars_right; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;
}

void ConsoleDrawer::drawStatistics()
{
    int length_of_string = std::strlen("Predators XX Preys XX");
    int num_of_stars_left = (this->field->getLength() * 2 - length_of_string) / 2;
    int num_of_stars_right = this->field->getLength() * 2 - length_of_string - num_of_stars_left;

    for (int i = 0; i < num_of_stars_left; i++)
        std::cout << '*';

    int predators = this->model->getPredatorsNum();
    std::cout << "Predators ";
    if (predators >= 10) std::cout << predators;
        else std::cout << '0' << predators;

    int preys = this->model->getPreysNum();
    std::cout << " Preys ";
    if (preys >= 10) std::cout << preys;
        else std::cout << '0' << preys;

    for (int i = 0; i < num_of_stars_right; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;
}

void ConsoleDrawer::drawLegend()
{
    std::cout << "X - Predators" << std::endl;
    std::cout << "O - Preys" << std::endl;
}

void ConsoleDrawer::drawField()
{
    Unit* position;
    for (int i = 0; i < this->field->getHeight(); i++) {
        for (int j = 0; j < this->field->getLength(); j++) {
            position = this->field->getPosition(i, j);
            if (position == nullptr) {
                std::cout << ". ";
            }
            else {
                switch (position->getType()) {
                    case UnitType::PREDATOR: { std::cout << "X "; break; }
                    case UnitType::PREY:     { std::cout << "O "; break; }
                    case UnitType::GRASS:    { std::cout << "w "; break; }
                }
            }
        }
        std::cout << std::endl;
    }
}
