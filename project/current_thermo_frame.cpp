#include "current_thermo_frame.hpp"


void current_thermo_frame::capture_frame(void)
{
    capture_frame_from_file(debug_file_name);
}

void current_thermo_frame::capture_frame_from_file(uchar *filename)
{
    frame = imread(filename, 0);
}

void current_thermo_frame::show_frame(void)
{
    namedWindow("frame", WINDOW_NORMAL);
    imshow("frame", frame);
}