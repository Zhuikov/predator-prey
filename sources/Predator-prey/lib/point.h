#ifndef POINT_H
#define POINT_H


class Point
{
    int x;
    int y;

public:
    Point(): x(0), y(0) {}
    Point(const int a, const int b): x(a), y(b) {}
    void setX(const int a) { this->x = a; }
    void setY(const int b) { this->y = b; }
    int getX() const { return x; }
    int getY() const { return y; }
    double operator-(const Point& point2);

};

#endif // POINT_H
