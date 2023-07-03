#include "calculate_function.hpp"
#include <iostream>
#include <math.h>

using namespace std;

double calculate_function(double x, double s1, double t_next)
{
    return t_next * exp(0.5 * x)/pow((x + s1), 0.5);
}
