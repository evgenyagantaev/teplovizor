#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "opencv_headers.hpp"

#include "point.hpp"
#include "thermo_pixel.hpp"
#include "brightness_to_temperature_converter.hpp"
#include "current_thermo_frame.hpp"

#define DEFAULT_ABB_TEMPERATURE 42
#define DEFAULT_BACKGROUND_TEMPERATURE 27


using namespace cv;

class marked_thermo_frame
{
private:

    point left_eye_center;
    point right_eye_center;
    thermo_pixel abb_base_pixel;
    thermo_pixel background_base_pixel;

    int manual_mark_counter;

    brightness_to_temperature_converter converter;

    Mat mark_canvas;

    //***

    //void mark_frame_manually(current_thermo_frame frame_to_mark);
 
    
public:

    marked_thermo_frame(void);

    //void mark_frame(current_thermo_frame frame_to_mark);
    void mark_frame(cv::Mat frame_to_mark, int x, int y);

    void set_mark_canvas(cv::Mat value);
    Mat get_mark_canvas(void);
    
        
};

