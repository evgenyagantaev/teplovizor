#pragma once

#include "thermometry.hpp"


class thermo_pixel
{
private:

    int x;
    int y;
    int brightness;
    double temperature;
    
public:
    thermo_pixel();
    ~thermo_pixel();
};

