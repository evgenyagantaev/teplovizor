#pragma once

#include "thermometry.hpp"

class current_thermo_frame
{
private:

    cv::Mat frame;

    void capture_frame_from_file(void);
    //uchar debug_file_name[64];
    const string debug_file_name;

public:

    current_thermo_frame(void);

    void capture_frame(void);
    void show_frame(void);

};
