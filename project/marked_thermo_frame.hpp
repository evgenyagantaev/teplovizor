#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "opencv_headers.hpp"

#include "point.hpp"
#include "thermo_pixel.hpp"
#include "thermo_pixel_vector.hpp"
#include "brightness_to_temperature_converter.hpp"
#include "temperature_range.hpp"
#include "current_thermo_frame.hpp"
#include "rect_thermal_spot.hpp"

#include "utilities.hpp"
#include "unistd.h"

#define DEFAULT_ABB_TEMPERATURE 41
#define DEFAULT_BACKGROUND_TEMPERATURE 27

#define EYE_WIDTH_COEFF  (3.0 / 8.0)
#define EYE_HEIGHT_COEFF (3.0 / 8.0)

#define PRIMARY_RANDOM_POINTS_NUMBER 8
#define SECONDARY_RANDOM_POINTS_NUMBER 3
#define SECONDARY_BASES_NUMBER 3

#define HEAD_CUT 1
#define CLASTER_BODY 7




class marked_thermo_frame
{
private:

    point left_eye_center;
    point right_eye_center;
    thermo_pixel abb_base_pixel;
    thermo_pixel background_base_pixel;
    thermo_pixel_vector left_eye_claster;
    thermo_pixel_vector right_eye_claster;
    thermo_pixel_vector secondary_layer_bases;
    rect_thermal_spot left_eye_spot;
    rect_thermal_spot right_eye_spot;

    temperature_range range;

    int manual_mark_counter;

    brightness_to_temperature_converter converter;

    cv::Mat mark_canvas;
    cv::Mat thermal_field;

    int eyes_span;
    int eye_spot_width;
    int eye_spot_height;
    int eye_spot_base_horizontal_offset;
    int eye_spot_base_vertical_offset;

    bool marked;

    double detect_temperature(rect_thermal_spot *spot, thermo_pixel_vector *claster);

    //***

    //void mark_frame_manually(current_thermo_frame frame_to_mark);
 
    
public:

    marked_thermo_frame(void);

    //void mark_frame(current_thermo_frame frame_to_mark);
    void mark_frame(cv::Mat frame_to_mark, int x, int y);

    void set_mark_canvas(cv::Mat value);
    cv::Mat get_mark_canvas(void);
    
    bool is_marked(void);
    void unmark(void);

    double left_eye_detect_temperature();
    double right_eye_detect_temperature();
    
        
};

