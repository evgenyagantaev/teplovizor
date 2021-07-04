#pragma once

#include "thermometry.hpp"

class marked_thermo_frame
{
private:

    point left_eye_center;
    point right_eye_center;
    thermo_pixel abb_base_pixel;
    thermo_pixel background_base_pixel;

    current_thermo_frame frame_to_mark;

    void mark_frame_manually();
    
public:

    void mark_frame();
    
};

