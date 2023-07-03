#include <iostream>
#include <math.h>
#include <iomanip>
#include "calculate_integral_simpson_method.hpp"
#include "calculate_function.hpp"
using namespace std;

int main()
{
    double s1 = 0.5, s2 = 2, step_s = 0.5;
    double t1 = 0.5, t2 = 4, step_t = 0.5;
    double a = 0, b = 1.047;
    int inf = 1000000;
    int k_iter;
    cout << setw(3) << "s" << setw(10) << "t" << setw(15) << "Int" << setw(13) << "k_iter"<< endl;
    cout << "___________________________________________" << endl;
    for (double t_next = t1; t_next <= t2; t_next += step_t)
    {
        double Int = calculate_integral_simpson_method(calculate_function, a, b, inf, s1, t_next, &k_iter);
        cout << setw(5) << s1 << setw(10) << t_next << setw (15) << Int<< setw(13)<< k_iter <<endl;
    }
    for (double s_next = s1; s_next <= s2; s_next += step_s)
    {
        double Int = calculate_integral_simpson_method(calculate_function, a, b, inf, s_next, t1, &k_iter);
        cout << setw(5) << s_next << setw(10) << t1<< setw (15) << Int<< setw(13)<< k_iter <<endl;
    }
    
    return 0;
}
