#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "opencv_headers.hpp"
#include "point.hpp"

class rect_thermal_spot
{
private:

    point base_point;
    int width;
    int height;

    cv::RNG random_generator;
    
public:

    void set_base(int x, int y);
    void set_width(int value);
    void set_height(int value);

    point get_base(void);
    int get_width(void);
    int get_height(void);

    point generate();

};

