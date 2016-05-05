#include "field.h"
#include "badfield.h"
#include "badboundary.h"

//Field::Field()
//{
//    this->height = 10;
//    this->length = 10;

//TODO: что это за бред с resize???
//    field.resize(10);
//    for(int i = 0; i < 10; i++){
//        field.push_back(std::vector<Position>(10, EMPTY));
//    }

    //TODO: даже если у вас цикл с одной строчкой в теле, лучше явно ставить фигурные скобки
    //потому что иначе очень легко дописать вторую строку, и забыть поставить скобки
    //for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
    //    (*it).resize(10, EMPTY);

//}
Field::Field(int height, int length)
{
    this->height = height;
    this->length = length;

    for(int i = 0; i < height; i++){
        field.push_back(std::vector<Position>(length, EMPTY));
    }
//    field.resize(height);
//    for (std::vector< std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
//         (*it).resize(length, EMPTY);
}

//TODO: надо осознать, что я вынесла одинаковое условие
bool Field::checkBoundary(int v, int h) const{
    if (v < 0 ||
            v >= height ||
            h < 0 ||
            h >= length){
        return false;
    }
    return true;
}

bool Field::isEmpty(int v, int h) const
{
    if(checkBoundary(v, h) == false){
        return false;
    }

    if (this->field[v][h] != EMPTY){
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

int Field::whatIsEmpty(int v, int h) const
{
    if (checkBoundary(v, h) == false){
        throw BadFieldBoundary();
    }

    //TODO: из animal нужно вынести direction и использовать его и здесь тоже
    if (isEmpty(v - 1, h) == true) return 0;
    if (isEmpty(v, h + 1) == true) return 1;
    if (isEmpty(v + 1, h) == true) return 2;
    if (isEmpty(v, h - 1) == true) return 3;
    return -1;
}

Field::~Field()
{
    //TODO: разве вам это надо? я просто не понимаю, может быть...
 //   for (std::vector<std::vector<Position> >::iterator it = field.begin(); it != field.end(); ++it)
 //       (*it).clear();
}
