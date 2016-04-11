#ifndef FIELD_H
#define FIELD_H
#include "settings.h"

class Field
{
    char** field;
    int length;
    int height;

    /**
     * @brief метод, изменяющий размер поля;
     * новая высота поля - высота поля field1; новая длина поля - длина поля field1;
     */
    void resize(Field *field1);

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
    Field(int n, int m);

    /**
     * @brief метод, полволяющий узнать, является ли клетка с данными координатами пустым
     * @param a - координата 1
     * @param b - координата 2
     * @return возвращает 0, если клетка свободна и 1, если клетка занята
     */
    int isEmpty(int a, int b);

    /**
     * @brief метод, позволяющий установить на клетку с данными координатами заданный символ
     * @param a - координата 1
     * @param b - координата 2
     * @param ch - символ, который нужно установить
     */
    void setPosition(const int a, const int b, char ch);

    /**
     * @brief метод, возвращающий свободное направление хода для заданной клетки
     * @param a - координата клетки 1
     * @param b - координата клетки 2
     * @return символ - направление
     */
    char whatIsEmpty(int a, int b);

    /**
     * @brief метод, возвращающий значение клетки с заданными координатами
     * @param x - координата 1
     * @param y - координата 2
     * @return символ - значение
     */
    char getChar(const int x, const int y) const;

    /**
     * @brief метод, возвращающий длину поля в клетках
     * @return длина поля
     */
    int getNumOfCols();

    /**
     * @brief метод, возвращающий высоту поля в клетках
     * @return высота поля
     */
    int getNumOfRows();

    /**
     * @brief перегруженный оператор присваивания; при необходимости, изменяет развер поля
     */
    Field& operator=(Field &field1);

    ~Field();
};

#endif // FIELD_H
