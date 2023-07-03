//
//  main.cpp
//  задание 2
//
//  Created by Сергей Шашура on 9.09.22.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // insert code here...
    int x, k, c1, d1, c2, d2, c3, d3;
   
    cin >> x;
    k = 9;
    
    c1 = x / 1000;
    d1 = x % 1000;
    c2 =  d1 / 100;
    d2 = d1 % 100;
    c3 = d2 / 10;
    d3 = d2 % 10;
     
    if (c1 == k or c2 == k or c3 == k or d3 == k)
        cout << "yes ";
    else cout << "no ";
    
    
}
