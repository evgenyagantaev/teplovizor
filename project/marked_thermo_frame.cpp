#include "marked_thermo_frame.hpp"

using namespace cv;

void marked_thermo_frame::mark_frame_manually(current_thermo_frame frame_to_mark)
{
    //frame_to_mark = imread("face0.png", 0);
    namedWindow("mark sample", WINDOW_NORMAL);
    imshow("mark sample", frame_to_mark.get_frame_mat());
}



void marked_thermo_frame::mark_frame(current_thermo_frame frame_to_mark)
{
    mark_frame_manually(frame_to_mark);
}