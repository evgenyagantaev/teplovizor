#pragma once

#include "thermometry.hpp"

class brightness_to_temperature_converter
{
private:

    int abb_br;
    double abb_temp;
    int bg_br;
    double bg_temp;
    double T0;
    double K;


public:

    void calibrate(int abb_brigthness, double abb_temperature, int background_brightness, double background_temperature);

    brightness_to_temperature_converter(/* args */);
    ~brightness_to_temperature_converter();
};

