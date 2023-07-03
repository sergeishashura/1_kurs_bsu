#include <iostream>
#include<math.h>
using namespace std;
int main() {
    double x = 0.0, y = 0.0;
    cin >> x >> y;
(x>0 && y>0)?  (cout << -x << -y) : (x>0 || y>0)?
    (cout << x / 2.5 << y / 2.5) :
( x<0 && x<0 && (((-5)<x && x<(-2)) || ((-5)<y && y<(-2)))) ?
    (cout << x*10 << y * 10) :
cout << x << y ;
    return 0;
}
