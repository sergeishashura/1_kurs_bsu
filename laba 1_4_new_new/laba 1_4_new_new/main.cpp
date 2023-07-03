#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double calculate_function_A (double x, double s);
double calculate_function_B (double x, double s);
void calculate_fun_by_chord_method(double (*func)(double, double),  double a = 1, double b = 4, double s = 0, double eps = 1e-6);

int main()
{
   // double a_fun_A = 1, b_fun_A = 4;
    cout << "Function A" << endl;
    cout << setw(3) << "s" << setw(10) << "x" << setw(15) << "f(x)" << setw(13) << "num"<< endl;
    cout << "___________________________________________" << endl;
    
    calculate_fun_by_chord_method(calculate_function_A);
    
    cout << "Function B" << endl;
    cout << setw(3) << "s" << setw(10) << "x" << setw(15) << "f(x)" << setw(13) << "num"<< endl;
        cout << "___________________________________________" << endl;
    
    double a_fun_B = 0, b_fun_B = 1;
    double s0 = 0.96;
    double sn = 1.02;
    for (double s = s0; s <= sn; s += 0.02)
    {
        calculate_fun_by_chord_method(calculate_function_B, a_fun_B, b_fun_B, s);
    }
    
    return 0;
}

void print(double s, double x_fun, double result_fun, int k_iter)
{
    cout << setw(5) << s << setw(10) << x_fun << setw (15) << result_fun << setw(13)<< k_iter <<endl;
}
double calculate_function_A(double x, double s)
{
    return pow((x + 1), 2) - 9;
}
double calculate_function_B(double x, double s)
{
    return pow(cos(M_PI * x), 2) - pow(M_E,pow(x,s)) + 1;
}

void calculate_fun_by_chord_method(double (*func)(double, double), double x_prev, double x_curr, double s, double eps)
{
   
    double x_next = 0;
    double tmp;
    int k_iter = 0;
    double result_fun = 0;
    do
    {
        tmp = x_next;
        x_next = x_curr - ((func(x_curr, s) * (x_prev - x_curr)) / (func(x_prev, s) - func(x_curr, s)));
        x_prev = x_curr;
        x_curr = tmp;
        k_iter++;
        
    }
    while (abs(x_next - x_curr) > eps);
    result_fun = func(x_next, s);
    print(s, x_next, result_fun, k_iter);
}

