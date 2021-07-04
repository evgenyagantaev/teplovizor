#include "marked_thermo_frame.hpp"

using namespace cv;

void marked_thermo_frame::mark_frame_manually()
{
    frame_to_mark = imread("face0.png", 0);
    namedWindow("mark sample", WINDOW_NORMAL);
    imshow("mark sample", frame_to_mark);
}



void marked_thermo_frame::mark_frame()
{
    marked_thermo_frame::mark_frame_manually();
}