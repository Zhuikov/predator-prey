#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @brief Direction - возможные значения направлений
 */
enum class Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NO_DIRECTION
};

/**
 * @brief класс для представления координат объектов на поле
 */
class Coordinates
{
    /**
     * @brief vertical - координата по вертикали
     */
    int vertical;

    /**
     * @brief horizontal - координата по горизонтали
     */
    int horizontal;

public:

    /**
     * @brief конструктор с параметрами; создает объект с заданными координатами
     */
    Coordinates(int vertical = 0, int horizontal = 0): vertical(vertical), horizontal(horizontal) {}

    /**
     * @brief метод, изменяющий координаты в соответствие с переданным направлением
     */
    void changeToDirection(Direction);

    /**
     * @brief метод, устанавливающий координату по вертикали
     */
    void setV(int vertical) { this->vertical = vertical; }

    /**
     * @brief метод, устанавливающий координату по горизонтали
     */
    void setH(int horizontal) { this->horizontal = horizontal; }

    /**
     * @brief метод, возвращающий координату по вертикали
     */
    int getV() const { return vertical; }

    /**
     * @brief метод, возвращающий координату по горизонтали
     */
    int getH() const { return horizontal; }

    /**
     * @brief Разность координат - расстояние между соответсвующими точками на плоскости
     */
    double operator-(const Coordinates &);
    bool operator==(Coordinates a) const;
    bool operator!=(Coordinates a) const;

};

#endif // COORDINATES_H
