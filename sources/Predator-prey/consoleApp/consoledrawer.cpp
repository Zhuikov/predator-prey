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
    if (model->getPredatorsNum() == 0 && model->getPreysNum() > 0) std::cout << "Жертвы убежали от хищников!";
    else if (model->getPredatorsNum() > 0 && model->getPreysNum() == 0) std::cout << "Хищники съели всех жертв!";
    else if (model->getPredatorsNum() == 0 && model->getPreysNum() == 0) std::cout << "Ничья!";

    std::cout << std::endl << std::endl;

}

void ConsoleDrawer::drawHead()
{
    int lenght_of_string = std::strlen("День ХХ Время HH:MM");
    int num_of_stars_left = (this->field->getLength() * 2 - lenght_of_string) / 2;
    int num_of_stars_right = this->field->getLength() * 2 - lenght_of_string - num_of_stars_left;

    for (int i = 0; i < num_of_stars_left; i++) {
        std::cout << '*';
    }

//    int day = this->model->getDay();
//    std::cout << "День ";
//    if (day < 10) std::cout << '0' << day << ' ';
//        else std::cout << day << ' ';

//    int time = this->model->getTime();
//    std::cout << "Время ";
//    if (time < 10) std::cout << '0' << time;
//        else std::cout << time;
//    std::cout << ':' << "00";

    for (int i = 0; i < num_of_stars_right; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;
}

void ConsoleDrawer::drawStatistics()
{
    int length_of_string = std::strlen("Хищники XX Жертвы XX");
    int num_of_stars_left = (this->field->getLength() * 2 - length_of_string) / 2;
    int num_of_stars_right = this->field->getLength() * 2 - length_of_string - num_of_stars_left;

    for (int i = 0; i < num_of_stars_left; i++)
        std::cout << '*';

    int predators = this->model->getPredatorsNum();
    std::cout << "Хищники ";
    if (predators >= 10) std::cout << predators;
        else std::cout << '0' << predators;

    int preys = this->model->getPreysNum();
    std::cout << " Жертвы ";
    if (preys >= 10) std::cout << preys;
        else std::cout << '0' << preys;

    for (int i = 0; i < num_of_stars_right; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;
}

void ConsoleDrawer::drawLegend()
{
    std::cout << "X - хищники" << std::endl;
    std::cout << "O - жертвы" << std::endl;
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
