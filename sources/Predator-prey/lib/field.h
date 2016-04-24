#ifndef FIELD_H
#define FIELD_H
#include "settings.h"
#include <vector>

enum Position
{
    EMPTY,
    PREDATOR,
    PREY
};

class Field
{
    std::vector< std::vector<Position> > field;
    int length;
    int height;

public:
    static const int MAX_FIELD_SIZE = 30;
    static const int MIN_FIELD_SIZE = 10;
    /**
     * @brief конструктор без параметров, создает поле 10 х 10
     */
    Field();

    /**
     * @brief конструктор с параметрами, создает поле указанных размеров
     * @param height - высота поля
     * @param length - длина поля
     */
    Field(int height, int length);

    /**
     * @brief метод, полволяющий узнать, является ли клетка с данными координатами пустым
     * @param a - координата 1
     * @param b - координата 2
     * @return возвращает false, если клетка свободна и true, если клетка занята
     */
    bool isEmpty(int a, int b) const;

    /**
     * @brief метод, позволяющий установить на клетку с данными координатами заданный символ
     * @param a - координата 1
     * @param b - координата 2
     * @param Position - позиция, которую надо установить
     */
    void setPosition(int a, int b, Position);

    /**
     * @brief метод, возвращающий свободное направление хода для заданной клетки
     * @param a - координата клетки 1
     * @param b - координата клетки 2
     * @return символ - направление
     */
    int whatIsEmpty(int a, int b) const;

    /**
     * @brief метод, возвращающий значение клетки с заданными координатами
     * @param x - координата 1
     * @param y - координата 2
     * @return символ - значение
     */
    Position getPosition(int a, int b) const;

    /**
     * @brief метод, возвращающий длину поля в клетках
     * @return длина поля
     */
    int getLength() const { return this->length; }

    /**
     * @brief метод, возвращающий высоту поля в клетках
     * @return высота поля
     */
    int getHeight() const { return this->height; }

    /**
     * @brief перегруженный оператор присваивания; при необходимости, изменяет развер поля
     */
    Field& operator=(const Field &field1);

    ~Field();
};

#endif // FIELD_H
