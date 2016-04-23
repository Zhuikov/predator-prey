#ifndef FIELD_H
#define FIELD_H
#include "settings.h"

class Field
{
    char** field;
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
     * @param ch - символ, который нужно установить
     */
    void setChar(const int a, const int b, char ch);

    /**
     * @brief метод, возвращающий свободное направление хода для заданной клетки
     * @param a - координата клетки 1
     * @param b - координата клетки 2
     * @return символ - направление
     */
    char whatIsEmpty(int a, int b) const;

    /**
     * @brief метод, возвращающий значение клетки с заданными координатами
     * @param x - координата 1
     * @param y - координата 2
     * @return символ - значение
     */
    char getChar(const int a, const int b) const;

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
    //todo const ссылка была бы все же лучше
    Field& operator=(const Field &field1);

    ~Field();
};

#endif // FIELD_H
