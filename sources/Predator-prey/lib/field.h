#ifndef FIELD_H
#define FIELD_H
#include "settings.h"
#include "coordinates.h"
#include <vector>

/**
 * @brief Position - перечисление всех возможных состояний клетки поля
 */
enum class Position
{
    EMPTY,
    PREDATOR,
    PREY,
    GRASS
};

/**
 * @brief класс для представления поля в программе
 */
class Field
{
    std::vector< std::vector< Unit* > > field;

    /**
     * @brief height - текущая длина поля
     */
    int height;

    /**
     * @brief length - текущая длина поля
     */
    int length;


public:
    /**
     * @brief MAX_FIELD_SIZE - максимальная длина и высота поля
     */
    //TODO: Подозреваю, что это ограничение вызвано только размерами, которые возможно отрисовать в консоли, предлагаю вынести его отсюда
    //А вообще ваше поле, кажется, только размером int ограничено, или максимальной длинной вектора
    static constexpr int MAX_FIELD_SIZE = 200;

    /**
     * @brief MIN_FIELD_SIZE - минимальная длина и высота поля
     */
    static constexpr int MIN_FIELD_SIZE = 10;

    /**
     * @brief конструктор с параметрами, создает поле указанных размеров
     * @param height - высота поля
     * @param length - длина поля
     */
    Field(int height = 10, int length = 10);

    /**
     * @brief метод, позволяющий узнать, является ли клетка с данными координатами пустым
     * @param v - координата  по вертикали
     * @param h - координата по горизонтали
     * @return возвращает true, если клетка свободна и false, если клетка занята
     */
    bool isEmpty(int v, int h) const;

    /**
     * @brief метод, позволяющий установить на клетку с данными координатами заданный символ
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @param Position - позиция, которую надо установить
     */
    void setPosition(int v, int h, Position);

    /**
     * @brief метод, возвращающий свободное направление хода для заданной клетки
     * @param v - координата клетки по вертикали
     * @param h - координата клетки по горизонтали
     */
    Direction whatIsEmpty(int v, int h) const;

    /**
     * @brief метод, возвращающий значение клетки с заданными координатами
     * @param v - координата по вертикали
     * @param h - координата по горизонтали
     * @return символ - значение
     */
    Position getPosition(int v, int h) const;

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

    /**
     * @brief проверить, не находится ли позиция за границами поля
     * @param vertical_position по вертикали
     * @param horizontal_position по горизонтали
     * @return
     */
    bool checkBoundary(int vertical_position, int horizontal_position) const;
};

#endif // FIELD_H
