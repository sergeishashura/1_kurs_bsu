#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void calculate_function_A (double a = 1, double b = 4);
double calculate_function_B (double x, double s);
double calculate_fun_B_by_chord_method(double s, int *k_iter, double a = 0, double b = 1);
double calculate_fun_A_by_chord_method(double s, int *k_iter, double x_prev, double x_curr);

int main()
{
    cout << "Function 1 starting... " << endl;
    calculate_function_A();
    cout << "" << endl;
    double s0 = 0.96;
    double sn = 1.02;
    cout << setw(3) << "s" << setw(10) << "x" << setw(15) << "f(x)" << setw(13) << "num"<< endl;
    cout << "___________________________________________" << endl;
    int k_iter;
    for (double s = s0; s <= sn; s += 0.02)
    {
        double x_fun_B = calculate_fun_B_by_chord_method(s, &k_iter);
        double result_fun_B = calculate_function_B(x_fun_B, s);
        cout << setw(5) << s << setw(10) << x_fun_B << setw (15) << result_fun_B << setw(13)<< k_iter <<endl;
    }
    return 0;
}
double calculate_function_A (double a, double b)
{
    cout << setw(5) << "x" << setw(10) << "f1(a)" << endl << "________________" << endl;
    for (double x = a; x <= b; x += 0.25)
    {
        double fun_A_x = pow((x + 1), 2) - 9;
        cout << setw(5) << x << setw(10) << fun_A_x << endl;
    }
    cout << endl << endl << endl;
    return fun_A_x;
}

double calculate_function_B (double x, double s)
{
    return pow(cos(M_PI * x), 2) - pow(M_E,pow(x,s)) + 1;
}
double calculate_fun_B_by_chord_method(double s, int *k_iter, double x_prev, double x_curr)
{
    double inf = 0.000001;
    double x_next = 0;
    double tmp;
    int count_iter = 0;
    do
    {
        tmp = x_next;
        x_next = x_curr - calculate_function_B(x_curr, s) * (x_prev - x_curr) / (calculate_function_B(x_prev, s) - calculate_function_B(x_curr, s));
        x_prev = x_curr;
        x_curr = tmp;
        count_iter++;
    }
    while (abs(x_next - x_curr) > inf);
    *k_iter = count_iter;
    return x_next;
}
double calculate_fun_A_by_chord_method(double s, int *k_iter, double x_prev, double x_curr)
{
    double inf = 0.000001;
    double x_next = 0;
    double tmp;
    int count_iter = 0;
    do
    {
        tmp = x_next;
        x_next = x_curr - calculate_function_B(x_curr, s) * (x_prev - x_curr) / (calculate_function_B(x_prev, s) - calculate_function_B(x_curr, s));
        x_prev = x_curr;
        x_curr = tmp;
        count_iter++;
    }
    while (abs(x_next - x_curr) > inf);
    *k_iter = count_iter;
    return x_next;
}

