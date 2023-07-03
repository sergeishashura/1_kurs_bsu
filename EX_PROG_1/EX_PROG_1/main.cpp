//
//  main.cpp
//  EX_PROG_1
//
//  Created by Сергей Шашура on 7.06.23.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void convert_hex_to_dec(string);

int main()
{
    string hex_num;
    cout << "Enter string: " << endl;
    cin >> hex_num;
    convert_hex_to_dec(hex_num);
    return 0;
}

void convert_hex_to_dec(string hex_num)
{
    unsigned int lengh_hex_num = hex_num.length();
    int dec_num = 0;
    unsigned int base = 16;
    unsigned int j = 0;
    for (int i = lengh_hex_num - 1; i >= 0 ; i--)
    {
        if(hex_num[i] >= '0' && hex_num[i] <= '9')
        {
            dec_num += (hex_num[i] - '0') * pow(base, j);
        }
        else if (hex_num[i] >= 'A' && hex_num[i] <= 'F')
        {
            dec_num += (hex_num[i] - 'A' + 10) * pow(base, j);
        }
        if (hex_num[i] == '-')
        {
            dec_num *= -1;
        }
        j++;
    }
    
    cout << "Number " << hex_num <<  " in a decimal notation: " << dec_num << endl;
    
}
