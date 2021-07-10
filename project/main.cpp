#include "main.hpp"
#include "utilities.hpp"

using namespace cv;
using namespace std;

//***

//Mouse callback
void draw_cross(Mat img, int i, int j, uint8_t brightness);
static void onMouse( int event, int x, int y, int, void* userInput );

//***



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************



int main( int argc, const char** argv )
{
    current_thermo_frame curr_frame;
    marked_thermo_frame marked_frame;
    
    curr_frame.capture_frame();
    Mat curr_frame_mat = curr_frame.get_frame_mat();
    marked_frame.set_mark_canvas(curr_frame_mat);

    imshow("manual mark window", curr_frame_mat);

    setMouseCallback("manual mark window", onMouse, &marked_frame);

    // waiting for manual markup completion
    cout << "manual markup waiting" << endl;
    waitKey(100);
    while(!marked_frame.is_marked())
    {
        waitKey(100);  
    }
    
    cout << "marked" << endl;
    waitKey(100);

    //double left_eye_temp = marked_frame.left_eye_detect_temperature();

    cout << endl;
    //cout << "left eye temp >>>>> " << left_eye_temp << " <<<<<" << endl;  
    cout << "hit some key to detect right eye temperature " << endl; 
    
    //waitKey(0);  

    //double right_eye_temp = marked_frame.right_eye_detect_temperature();

    cout << endl;
    //cout << "right eye temp >>>>> " << right_eye_temp << " <<<<<" << endl;  
    cout << "hit some key to detect forehead temperature " << endl; 
    
    //waitKey(0);  

    double forehead_temp = marked_frame.forehead_detect_temperature();

    cout << endl;
    cout << "forehead temp >>>>> " << forehead_temp << " <<<<<" << endl;  

    waitKey(0);  
    

    return 0;
}



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************






//Mouse callback
//*
static void onMouse( int event, int x, int y, int, void* userInput )
{
    marked_thermo_frame *marked_frame = (marked_thermo_frame *)userInput;

    if( event == EVENT_LBUTTONDOWN )
    {
        Mat dst = marked_frame->get_mark_canvas();
    
        draw_cross(dst, y, x, BLACK);
        cout << "pixel[" << y << "," << x << "] -> " << (int)dst.at<uchar>(y,x) << endl;

        if(!(marked_frame->is_marked()))
        {
            marked_frame->mark_frame(dst, x, y);
        }

        // Show the result
        //imshow("manual mark window", *dst);

    }

 }
 //*/


