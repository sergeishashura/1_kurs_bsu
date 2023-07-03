#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void calculate_function_A (double a, double b);
double calculate_function_B (double x, double s);
double bFunDouble(double x);
double calculate_by_chord_method(double a, double b, double s);

int main()
{
    double a = 1;
    double b = 4;
    cout << "Function 1 starting... " << endl;
    calculate_function_A(a,b);
    cout << "" << endl;
    a = 0;
    b = 1;
    double s0 = 0.96;
    double sn = 1.02;
    cout << setw(3) << "s" << setw(10) << "x" << setw(15) << "f(x)" << setw(13) << "num"<< endl;
    cout << "___________________________________________" << endl;
    for (double s = s0; s <= sn; s += 0.02)
    {
        double x_fun_B = calculate_by_chord_method(a, b, s);
        double result_fun_B = calculate_function_B(x_fun_B, s);
        cout << setw(5) << s << setw(10) << x_fun_B << setw (15) << result_fun_B << setw(13)<<  endl;
    }
    return 0;
    
}

void calculate_function_A (double a, double b)
{
    cout << setw(5) << "x" << setw(10) << "f1(a)" << endl << "________________" << endl;
    for (double x = a; x <= b; x += 0.25)
    {
        double fx = pow((x + 1), 2) - 9;
        cout << setw(5) << x << setw(10) << fx << endl;
    }
    cout << endl << endl << endl;
}

double calculate_function_B (double x, double s)
{
    double f_b = pow(cos(M_PI * x), 2) - pow(M_E,pow(x,s)) + 1;
    return f_b;
}
double bFunDouble(double x)
{
 double f_b_2 = (2 * exp(x) - 1) / (exp(x));
 return f_b_2;
}

double calculate_by_chord_method(double a, double b, double s)
{
    double inf = 0.000001;
    int k_iter = 0;
    double c = 0;
    double x = 0;
    
    if (calculate_function_B(a, s) * bFunDouble(a) > 0)
    {
        c = a;
    }
    else
    {
        if (calculate_function_B(b, s) * bFunDouble(b) > 0)
        {
            c = b;
        }
    }
    
    if (calculate_function_B(a, s) * bFunDouble(a) < 0)
    {
        x = a;
    }
    else
    {
        if (calculate_function_B(b, s) * bFunDouble(b) < 0)
        {
            x = b;
        }
    }
    
    while (true)
    {
        k_iter++;
        double delta_x = (calculate_function_B(x, s) * (x - c)) / (calculate_function_B(x, s) - calculate_function_B(c, s));
        x -= delta_x;
        if (abs(delta_x) < inf)
            
            return x;
    }
}
