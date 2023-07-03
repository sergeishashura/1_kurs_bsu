#include "calculate_integral_simpson_method.hpp"
#include "calculate_function.hpp"
#include <iostream>
#include <math.h>

using namespace std;

double calculate_integral_simpson_method(double (*fun)(double, double, double), double a, double b, int inf, double s1, double t1, int *k_iter)
{
    double Integral = 0;
    double h = (b - a) / inf;
    int count_iter = 0;
    for (int i = 0; i < inf; i++)
    {
        double x1 = a + i * h;
        double x2 = a + (i + 1) * h;
        Integral += (x2 - x1) / 6.0 * ((fun(x1, s1, t1) + 4.0 * fun(0.5 * (x1 + x2), s1, t1) + fun(x2, s1, t1)));
        count_iter++;
    }
    *k_iter = count_iter;
    return Integral;
}
