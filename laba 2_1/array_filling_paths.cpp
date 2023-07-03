#include "array_filling_paths.hpp"
#include <iostream>
using namespace std;
int fill_array_rand(int* arr, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        cout << j << " ";
        arr[j]++;
    }
    return *arr;
}

int fill_array_myself(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        cin >> j;
        arr[j]++;
    }
    return *arr;
}

