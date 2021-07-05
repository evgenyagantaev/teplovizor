#include "current_thermo_frame.hpp"

using namespace cv;

current_thermo_frame::current_thermo_frame()
{
    
}


void current_thermo_frame::capture_frame(void)
{
    capture_frame_from_file();
}

void current_thermo_frame::capture_frame_from_file(void)
{
    frame = imread("face0.png", 0);
}

void current_thermo_frame::show_frame(void)
{
    namedWindow("frame", WINDOW_NORMAL);
    imshow("frame", frame);
}


cv::Mat current_thermo_frame::get_frame_mat(void)
{
    return current_thermo_frame::frame;
}