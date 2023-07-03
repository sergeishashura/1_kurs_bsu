#include <iostream>
#include "array_filling_paths.hpp"
#include "output_array.hpp"
using namespace std;
enum CHOOSE_FILLING_METHOD
{
    FILL_WITH_RANDOM_NUM = 1,
    ENTER_BY_USER
};
int main()
{
    int n, num_way;
    cout << "Enter the array size - ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    cout << "Enter the method:\n1 - Random numbers;\n2 - Enter yourself.\n";
    cin >> num_way;
    switch (num_way)
    {
        case FILL_WITH_RANDOM_NUM:
            fill_array_rand(arr, n);
            break;
        case ENTER_BY_USER:
            fill_array_myself(arr, n);
            break;
        default:
            cout << "Enter the correct option!\n";
            main();
            break;
    }
    check_and_output(arr, n);
    delete[] arr;
    return 0;
}
