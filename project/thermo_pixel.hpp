#pragma once

#include "thermometry.hpp"


class thermo_pixel
{
private:

    point position;
    int brightness;
    double temperature;
    
public:
    thermo_pixel();
    ~thermo_pixel();
};

