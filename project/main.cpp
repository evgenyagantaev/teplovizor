#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

void draw_cross(Mat *img, int i, int j)
{
    if((i>2) && (j>2) && (i<(img->rows - 3)) && (j<(img->cols - 3)))
    {
        img->at<uchar>(i,j) = 0;
        img->at<uchar>(i-1,j) = 0;
        img->at<uchar>(i-2,j) = 0;
        img->at<uchar>(i-3,j) = 0;
        img->at<uchar>(i+1,j) = 0;
        img->at<uchar>(i+2,j) = 0;
        img->at<uchar>(i+3,j) = 0;
        img->at<uchar>(i,j-1) = 0;
        img->at<uchar>(i,j-2) = 0;
        img->at<uchar>(i,j-3) = 0;
        img->at<uchar>(i,j+1) = 0;
        img->at<uchar>(i,j+2) = 0;
        img->at<uchar>(i,j+3) = 0;
    }
    
}



int main( int argc, const char** argv )
{
    // Read images
    //Mat color= imread("face1.jpg");
    Mat gray= imread("face0.png", 0);
    // Write images
    imwrite("face0_gray.jpg", gray);
    // Get same pixel with opencv function
    int p_row = (int)(gray.rows/2);
    int p_col = (int)(gray.cols/2);
    //p_row -= 8;
    //p_col += 135;
    //p_row = 4;
    //p_col = 4;
    draw_cross(&gray, p_row, p_col);
    //Vec3b pixel= color.at<Vec3b>(myRow, myCol);
    //cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," <<
    //(int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
    cout << "matrix[" << gray.rows << "," << gray.cols << "]" << endl;
    cout << "pixel[" << p_row << "," << p_col << "] -> " << (int)gray.at<uchar>(p_row,p_col) << endl;
    // show images
    //imshow("face1 BGR", color);
    imshow("face0 gray", gray);
    // wait for any key press
    waitKey(0);
    return 0;
}