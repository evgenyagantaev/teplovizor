#pragma once

#include "opencv_headers.hpp"



class current_thermo_frame
{
private:

    cv::Mat frame;

    void capture_frame_from_file(void);

public:

    current_thermo_frame(void);

    void capture_frame(void);
    void show_frame(void);

    cv::Mat get_frame_mat(void); 

};
