#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
    int i;
    int j;

public:
    Coordinates(): i(0), j(0) {}
    Coordinates(int a, int b): i(a), j(b) {}
    void setI(int a) { this->i = a; }
    void setJ(int b) { this->j = b; }
    int getI() const { return i; }
    int getJ() const { return j; }

    /**
     * @brief Разность координат - расстояние между соответсвующими точками на плоскости
     */
    double operator-(Coordinates &);
    bool operator==(Coordinates a) const;
    bool operator!=(Coordinates a) const;

};

#endif // COORDINATES_H
