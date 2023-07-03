#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void dichotomy(double(*Func)(double, float), double a, double b, const double eps, const double sRight=0, const double sLeft=0,
               const double sDelta=1);
double Func2(double x, float s);
double Func1(double x, float s);
int main() {
    double a = -2, b = 1;
    double sRight = 1.95,
    sLeft = 2,
    sDelta = 0.01,
    eps = 1e-6;
    cout << "Func1" << setw(10) << "S" << setw(15) << "X" << setw(10) << "F(x)" << setw(20) << "k_iter" << '\n';
    dichotomy(Func1, a, b, eps);

    cout << "\nFunc2" << setw(10) << "S" << setw(15) << "X" << setw(10) << "F(x)" << setw(20) << "k_iter" << '\n';
    dichotomy(Func2, a, b, eps, sRight, sLeft, sDelta);
   
    
    return 0;
}

void print(float s, double x, double fx, int k_iter)
{
    cout << setw(15) << s << setw(15) << x << setw(15) << fx << setw(15) << k_iter << '\n';
    
}


void dichotomy (double(*func)(double, float), double a, double b, const double eps, double sLeft, const double sRight,
               const double sDelta)
{
   int a1 = a,
       b1 = b;
    int kItere = 0;
    double x = 0.0;
    while (sLeft <= sRight)
    {
        a = a1;
        b = b1;
       
        kItere = 0;
        double funcReturn = 0.0;
        while(abs((b - a)) >= eps)
        {
            kItere++;
            x = (a + b) / 2.0;
            funcReturn = func(x, sLeft);
            if(funcReturn == 0.0)
                break;
            else if (funcReturn * func(a, sLeft) < 0)
                b = x;
            else
                a = x;
        }
       
        print(sLeft, x, funcReturn, kItere);
        sLeft += sDelta;
    }
    return;
}


double Func2(double x, float s)
{
    return pow(cos(x), 2) - pow(x, 1.0 / s);
}
double Func1(double x,float s)
{
    return pow(x - 1, 2) - 3;
}
