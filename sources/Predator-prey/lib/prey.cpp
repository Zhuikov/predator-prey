#include "prey.h"
#include "units.h"

void Prey::directionfinding()
{
    isChase();

    if (warning == 1) {
        if (my_place.getX() < dangerous_pred.getX()) {
            if (field->isEmpty(my_place.getX() - 1, my_place.getY())) direction = 'l';
                else chooseRandomDirection(); }
        if (my_place.getX() > dangerous_pred.getX()) {
            if (field->isEmpty(my_place.getX() + 1, my_place.getY())) direction = 'r';
                else chooseRandomDirection(); }
        if (my_place.getY() > dangerous_pred.getY()) {
            if (field->isEmpty(my_place.getX(), my_place.getY() + 1)) direction = 'd';
                else chooseRandomDirection(); }
        if (my_place.getY() < dangerous_pred.getY()) {
            if (field->isEmpty(my_place.getX(), my_place.getY() - 1)) direction = 'u';
                else chooseRandomDirection(); }
    }
    else chooseRandomDirection();
}

void Prey::createPrey()
{
    chooseRandomDirection();

        switch (direction) {
        case 'u': {
            Prey prey(my_place.getX(), my_place.getY() - 1);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'r': {
            Prey prey(my_place.getX() + 1, my_place.getY());
            units_struct->preys.push_back(prey);
            break;
        }
        case 'd': {
            Prey prey(my_place.getX(), my_place.getY() + 1);
            units_struct->preys.push_back(prey);
            break;
        }
        case 'l': {
            Prey prey(my_place.getX() - 1, my_place.getY());
            units_struct->preys.push_back(prey);
        }
        }

        unsigned int vec_size = units_struct->preys.size();
        units_struct->preys[vec_size].setPtrs(this->units_struct, this->field);

        chooseRandomDirection();
        this->energy = 0;
}

void Prey::isChase()
{
    warning = 0;
    for (unsigned int i = 0; i < units_struct->predators.size(); i++) {
        if (this->my_place - units_struct->predators[i].my_place < 1.1) {
            warning = 1;
            this->dangerous_pred = units_struct->predators[i].my_place;
        }
    }
}

Prey::Prey(const int a, const int b)
{
    my_place.setX(a);
    my_place.setY(b);
    dangerous_pred.setX(-1);
    dangerous_pred.setY(-1);
    energy = 0;
    field->setPosition(a, b, 'O');
    life_time = 0;

    isChase();
    chooseRandomDirection();
}

void Predator::setPtrs(Units* ptrU, Field* ptrF)
{
    this->units_struct = ptrU;
    this->field = ptrF;
}
