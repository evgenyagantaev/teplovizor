#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "point.hpp"
#include "thermo_pixel.hpp"
#include "brightness_to_temperature_converter.hpp"
#include "temperature_range.hpp"

#define TPV_LENGTH 64

class thermo_pixel_vector
{
private:

    thermo_pixel vector[TPV_LENGTH];

    int current_length;

    void cut(int value);
    void shift(int index);
    
public:
    thermo_pixel_vector();

    void add_pixel(thermo_pixel value);
    int get_current_length();
    thermo_pixel get_pixel(int index);
};


