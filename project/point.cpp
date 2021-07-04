#include "point.hpp"

void point::set_point(int X, int Y)
{
    x = X;
    y = Y;
}

point::point()
{}

point::point(int X, int Y)
{
    set_point(X, Y)
}

int point::getx()
{
    return x;
}
int point::gety()
{
    return y;
}