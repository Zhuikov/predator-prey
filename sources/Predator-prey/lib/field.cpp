#include "field.h"
#include "badfield.h"
#include "badboundary.h"

Field::Field(int height, int length)
{
    this->height = height;
    this->length = length;

    for(int i = 0; i < height; i++){
        field.push_back(std::vector<Position>(length, Position::EMPTY));
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

    if (this->field[v][h] != Position::EMPTY){
        return false;
    }

    return true;
}

void Field::setPosition(int v, int h, Position pos)
{
    if (checkBoundary(v, h) == false){
        throw BadFieldBoundary();
    }
    this->field[v][h] = pos;
}

Position Field::getPosition(int v, int h) const
{
    if (checkBoundary(v, h) == false){
        throw BadFieldBoundary();
    }
    return this->field[v][h];
}

Direction Field::whatIsEmpty(int v, int h) const
{
    if (checkBoundary(v, h) == false){
        throw BadFieldBoundary();
    }

    if (isEmpty(v - 1, h) == true) return Direction::UP;
    if (isEmpty(v, h + 1) == true) return Direction::RIGHT;
    if (isEmpty(v + 1, h) == true) return Direction::DOWN;
    if (isEmpty(v, h - 1) == true) return Direction::LEFT;
    return Direction::NO_DIRECTION;
}
