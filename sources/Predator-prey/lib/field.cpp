#include "field.h"

Field::Field(int n, int m)
{
    this->height = n;
    this->length = m;

    field = new char*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[length];
        for (int j = 0; j < length; j++)
            field[i][j] = '.';
    }
}

int Field::isEmpty(int x, int y)
{
    if ((x < 0) || (x >= length) || (y < 0) || (y >= height)) return 0;
    if (this->field[x][y] == '.') return 1;
    return 0;
}

void Field::setPosition(const int x, const int y, char ch)
{
    this->field[x][y] = ch;
}

char Field::whatIsEmpty(int x, int y)
{
    if (isEmpty(x, y - 1)) return 'u';
    if (isEmpty(x + 1, y)) return 'r';
    if (isEmpty(x, y + 1)) return 'd';
    return 'l';
}

char Field::getChar(const int x, const int y) const
{
    return field[x][y];
}

Field::~Field()
{
    for (int i = 0; i < height; i++) {
        delete[] field[i];
    }
    delete[] field;
}

