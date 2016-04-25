#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @brief класс для представления координат объектов на поле
 */
class Coordinates
{
    /**
     * @brief i - координата по вертикали
     */
    int i;

    /**
     * @brief j - координата по горизонтали
     */
    int j;

public:
    /**
     * @brief Coordinates - конструктор без параметров; создает объект координат (0, 0)
     */
    Coordinates(): i(0), j(0) {}

    /**
     * @brief Coordinates - конструктор с параметрами; создает объект
     * с заданными координатами
     */
    Coordinates(int a, int b): i(a), j(b) {}

    /**
     * @brief метод, устанавливающий координату по вертикали
     */
    void setI(int a) { this->i = a; }

    /**
     * @brief метод, устанавливающий координату по горизонтали
     */
    void setJ(int b) { this->j = b; }

    /**
     * @brief метод, возвращающий координату по вертикали
     */
    int getI() const { return i; }

    /**
     * @brief метод, возвращающий координату по горизонтали
     */
    int getJ() const { return j; }

    /**
     * @brief Разность координат - расстояние между соответсвующими точками на плоскости
     */
    double operator-(Coordinates &);
    bool operator==(Coordinates a) const;
    bool operator!=(Coordinates a) const;

};

#endif // COORDINATES_H
