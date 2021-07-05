#include "main.hpp"


//***

//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput );

//***

using namespace cv;

current_thermo_frame curr_frame;
marked_thermo_frame marked_frame;



int main( int argc, const char** argv )
{
    namedWindow("face0", WINDOW_NORMAL);

    curr_frame.capture_frame();
    Mat curr_frame_mat = curr_frame.get_frame_mat();

    marked_frame.mark_frame(curr_frame);

    setMouseCallback("face0", onMouse, &curr_frame_mat);

    waitKey(0);  
    return 0;
}

//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput )
{
    Mat *dst = (Mat *)userInput;

    if( event == EVENT_LBUTTONDOWN )
    {
    
        cout << "pixel[" << y << "," << x << "] -> " << (int)dst->at<uchar>(y,x) << endl;

        // Show the result
        imshow("face0", *dst);

    }

 }