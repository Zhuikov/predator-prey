#include "field.h"
#include "badfield.h"
#include "badboundary.h"

Field::Field()
{
    this->height = 10;
    this->length = 10;

    field.resize(10);
    for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
        (*it).resize(10, EMPTY);

}

Field::Field(int height, int length)
{
    if (height < 0 || length < 0) throw BadFieldCreate();
    this->height = height;
    this->length = length;

    field.resize(height);
    for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
         (*it).resize(length, EMPTY);
}

Field& Field::operator=(const Field &field2)
{
    if (this != &field2) {
        for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
            (*it).clear();
        field.clear();

        this->height = field2.getHeight();
        this->length = field2.getLength();

        field.resize(field2.getHeight());
        for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
            (*it).resize(field2.getLength());

        for (int i = 0; i < height; i++)
            for (int j = 0; j < length; j++)
                this->field[i][j] = field2.getPosition(i, j);
    }

    return *this;
}

bool Field::isEmpty(int a, int b) const
{
    /// здесь не нужно бросать исключение
    if (a < 0 || a >= height || b < 0 || b >= length) return false;
    if (this->field[a][b] != EMPTY) return false;
    return true;
}

void Field::setPosition(int a, int b, Position pos)
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    this->field[a][b] = pos;
}

Position Field::getPosition(int a, int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    return this->field[a][b];
}

int Field::whatIsEmpty(int a, int b) const
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    if (isEmpty(a - 1, b) == true) return 0;
    if (isEmpty(a, b + 1) == true) return 1;
    if (isEmpty(a + 1, b) == true) return 2;
    if (isEmpty(a, b - 1) == true) return 3;
    return -1;
}

Field::~Field()
{
    for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
        (*it).clear();
}
