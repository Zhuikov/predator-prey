#include "field.h"

Field::Field()
{
    this->height = 10;
    this->length = 10;

    field = new char*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[length];
        for (int j = 0; j < length; j++)
            field[i][j] = '.';
    }
}

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

Field& Field::operator=(Field &field2)
{
    if (this != &field2) {
        for (int i = 0; i < this->height; i++)
            delete[] field[i];
        delete[] field;

        this->resize(&field2);

        this->field = new char*[height];
        for (int i = 0; i < height; i++)
            field[i] = new char[length];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < length; j++)
                this->field[i][j] = field2.getChar(i, j);
    }

    return *this;
}

int Field::isEmpty(int a, int b)
{
    if ((a < 0) || (a >= height) || (b < 0) || (b >= length)) return 0;
    if ((this->field[a][b] == '.') && (a >= 0) && (a < height) && (b >= 0) && (b < length)) return 1;
    return 0;
}

void Field::setPosition(const int a, const int b, char ch)
{
    this->field[a][b] = ch;
}

void Field::resize(Field *field1)
{
    height = field1->getNumOfRows();
    length = field1->getNumOfCols();
}

char Field::whatIsEmpty(int a, int b)
{
    if (isEmpty(a - 1, b)) return 'u';
    if (isEmpty(a, b + 1)) return 'r';
    if (isEmpty(a + 1, b)) return 'd';
    if (isEmpty(a, b - 1)) return 'l';
    return '0';
}

char Field::getChar(const int x, const int y) const
{
    return field[x][y];
}

int Field::getNumOfCols()
{
    return this->length;
}

int Field::getNumOfRows()
{
    return this->height;
}

Field::~Field()
{
    for (int i = 0; i < height; i++) {
        delete[] field[i];
    }
    delete[] field;
}
