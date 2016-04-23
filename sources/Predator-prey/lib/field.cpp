#include "field.h"
#include "badfield.h"
#include "badboundary.h"

Field::Field()
{
    this->height = 10;
    this->length = 10;

    //todo сишные массивы - не очень круто
    /// да нормально же! или все-таки нет..?
    field = new Position*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new Position[length];
        for (int j = 0; j < length; j++)
            field[i][j] = EMPTY;
    }
}

Field::Field(int height, int length)
{
    if (height < 0 || length < 0) throw BadFieldCreate();
    this->height = height;
    this->length = length;

    field = new Position*[height];
    for (int i = 0; i < height; i++) {
        field[i] = new Position[length];
        for (int j = 0; j < length; j++)
            field[i][j] = EMPTY;
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

        this->field = new Position*[height];
        for (int i = 0; i < height; i++)
            field[i] = new Position[length];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < length; j++)
                this->field[i][j] = field2.getPosition(i, j);
    }

    return *this;
}

bool Field::isEmpty(int a, int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) return false;
    if (this->field[a][b] != EMPTY) return false;
    return true;
}

void Field::setPosition(int a, int b, Position pos)
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    this->field[a][b] = pos;
}

Position Field::getPosition(const int a, const int b) const
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
