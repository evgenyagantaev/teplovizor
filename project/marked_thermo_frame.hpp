#pragma once

#include "point.hpp"
#include "thermo_pixel.hpp"
#include "current_thermo_frame.hpp"

class marked_thermo_frame
{
private:

    point left_eye_center;
    point right_eye_center;
    thermo_pixel abb_base_pixel;
    thermo_pixel background_base_pixel;

    //***

    void mark_frame_manually(current_thermo_frame frame_to_mark);
    
    
public:

    void mark_frame(current_thermo_frame frame_to_mark);
    
};

