#include "marked_thermo_frame.hpp"

//#define DEBUG_CONSOLE_OUTPUT
#define VISUAL_DEBUG
#define MANUAL_MARK
#define THREE_LAYERS


using namespace cv;
using namespace std;

marked_thermo_frame::marked_thermo_frame(void)
{
    manual_mark_counter = 0;
    marked = false;

    #ifdef MANUAL_MARK
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    namedWindow("manual mark window", WINDOW_NORMAL);
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif
    
}

void marked_thermo_frame::set_mark_canvas(Mat value)
{
    mark_canvas = value;
    thermal_field = mark_canvas.clone();

    #ifdef MANUAL_MARK
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    putText(mark_canvas, "mark left eye", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif
}

Mat marked_thermo_frame::get_mark_canvas(void)
{
    return mark_canvas;
}




void marked_thermo_frame::mark_frame(cv::Mat frame_to_mark, int x, int y)
{
    

    if(manual_mark_counter == 0) 
    {
        left_eye_center.set_point(x, y);
        manual_mark_counter++;

        #ifdef DEBUG_CONSOLE_OUTPUT
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        cout << "mark_frame >> left eye position = " << left_eye_center.getx() << "   " << left_eye_center.gety() << endl;
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        #ifdef MANUAL_MARK
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        mark_canvas = thermal_field.clone();
        putText(mark_canvas, "mark right eye", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif
    }
    else if(manual_mark_counter == 1) 
    {
        right_eye_center.set_point(x, y);
        manual_mark_counter++;

        #ifdef DEBUG_CONSOLE_OUTPUT
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        cout << "mark_frame >> right eye position = " << right_eye_center.getx() << "   " << right_eye_center.gety() << endl;
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        #ifdef MANUAL_MARK
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        mark_canvas = thermal_field.clone();
        putText(mark_canvas, "mark ABB", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif
    }
    else if(manual_mark_counter == 2) 
    {
        abb_base_pixel.set_position(x, y);
        manual_mark_counter++;

        abb_base_pixel.set_brightness((int)frame_to_mark.at<uchar>(y,x));
        abb_base_pixel.set_temperature(DEFAULT_ABB_TEMPERATURE);

        #ifdef DEBUG_CONSOLE_OUTPUT
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        cout << "mark_frame >> abb position = " << abb_base_pixel.get_position().getx() << "   " << abb_base_pixel.get_position().gety() << endl;
        cout << "mark_frame >> abb brightness = " << abb_base_pixel.get_brightness() << endl;
        cout << "mark_frame >> abb temperature = " << abb_base_pixel.get_temperature() << endl;
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        #ifdef MANUAL_MARK
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        mark_canvas = thermal_field.clone();
        putText(mark_canvas, "mark background", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif
    }
    else if(manual_mark_counter == 3) 
    {
        background_base_pixel.set_position(x, y);
        manual_mark_counter = 0;
        
        background_base_pixel.set_brightness((int)frame_to_mark.at<uchar>(y,x));
        background_base_pixel.set_temperature(DEFAULT_BACKGROUND_TEMPERATURE);

        #ifdef DEBUG_CONSOLE_OUTPUT
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        cout << "mark_frame >> abb position = " << background_base_pixel.get_position().getx() << "   " << background_base_pixel.get_position().gety() << endl;
        cout << "mark_frame >> background brightness = " << background_base_pixel.get_brightness() << endl;
        cout << "mark_frame >> background temperature = " << background_base_pixel.get_temperature() << endl;
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        #ifdef MANUAL_MARK
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        draw_cross(mark_canvas, y, x, BLACK);
        imshow("manual mark window", mark_canvas);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif


        converter.calibrate(abb_base_pixel.get_brightness(), abb_base_pixel.get_temperature(), 
                            background_base_pixel.get_brightness(), background_base_pixel.get_temperature());

        eyes_span = left_eye_center.getx() - right_eye_center.getx();
        eye_spot_width = (int)(eyes_span * EYE_WIDTH_COEFF);
        eye_spot_height = eye_spot_width;
        eye_spot_base_horizontal_offset = eye_spot_width;
        eye_spot_base_vertical_offset = (int)(eye_spot_width/2);

        marked = true;


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
    mark_canvas = thermal_field.clone();
}


double marked_thermo_frame::left_eye_detect_temperature()
{
    left_eye_spot.set_base(left_eye_center.getx() - eye_spot_base_horizontal_offset, left_eye_center.gety() - eye_spot_base_vertical_offset);
    left_eye_spot.set_width(eye_spot_width);
    left_eye_spot.set_height(eye_spot_height);

    return detect_temperature(&left_eye_spot, &left_eye_claster);
}

double marked_thermo_frame::right_eye_detect_temperature()
{
    right_eye_spot.set_base(right_eye_center.getx(), right_eye_center.gety() - eye_spot_base_vertical_offset);
    right_eye_spot.set_width(eye_spot_width);
    right_eye_spot.set_height(eye_spot_height);

    return detect_temperature(&right_eye_spot, &right_eye_claster);
}


double marked_thermo_frame::detect_temperature(rect_thermal_spot *spot, thermo_pixel_vector *claster)
{
    #ifdef VISUAL_DEBUG
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    mark_canvas = thermal_field.clone();
    putText(mark_canvas, "primary layer random points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
    imshow("manual mark window", mark_canvas);
    waitKey(100);
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif

    int i;
    for(i=0; i<PRIMARY_RANDOM_POINTS_NUMBER; i++)
    {
        
        point random_point = (*spot).generate();
        
        #ifdef VISUAL_DEBUG
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        draw_cross(mark_canvas, random_point.gety(), random_point.getx(), BLACK);
        imshow("manual mark window", mark_canvas);
        waitKey(700);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        thermo_pixel random_pixel;
        random_pixel.set_position(random_point.getx(), random_point.gety());
        random_pixel.set_brightness((int)thermal_field.at<uchar>(random_point.gety(),random_point.getx()));
        random_pixel.set_temperature(converter.convert(random_pixel.get_brightness()));

        #ifdef DEBUG_CONSOLE_OUTPUT
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        cout << " >> " << random_pixel.get_temperature() << " << " << endl;
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        if(range.check(random_pixel.get_temperature()))
        {
            (*claster).add_pixel(random_pixel);
        }   
    }

    
    #ifdef VISUAL_DEBUG
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    waitKey(2000);
    mark_canvas = thermal_field.clone();
    imshow("manual mark window", mark_canvas);
    waitKey(100);
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif
    
    secondary_layer_detect(spot, claster); // second layer

    #ifdef THREE_LAYERS
    secondary_layer_detect(spot, claster); // third layer
    #endif

    double temperature = 0;
    int index = HEAD_CUT;
    while (index < (HEAD_CUT + CLASTER_BODY) && (index < (*claster).get_current_length()))
    {
        temperature += (*claster).get_pixel(index).get_temperature();
        index++;
    }
    temperature /= CLASTER_BODY;
    
    return temperature;
    
}


void marked_thermo_frame::secondary_layer_detect(rect_thermal_spot *spot, thermo_pixel_vector *claster)
{
    if((*claster).get_current_length() >= SECONDARY_BASES_NUMBER)
    {

        secondary_layer_bases.clean();
        int i;
        for(i=0; i<SECONDARY_BASES_NUMBER; i++)
        {
            secondary_layer_bases.add_pixel((*claster).get_pixel(i));
        }

        #ifdef VISUAL_DEBUG
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        mark_canvas = thermal_field.clone();
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
        for(i=0; i<SECONDARY_BASES_NUMBER; i++)
        {
            point p = secondary_layer_bases.get_pixel(i).get_position();
            draw_cross(mark_canvas, p.gety(), p.getx(), BLACK);
        }
        putText(mark_canvas, "secondary layer base points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
         mark_canvas = thermal_field.clone();
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
        for(i=0; i<SECONDARY_BASES_NUMBER; i++)
        {
            point p = secondary_layer_bases.get_pixel(i).get_position();
            draw_cross(mark_canvas, p.gety(), p.getx(), BLACK);
        }
        putText(mark_canvas, "secondary layer base points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
         mark_canvas = thermal_field.clone();
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
        for(i=0; i<SECONDARY_BASES_NUMBER; i++)
        {
            point p = secondary_layer_bases.get_pixel(i).get_position();
            draw_cross(mark_canvas, p.gety(), p.getx(), BLACK);
        }
        putText(mark_canvas, "secondary layer base points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        imshow("manual mark window", mark_canvas);
        waitKey(1000);
        mark_canvas = thermal_field.clone();
        putText(mark_canvas, "secondary layer random points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
        imshow("manual mark window", mark_canvas);
        waitKey(100);
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif

        for(i=0; i<SECONDARY_BASES_NUMBER; i++)
        {
            int x = secondary_layer_bases.get_pixel(i).get_position().getx();
            int y = secondary_layer_bases.get_pixel(i).get_position().gety();

            #ifdef DEBUG_CONSOLE_OUTPUT
            //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
            cout << i << " >> secondary base " << endl;
            //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
            #endif

            int width = (int)(eye_spot_width / 2);
            int height = width;
            int horizontal_offset = (int)(width / 2);
            int vertical_offset = horizontal_offset;

            (*spot).set_base(x - horizontal_offset, y - vertical_offset);
            (*spot).set_width(width);
            (*spot).set_height(height);

            int j;
            for(j=0; j<SECONDARY_RANDOM_POINTS_NUMBER; j++)
            {
                
                point random_point = (*spot).generate();

                #ifdef VISUAL_DEBUG
                //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                draw_cross(mark_canvas, random_point.gety(), random_point.getx(), BLACK);
                imshow("manual mark window", mark_canvas);
                waitKey(700);
                //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                #endif

                thermo_pixel random_pixel;
                random_pixel.set_position(random_point.getx(), random_point.gety());
                random_pixel.set_brightness((int)thermal_field.at<uchar>(random_point.gety(),random_point.getx()));
                random_pixel.set_temperature(converter.convert(random_pixel.get_brightness()));

                #ifdef DEBUG_CONSOLE_OUTPUT
                //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                cout << " >> secondary random " << random_pixel.get_temperature() << " << " << endl;
                //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                #endif

                if(range.check(random_pixel.get_temperature()))
                {
                    (*claster).add_pixel(random_pixel);

                    #ifdef DEBUG_CONSOLE_OUTPUT
                    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                    cout << "claster length = " << (*claster).get_current_length() << endl;
                    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
                    #endif
                } 
                 
            }

            #ifdef VISUAL_DEBUG
            //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
            waitKey(2000);
            mark_canvas = thermal_field.clone();
            putText(mark_canvas, "secondary layer random points", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);
            imshow("manual mark window", mark_canvas);
            waitKey(100);
            //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
            #endif
            

        }//end   for(i=0; i<SECONDARY_BASES_NUMBER; i++)

        #ifdef VISUAL_DEBUG
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        mark_canvas = thermal_field.clone();
        putText(mark_canvas, "secondary layer claster", Point(30,30), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0,0,0), 2);

        int k;
        for(k=0; k<PRIMARY_RANDOM_POINTS_NUMBER; k++)
        {
            point cross_position = (*claster).get_pixel(k).get_position();
            draw_cross(mark_canvas, cross_position.gety(), cross_position.getx(), BLACK);
            imshow("manual mark window", mark_canvas);
            waitKey(700);
        }
        //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
        #endif
    }
}