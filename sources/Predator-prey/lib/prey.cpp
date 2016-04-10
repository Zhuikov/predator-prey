#include "prey.h"
#include "units.h"
#include <ctime>
#include <cstdlib>

void Prey::directionfinding()
{
    isChase();

    if (warning == 1) {
        if (my_place.getX() < dangerous_pred.getX()) {
            if (field->isEmpty(my_place.getX() - 1, my_place.getY())) direction = 'u';
                else chooseRandomDirection(); }
        if (my_place.getX() > dangerous_pred.getX()) {
            if (field->isEmpty(my_place.getX() + 1, my_place.getY())) direction = 'd';
                else chooseRandomDirection(); }
        if (my_place.getY() > dangerous_pred.getY()) {
            if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) direction = 'r';
                else chooseRandomDirection(); }
        if (my_place.getY() < dangerous_pred.getY()) {
            if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) direction = 'l';
                else chooseRandomDirection(); }
    }
    else chooseRandomDirection();
}

void Prey::createPrey()
{
    chooseRandomDirection();

    switch (direction) {
        case 'u': {
            Prey *prey = new Prey(my_place.getX() - 1, my_place.getY(), this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'r': {
            Prey *prey = new Prey(my_place.getX(), my_place.getY() + 1, this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'd': {
            Prey *prey = new Prey(my_place.getX() + 1, my_place.getY(), this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'l': {
            Prey *prey = new Prey(my_place.getX(), my_place.getY() - 1, this->field);
            prey->setPtrs(this->units_struct);
            units_struct->preys.push_back(prey);
        }
        }

    chooseRandomDirection();
    this->energy = 0;
}

void Prey::isChase()
{
    warning = 0;
    for (std::vector<Predator*>::const_iterator i = this->units_struct->predators.begin();
         i != this->units_struct->predators.end(); i++) {
            if (this->my_place - (*i)->my_place < 1.1) {
                warning = 1;
                this->dangerous_pred = (*i)->my_place;
            }
    }
}

Prey::Prey(const int a, const int b, Field* ptrF)
{
    my_place.setX(a);
    my_place.setY(b);
    dangerous_pred.setX(-1);
    dangerous_pred.setY(-1);
    energy = 0;
    didMove = 0;
    life_time = 0;
    field = ptrF;
    field->setPosition(this->my_place.getX(), this->my_place.getY(), 'O');
    direction = 'u';
    warning = 0;
}

void Prey::setPtrs(Units* ptrU)
{
    this->units_struct = ptrU;
    isChase();
}

void Prey::movePrey()
{
    srand(time(0));
    this->field->setPosition(this->my_place.getX(), this->my_place.getY(), '.');
    this->directionfinding();
    if (!didMove)this->go(direction);
    else didMove = 0;
    this->field->setPosition(this->my_place.getX(), this->my_place.getY(), 'O');
}
