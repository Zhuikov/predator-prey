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
    //todo возможно стоит сделать метод const?
    int getI() { return i; }
    //todo возможно стоит сделать метод const?
    int getJ() { return j; }

    /**
     * @brief Разность координат - расстояние между соответсвующими точками на плоскости
     */
    //todo составные объекты лучше по констаной ссылке
    double operator-(Coordinates &point2);
    //todo хотелось бы более содержательные названия
    // a ни о чем не говорит
    //todo возможно стоит сделать метод const?
    bool operator==(Coordinates a);
    //todo возможно стоит сделать метод const?
    bool operator!=(Coordinates a);

};

#endif // COORDINATES_H
