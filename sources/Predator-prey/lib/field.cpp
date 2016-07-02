#include "field.h"

Field::Field(int height, int length)
{
    this->height = height;
    this->length = length;

    for(int i = 0; i < height; i++){
        field.push_back(std::vector< Unit* >(length, nullptr));
    }
}

bool Field::checkBoundary(int v, int h) const
{
    if (v < 0 || v >= height || h < 0 || h >= length){
        return false;
    }
    return true;
}

bool Field::isEmpty(int v, int h) const
{
    if(checkBoundary(v, h) == false){
        return false;
    }

    if (this->field[v][h] != nullptr){
        return false;
    }

    return true;
}

void Field::setPosition(int v, int h, Unit* unit)
{
    if (checkBoundary(v, h) == false){
        throw BadFieldBoundary(v, h);
    }
    this->field[v][h] = unit;
}

Unit* Field::getPosition(int v, int h) const
{
//    if (checkBoundary(v, h) == false){
//        throw BadFieldBoundary(v, h);
//    }
    return this->field[v][h];
}
