//
//
//  для для сверки : https://www.desmos.com/calculator?lang=ru//
//  Created by Сергей Шашура on 15.09.22.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x, y;
    y = 0.0;
    
    
    
    cin>> x;
    
    
    if (x >= (-8) && x <= (-2)) y = (x+2)/6;
            
    
    if (x > (-2) && x <= 0) y = 2-(sqrt(4-(pow(x+2,2))));
   
    
    if (x > 0 && x <= 2) y = sqrt (4-(pow(x,2)));
                    
  
    if (x > 2 && x <= 3) y = 2 - x;
                        
       cout<< y ;
       
    
                      
    
    return 0;
   
       }
