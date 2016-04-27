#include "field.h"
#include "badfield.h"
#include "badboundary.h"

//TODO: убрать дублирование конструкторов, сделать один конструктор с параметрами по умолчанию
//TODO: и параметр по умолчанию не 10, а MIN_FIELD_SIZE
Field::Field()
{
    this->height = 10;
    this->length = 10;

//TODO: что это за бред с resize???
//    field.resize(10);
    for(int i = 0; i < 10; i++){
        field.push_back(std::vector<Position>(10, EMPTY));
    }

    //TODO: даже если у вас цикл с одной строчкой в теле, лучше явно ставить фигурные скобки
    //потому что иначе очень легко дописать вторую строку, и забыть поставить скобки
    //for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
    //    (*it).resize(10, EMPTY);

}

//TODO: использовать списки инициализации
Field::Field(int height, int length)
{
    if (height < 0 || length < 0) throw BadFieldCreate();
    this->height = height;
    this->length = length;

    for(int i = 0; i < height; i++){
        field.push_back(std::vector<Position>(length, EMPTY));
    }
//    field.resize(height);
//    for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
//         (*it).resize(length, EMPTY);
}

//Field& Field::operator=(const Field &field2)
//{
//    if (this != &field2) {
//        for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
//            (*it).clear();
//        field.clear();

//        this->height = field2.getHeight();
//        this->length = field2.getLength();

//        field.resize(field2.getHeight());
//        for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
//            (*it).resize(field2.getLength());

//        for (int i = 0; i < height; i++)
//            for (int j = 0; j < length; j++)
//                this->field[i][j] = field2.getPosition(i, j);
//    }

//    return *this;
//}

//TODO: надо осознать, что я вынесла одинаковое условие
bool Field::checkBoundary(int vertical_position, int horizontal_position){
    if (vertical_position < 0 ||
            vertical_position >= height ||
            horizontal_position < 0 ||
            horizontal_position >= length){
        return false;
    }
    return true;
}

bool Field::isEmpty(int a, int b) const
{
    if(checkBoundary(a, b)){
        return false;
    }

    if (this->field[a][b] != EMPTY){
        return false;
    }

    return true;
}

void Field::setPosition(int a, int b, Position pos)
{
    if (checkBoundary(a, b)){
        throw BadFieldBoundary();
    }
    this->field[a][b] = pos;
}

Position Field::getPosition(int a, int b) const
{
    if (checkBoundary(a, b)){
        throw BadFieldBoundary();
    }
    return this->field[a][b];
}

int Field::whatIsEmpty(int a, int b) const
{
    if (checkBoundary(a, b)){
        throw BadFieldBoundary();
    }
    if (isEmpty(a - 1, b) == true) return 0;
    if (isEmpty(a, b + 1) == true) return 1;
    if (isEmpty(a + 1, b) == true) return 2;
    if (isEmpty(a, b - 1) == true) return 3;
    return -1;
}

Field::~Field()
{
    //TODO: разве вам это надо? я просто не понимаю, может быть...
 //   for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
 //       (*it).clear();
}
