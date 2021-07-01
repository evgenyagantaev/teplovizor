#pragma once

#include "thermometry.hpp"



class current_thermo_frame
{
private:

    Mat frame;

    void capture_frame_from_file(uchar *filename);
    uchar debug_file_name[] = "face0.png";

public:

    void capture_frame(void);
    void show_frame(void);

};
