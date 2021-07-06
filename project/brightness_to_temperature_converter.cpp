#include "brightness_to_temperature_converter.hpp"

using namespace std;


void brightness_to_temperature_converter::calibrate(int abb_brigthness, double abb_temperature, 
                                                    int background_brightness, double background_temperature)
{
    abb_br = abb_brigthness;
    abb_temp = abb_temperature;
    bg_br = background_brightness;
    bg_temp = background_temperature;

    K = (bg_temp - abb_temp)/(bg_br - abb_br);
    T0 = abb_temp - K * abb_br;

    cout << "converter calibrated T0 = " << T0 << ", K = " << K << endl;
}

double brightness_to_temperature_converter::convert(int brightness)
{
    return brightness * K + T0;
}