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

Field::Field(int n, int m)
{
    if (n < 0 || m < 0) throw BadFieldCreate();
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
    //todo проверить на присваивание объекта самому себе
    //а то тут сигментейшн фолт может быть
    if (this != &field2) {
        for (int i = 0; i < this->height; i++)
            delete[] field[i];
        delete[] field;

        this->height = field2.getNumOfRows();
        this->length = field2.getNumOfCols();

        this->field = new char*[height];
        for (int i = 0; i < height; i++)
            field[i] = new char[length];

        for (int i = 0; i < height; i++)
            for (int j = 0; j < length; j++)
                this->field[i][j] = field2.getChar(i, j);
    }

    return *this;
}

bool Field::isEmpty(int a, int b)
{
    //todo может, лучше сделать выбрасывание исключения о выходе за границы?
    // как в строке 65
    if (a < 0 || a >= height || b < 0 || b >= length) return false;
    if (this->field[a][b] != '.') return false;
    return true;
}

void Field::setPosition(int a, int b, char ch)
{
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    this->field[a][b] = ch;
}

char Field::whatIsEmpty(int a, int b)
{
    //todo enum был бы лучше
    if (a < 0 || a >= height || b < 0 || b >= length) throw BadFieldBoundary();
    if (isEmpty(a - 1, b)) return 'u';
    if (isEmpty(a, b + 1)) return 'r';
    if (isEmpty(a + 1, b)) return 'd';
    if (isEmpty(a, b - 1)) return 'l';
    return '0';
}

Field::~Field()
{
    for (int i = 0; i < height; i++) {
        delete[] field[i];
    }
    delete[] field;
}
