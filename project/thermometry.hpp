#pragma once

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


#define TEMPERATURE_LOW_BOUND 33
#define TEMPERATURE_UP_BOUND 40

struct point
{
    int x;
    int y;
};



class thermometry
{
private:
    
public:

    thermometry();
    ~thermometry();
};



