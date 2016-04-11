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
    int getI() { return i; }
    int getJ() { return j; }
    double operator-(Coordinates point2);
    bool operator==(Coordinates a);
    bool operator!=(Coordinates a);

};

#endif // COORDINATES_H
