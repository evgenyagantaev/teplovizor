#include "thermo_pixel.hpp"


thermo_pixel::thermo_pixel()
{
    position = point();
    brightness = UNREAL_BRIGHTNESS;
    temperature = UNREAL_TEMPERATURE;
}

void thermo_pixel::set_position(int x, int y)
{
    position.set_point(x, y);
}


void thermo_pixel::set_brightness(int value)
{
    brightness = value;
}
void thermo_pixel::set_temperature(double value)
{
    temperature = value;
}

point thermo_pixel::get_position(void)
{
    return position;
}
int thermo_pixel::get_brightness(void)
{
    return brightness;
}
double thermo_pixel::get_temperature(void)
{
    return temperature;
}