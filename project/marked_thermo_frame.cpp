#include "marked_thermo_frame.hpp"

using namespace cv;
using namespace std;

marked_thermo_frame::marked_thermo_frame(void)
{
    manual_mark_counter = 0;
}

void marked_thermo_frame::mark_frame_manually(current_thermo_frame frame_to_mark)
{
    //frame_to_mark = imread("face0.png", 0);
    namedWindow("manual mark window", WINDOW_NORMAL);
    
    Mat mark_canvas = frame_to_mark.get_frame_mat();

    imshow("manual mark window", mark_canvas);

    
}



void marked_thermo_frame::mark_frame(current_thermo_frame frame_to_mark)
{
    mark_frame_manually(frame_to_mark);
}

