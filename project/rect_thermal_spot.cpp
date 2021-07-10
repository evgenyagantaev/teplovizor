#include "rect_thermal_spot.hpp"

//#define DEBUG_CONSOLE_OUTPUT

using namespace cv;
using namespace std;   

rect_thermal_spot::rect_thermal_spot()
{
    time_t rawtime;
    tm * ptm;
    time (&rawtime);
    rng_seed = (uint64_t)rawtime;
    random_generator = RNG(rng_seed);

    #ifdef DEBUG_CONSOLE_OUTPUT
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    cout << "random generator seed >> " << rng_seed << endl;
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif
    
}

void rect_thermal_spot::set_base(int x, int y)
{
    base_point.set_point(x, y);
}
void rect_thermal_spot::set_width(int value)
{
    width = value;
}
void rect_thermal_spot::set_height(int value)
{
    height = value;
}

point rect_thermal_spot::get_base(void)
{
    return base_point;
}
int rect_thermal_spot::get_width(void)
{
    return width;
}
int rect_thermal_spot::get_height(void)
{
    return height;
}

point rect_thermal_spot::generate()
{
    int x = random_generator.uniform(base_point.getx(), base_point.getx() + width);
    int y = random_generator.uniform(base_point.gety(), base_point.gety() + height);

    #ifdef DEBUG_CONSOLE_OUTPUT
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    cout << "random point >> " << x << "  " << y << endl;
    //DEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUGDEBUG
    #endif

    point return_value;
    return_value.set_point(x, y);

    return return_value;
}