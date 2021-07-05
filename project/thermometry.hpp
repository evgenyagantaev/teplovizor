#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "opencv_headers.hpp"

#define TEMPERATURE_LOW_BOUND 33
#define TEMPERATURE_UP_BOUND 40

#include "point.hpp"
#include "thermo_pixel.hpp"
#include "thermo_pixel_vector.hpp"
#include "brightness_to_temperature_converter.hpp"
#include "current_thermo_frame.hpp"
#include "random_rect_2d_generator.hpp"
#include "rect_thermal_spot.hpp"
#include "temperature_range.hpp"
#include "thermo_pixel_vector.hpp"
#include "marked_thermo_frame.hpp"




class thermometry
{
private:
    
public:

    thermometry();
    ~thermometry();
};



