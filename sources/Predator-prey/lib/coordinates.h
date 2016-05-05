#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @brief класс для представления координат объектов на поле
 */
//TODO: думаю вам лучше иметь enum Direction ближе к этому классу, и в нем скрыть все подробности определения направления на основе координат
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
     * @brief Coordinates - конструктор без параметров; создает объект координат (0, 0)
     */
    //TODO: использовать для этого параметры по умолчанию в следующем конструкторе
    Coordinates(): vertical(0), horizontal(0) {}

    /**
     * @brief Coordinates - конструктор с параметрами; создает объект
     * с заданными координатами
     */
    Coordinates(int vertical, int horizontal): vertical(vertical), horizontal(horizontal) {}

    /**
     * @brief метод, устанавливающий координату по вертикали
     */
    //TODO: setI --> setV --> setVertical
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
    double operator-(Coordinates &);
    bool operator==(Coordinates a) const;
    bool operator!=(Coordinates a) const;

};

#endif // COORDINATES_H
