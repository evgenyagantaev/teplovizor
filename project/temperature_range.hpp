#pragma once




class temperature_range
{
private:
    double low_bound;
    double up_bound;

public:
    temperature_range();
    ~temperature_range();

    bool check(double temperature);
};

