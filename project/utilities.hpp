#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "opencv_headers.hpp"

#define WHITE 0xff
#define BLACK 0x00



void draw_cross(cv::Mat img, int i, int j, uint8_t brightness);