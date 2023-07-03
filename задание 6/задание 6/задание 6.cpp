#include <iostream>
#include<math.h>
using namespace std;
int main() {
    double x = 0.0, y = 0.0;
    cin >> x >> y;
     if ( x>0 && y>0) { x = (-1)* x; y = (-1)* y;
         cout << x << y ;}
    else
if ( x>0 || y>0) {x = x / 2.5; y = y / 2.5;
         cout << x << y ;}
    else
if ( x<0 && x<0 && (((-5)<x && x<(-2)) || ((-5)<y && y<(-2)))) {x = x * 10; y = y * 10;
         cout << x  << y ;}
   else
         cout << x  << y ;
    return 0;
    
}
