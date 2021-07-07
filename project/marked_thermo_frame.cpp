#include "marked_thermo_frame.hpp"

using namespace cv;
using namespace std;

marked_thermo_frame::marked_thermo_frame(void)
{
    manual_mark_counter = 0;
    marked = false;
    namedWindow("manual mark window", WINDOW_NORMAL);
    
}

void marked_thermo_frame::set_mark_canvas(Mat value)
{
    mark_canvas = value;
    thermal_field = mark_canvas.clone();
}

Mat marked_thermo_frame::get_mark_canvas(void)
{
    return mark_canvas;
}

/*
void marked_thermo_frame::mark_frame_manually(current_thermo_frame frame_to_mark)
{
    //frame_to_mark = imread("face0.png", 0);
    namedWindow("manual mark window", WINDOW_NORMAL);
    
    Mat mark_canvas = frame_to_mark.get_frame_mat();

    imshow("manual mark window", mark_canvas);

    
}
*/



void marked_thermo_frame::mark_frame(cv::Mat frame_to_mark, int x, int y)
{
    //mark_frame_manually(frame_to_mark);

    //Mat mark_canvas = frame_to_mark.get_frame_mat();

    if(manual_mark_counter == 0) 
    {
        left_eye_center.set_point(x, y);
        manual_mark_counter++;
        cout << "mark_frame >> left eye position = " << left_eye_center.getx() << "   " << left_eye_center.gety() << endl;

        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
    }
    else if(manual_mark_counter == 1) 
    {
        right_eye_center.set_point(x, y);
        manual_mark_counter++;
        cout << "mark_frame >> right eye position = " << right_eye_center.getx() << "   " << right_eye_center.gety() << endl;

        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
    }
    else if(manual_mark_counter == 2) 
    {
        abb_base_pixel.set_position(x, y);
        manual_mark_counter++;
        cout << "mark_frame >> abb position = " << abb_base_pixel.get_position().getx() << "   " << abb_base_pixel.get_position().gety() << endl;
        abb_base_pixel.set_brightness((int)frame_to_mark.at<uchar>(y,x));
        cout << "mark_frame >> abb brightness = " << abb_base_pixel.get_brightness() << endl;
        abb_base_pixel.set_temperature(DEFAULT_ABB_TEMPERATURE);
        cout << "mark_frame >> abb temperature = " << abb_base_pixel.get_temperature() << endl;

        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
    }
    else if(manual_mark_counter == 3) 
    {
        background_base_pixel.set_position(x, y);
        manual_mark_counter = 0;
        cout << "mark_frame >> abb position = " << background_base_pixel.get_position().getx() << "   " << background_base_pixel.get_position().gety() << endl;
        background_base_pixel.set_brightness((int)frame_to_mark.at<uchar>(y,x));
        cout << "mark_frame >> background brightness = " << background_base_pixel.get_brightness() << endl;
        background_base_pixel.set_temperature(DEFAULT_BACKGROUND_TEMPERATURE);
        cout << "mark_frame >> background temperature = " << background_base_pixel.get_temperature() << endl;

        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);

        converter.calibrate(abb_base_pixel.get_brightness(), abb_base_pixel.get_temperature(), 
                            background_base_pixel.get_brightness(), background_base_pixel.get_temperature());

        marked = true;

        int eyes_span = left_eye_center.getx() - right_eye_center.getx();
        int eye_spot_width = (int)(eyes_span * EYE_WIDTH_COEFF);
        int eye_spot_height = eye_spot_width;
        int eye_spot_base_horizontal_offset = eye_spot_width;
        int eye_spot_base_vertical_offset = (int)(eye_spot_width/2);

        left_eye_spot.set_base(left_eye_center.getx() - eye_spot_base_horizontal_offset, left_eye_center.gety() - eye_spot_base_vertical_offset);
        left_eye_spot.set_width(eye_spot_width);
        left_eye_spot.set_height(eye_spot_height);

        int i;
        for(i=0; i<8; i++)
        {
            point random_point = left_eye_spot.generate();
            draw_cross(mark_canvas, random_point.gety(), random_point.getx(), BLACK);
            imshow("manual mark window", mark_canvas);
        }

    }
}

bool marked_thermo_frame::is_marked(void)
{
    return marked;
}

void marked_thermo_frame::unmark(void)
{
    marked = false;
    manual_mark_counter = 0;
}