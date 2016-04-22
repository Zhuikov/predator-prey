#ifndef FIELD_H
#define FIELD_H
#include "settings.h"

class Field
{
    char** field;
    int length;
    int height;

public:
    /**
     * @brief конструктор без параметров, создает поле 10 х 10
     */
    Field();

    /**
     * @brief конструктор с параметрами, создает поле указанных размеров
     * @param n - высота поля
     * @param m - длина поля
     */
    //todo n и m плохие названия, не информативно
    // мб height и length
    Field(int n, int m);

    /**
     * @brief метод, полволяющий узнать, является ли клетка с данными координатами пустым
     * @param a - координата 1
     * @param b - координата 2
     * @return возвращает false, если клетка свободна и true, если клетка занята
     */
    //todo возможно стоит сделать метод const?
    bool isEmpty(int a, int b);

    /**
     * @brief метод, позволяющий установить на клетку с данными координатами заданный символ
     * @param a - координата 1
     * @param b - координата 2
     * @param ch - символ, который нужно установить
     */
    //todo перименовать
    // установаить позицию? может быть установить символ?
    void setPosition(const int a, const int b, char ch);

    /**
     * @brief метод, возвращающий свободное направление хода для заданной клетки
     * @param a - координата клетки 1
     * @param b - координата клетки 2
     * @return символ - направление
     */
    //todo возможно стоит сделать метод const?
    char whatIsEmpty(int a, int b);

    /**
     * @brief метод, возвращающий значение клетки с заданными координатами
     * @param x - координата 1
     * @param y - координата 2
     * @return символ - значение
     */
    //todo везде a и b, а тут x и y
    // вы уж определитесь и пределайте
    //todo возможно стоит сделать метод const?
    char getChar(const int x, const int y) const { return field[x][y]; }

    /**
     * @brief метод, возвращающий длину поля в клетках
     * @return длина поля
     */
    //todo мб getLength() было бы лаконичнее и информативнее
    //todo возможно стоит сделать метод const?
    int getNumOfCols() { return this->length; }

    /**
     * @brief метод, возвращающий высоту поля в клетках
     * @return высота поля
     */
    //todo аналогично предыдущему
    //todo возможно стоит сделать метод const?
    int getNumOfRows() { return this->height; }

    /**
     * @brief перегруженный оператор присваивания; при необходимости, изменяет развер поля
     */
    //todo const ссылка была бы все же лучше
    Field& operator=(Field &field1);

    ~Field();
};

#endif // FIELD_H
