#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @brief класс для представления координат объектов на поле
 */
//TODO: пусть везде будут только h и v, никаких i, j, a, b
//TODO: думаю вам лучше иметь enum Direction ближе к этому классу, и в нем скрыть все подробности определения направления на основе координат
class Coordinates
{
    //TODO: Если вы настаиваете на одной букве, пусть это будет v
    /**
     * @brief i - координата по вертикали
     */
    int i;

    //TODO: Если вы настаиваете на одной букве, пусть это будет h
    /**
     * @brief j - координата по горизонтали
     */
    int j;

public:
    /**
     * @brief Coordinates - конструктор без параметров; создает объект координат (0, 0)
     */
    //TODO: использовать для этого параметры по умолчанию в следующем конструкторе
    Coordinates(): i(0), j(0) {}

    /**
     * @brief Coordinates - конструктор с параметрами; создает объект
     * с заданными координатами
     */
    Coordinates(int a, int b): i(a), j(b) {}

    /**
     * @brief метод, устанавливающий координату по вертикали
     */
    //TODO: setI --> setV --> setVertical
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
