#include "field.h"

Field::Field()
{
    this->length = sett->field_length;
    this->height = sett->field_height;
    field = new char*[length];
    for (int i = 0; i < height; i++) {
        field[i] = new char[height];
        for (int j = 0; j < height; j++) {
            field[i][j] = '.';
        }
    }
}

int Field::isEmpty(int x, int y)
{
    if (this->field[x][y] == '.') return 1;
    return 0;
}

void Field::setPosition(int x, int y, char ch)
{
    this->field[x][y] = ch;
}

Field::~Field()
{
    for (int i = 0; i < height; i++) {
        delete[] field[i];
    }
    delete[] field;
}

