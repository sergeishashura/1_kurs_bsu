//
//  main.cpp
//  ккк
//
//  Created by Сергей Шашура on 13.09.22.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // insert code here...
    int x, d1, d2, d3, d4, k, s;
    
    cin>> x;
    
    k = 9;
    s=0;
    
    d1 = x / 1000;
    x = x % 1000;
    d2 = x / 100;
    x = x % 100;
    d3 = x / 10;
    d4 = x % 10;
    
    if ( d1 == k) s++;
    if (d2 == k) s++;
    if (d3 == k) s++;
    if (d4 == k) s++;
    
    {if (s >= 3) cout<< "yes ";
        else cout << "no ";}
    
    return 0;
}
