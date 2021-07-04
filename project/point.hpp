#pragma once

#include "thermometry.hpp"

class point
{
private:
    int x;
    int y;
public:

    void set_point(int X, int Y);

    point();
    point(int X, int Y);

    int getx();
    int gety();
};


