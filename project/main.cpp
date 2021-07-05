#include "main.hpp"

using namespace cv;

//***

//Mouse callback
void draw_cross(Mat *img, int i, int j, uint8_t brightness);
static void onMouse( int event, int x, int y, int, void* userInput );

//***



current_thermo_frame curr_frame;
marked_thermo_frame marked_frame;



int main( int argc, const char** argv )
{
    
    curr_frame.capture_frame();
    Mat curr_frame_mat = curr_frame.get_frame_mat();

    imshow("manual mark window", curr_frame_mat);

    setMouseCallback("manual mark window", onMouse, &curr_frame_mat);

    marked_frame.mark_frame(curr_frame);

    waitKey(0);  
    return 0;
}

//Mouse callback
//*
static void onMouse( int event, int x, int y, int, void* userInput )
{
    Mat *dst = (Mat *)userInput;

    if( event == EVENT_LBUTTONDOWN )
    {
    
        draw_cross(dst, y, x, BLACK);
        cout << "pixel[" << y << "," << x << "] -> " << (int)dst->at<uchar>(y,x) << endl;

        // Show the result
        imshow("manual mark window", *dst);

    }

 }
 //*/


void draw_cross(Mat *img, int i, int j, uint8_t brightness)
{
    if((i>2) && (j>2) && (i<(img->rows - 3)) && (j<(img->cols - 3)))
    {
        //img->at<uchar>(i,j) = brightness;
        img->at<uchar>(i-1,j) = brightness;
        img->at<uchar>(i-2,j) = brightness;
        img->at<uchar>(i-3,j) = brightness;
        img->at<uchar>(i+1,j) = brightness;
        img->at<uchar>(i+2,j) = brightness;
        img->at<uchar>(i+3,j) = brightness;
        img->at<uchar>(i,j-1) = brightness;
        img->at<uchar>(i,j-2) = brightness;
        img->at<uchar>(i,j-3) = brightness;
        img->at<uchar>(i,j+1) = brightness;
        img->at<uchar>(i,j+2) = brightness;
        img->at<uchar>(i,j+3) = brightness;
    }
    
}