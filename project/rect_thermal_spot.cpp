#include "rect_thermal_spot.hpp"

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