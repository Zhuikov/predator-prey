#ifndef BADNUM_H
#define BADNUM_H
#include <exception>

class BadNum : public std::exception
{
    int bad_number;
    int min_boundary;
    int max_boundary;
public:
    BadNum(int bad_number, int min_boundary, int max_boundary):
        bad_number(bad_number),
        min_boundary(min_boundary),
        max_boundary(max_boundary)
    {}
    virtual const char *what() const throw()
    {
        const char *string;
        if (bad_number < min_boundary) {
            string = "Введенное значение меньше допустимого";
        }
        if (bad_number > max_boundary) {
            string = "Введенное значение больше допустимого";
        }
        return string;
    }
   int getMaxBoundary() { return max_boundary; }
   int getMinBoundary() { return min_boundary; }
};

#endif // BADNUM_H

