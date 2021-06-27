#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
int main( int argc, const char** argv )
{
    // Read images
    Mat color= imread("face1.jpg");
    Mat gray= imread("face1.jpg", 0);
    // Write images
    imwrite("face1_gray.jpg", gray);
    // Get same pixel with opencv function
    int myRow=color.cols-1;
    int myCol=color.rows-1;
    Vec3b pixel= color.at<Vec3b>(myRow, myCol);
    cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," <<
    (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
    // show images
    imshow("face1 BGR", color);
    imshow("face1 Gray", gray);
    // wait for any key press
    waitKey(0);
    return 0;
}