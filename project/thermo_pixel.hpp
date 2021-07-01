#pragma once

#include "thermometry.hpp"


class thermo_pixel
{
private:

    struct point position;
    int brightness;
    double temperature;
    
public:
    thermo_pixel();
    ~thermo_pixel();
};

