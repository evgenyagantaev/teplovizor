#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
using namespace cv;

#define WHITE 0xff
#define BLACK 0x00

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



// Create a variable to save the position value in track
int blurAmount=15;


// Trackbar call back function
static void onChange(int pos, void* userInput);
//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput );


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

int main( int argc, const char** argv )
{
    // Read images
    //Mat color= imread("face1.jpg");
    Mat pair[2];
    pair[0] = imread("face0.png", 0);
    pair[1] = imread("face0.png", 0);
    // Write images
    //imwrite("face0_gray.jpg", gray);
    // Get same pixel with opencv function
    //int p_row = (int)(gray.rows/2);
    //int p_col = (int)(gray.cols/2);
    //p_row -= 8;
    //p_col += 135;
    //p_row = 4;
    //p_col = 4;
    //draw_cross(&gray, p_row, p_col, BLACK);
    //Vec3b pixel= color.at<Vec3b>(myRow, myCol);
    //cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," <<
    //(int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
    cout << "matrix[" << pair[0].rows << "," << pair[0].cols << "]" << endl;
    //cout << "pixel[" << p_row << "," << p_col << "] -> " << (int)gray.at<uchar>(p_row,p_col) << endl;
    // show images
    //imshow("face1 BGR", color);
    namedWindow("face0", WINDOW_NORMAL);
    imshow("face0", pair[0]);

    // create a trackbark
    //createTrackbar("face0", "face0", &blurAmount, 30, onChange, &gray);
    
    setMouseCallback("face0", onMouse, pair);

    // Call to onChange to init
    //onChange(blurAmount, &gray);

    // wait for any key press
    waitKey(0);  
    return 0;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************



// Trackbar call back function
static void onChange(int pos, void* userData)
{
    if(pos <= 0)
    return;
    // Aux variable for result
    Mat imgBlur;
    // Get the pointer input image
    Mat* img= (Mat*)userData;
    // Apply a blur filter
    blur(*img, imgBlur, Size(pos, pos));
    // Show the result
    imshow("face0", imgBlur);
}


//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput )
{
    if( event != EVENT_LBUTTONDOWN )
    return;
    // Get the pointer input image
    Mat* pair = (Mat*)userInput;
    Mat* src = pair;
    Mat* dst = &(pair[1]);
    // Draw circle
    //circle(*img, Point(x, y), 10, Scalar(0,255,0), 3);

    draw_cross(dst, y, x, BLACK);
    cout << "pixel[" << y << "," << x << "] -> " << (int)src->at<uchar>(y,x) << endl;

    // Show the result
    imshow("face0", *dst);

    // Call on change to get blurred image
    //onChange(blurAmount, img);
}

