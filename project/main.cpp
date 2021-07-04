#include "main.hpp"

using namespace cv;

current_thermo_frame curr_frame;
marked_thermo_frame marked_frame;


int main( int argc, const char** argv )
{
    curr_frame.capture_frame();
    //curr_frame.show_frame();

    marked_frame.mark_frame();

    waitKey(0);  
    return 0;
}