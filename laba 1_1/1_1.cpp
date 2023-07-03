#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
void equation()
{
    int x, y, d1, d2, d3, d4, d5, D6, d7, d8, d9, d10, d11, d12;
    cin >> x;
    d1 = pow(x, 2);
    d2 = d1 * M_PI;
    d3 = sin(d2);
    d4 = log10(x);
    d5 = d4 + d3;
    D6 = sin(d5);
    d7 = pow(x, 2);
    d8 = sin(x);
    d9 = cos(x);
    d10 = pow(M_E, d9);
    d11 = d7 + d8 + d10;
    d12 = pow(d11, 1.0 / 4);
    y = d5 * d12;

    cout << y;
}
