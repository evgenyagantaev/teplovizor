#include "main.hpp"

using namespace cv;

current_thermo_frame curr_frame;


int main( int argc, const char** argv )
{
    curr_frame.capture_frame();
    curr_frame.show_frame();

    waitKey(0);  
    return 0;
}