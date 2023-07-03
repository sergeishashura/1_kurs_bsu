#include "output_array.hpp"
#include <iostream>
using namespace std;
void check_and_output(int* arr, int n)
{
    cout << endl;
    for (int i = n; i > 0; i--)
    {
        if (arr[i] == 1)
        {
            cout << i << " ";
        }
    }
}

 string yolo() {
    return "yolo";
}