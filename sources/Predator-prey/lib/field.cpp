#include "field.h"
#include "exceptions.h"

Field::Field()
{
    this->height = 10;
    this->length = 10;

    //todo сишные массивы - не очень круто
    field = new char*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[length];
        for (int j = 0; j < length; j++)
            field[i][j] = '.';
    }
}

Field::Field(int height, int length)
{
    if (height < 0 || length < 0) throw BadFieldCreate();
    this->height = height;
    this->length = length;

    field = new char*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[length];
        for (int j = 0; j < length; j++)
            field[i][j] = '.';
    }
}

Field& Field::operator=(const Field &field2)
{
    if (this != &field2) {
        for (int i = 0; i < this->height; i++)
            delete[] field[i];
        delete[] field;

        this->height = field2.getHeight();
        this->length = field2.getLength();

        this->field = new char*[height];
        for (int i = 0; i < height; i++)
            field[i] = new char[length];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < length; j++)
                this->field[i][j] = field2.getChar(i, j);
    }

    return *this;
}

bool Field::isEmpty(int a, int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) return false;
    if (this->field[a][b] != '.') return false;
    return true;
}

void Field::setChar(int a, int b, char ch)
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    this->field[a][b] = ch;
}

char Field::getChar(const int a, const int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    return this->field[a][b];
}

int Field::whatIsEmpty(int a, int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    if (isEmpty(a - 1, b)) return 0;
    if (isEmpty(a, b + 1)) return 1;
    if (isEmpty(a + 1, b)) return 2;
    if (isEmpty(a, b - 1)) return 3;
    return -1;
}

Field::~Field()
{
    for (int i = 0; i < height; i++) {
        delete[] field[i];
    }
    delete[] field;
}
