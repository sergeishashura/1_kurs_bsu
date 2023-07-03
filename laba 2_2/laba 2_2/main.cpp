#include <iostream>
#include "two-dimensional_array_as_pointer.hpp"
#include "two-dimensional_array_as_one-dimensional.hpp"
using namespace std;
enum MEMORY_ALLOCATION_METHOD
{
    TWODIMENSIONAL_ARRAY_AS_ONEDIMENSIONAL = 1,
    TWODIMENSIONAL_AS_POINTER
};
int main()
{
    int size, num_way, power;
    cout << "Enter size of matrix- ";
    cin >> size;
    cout << "Enter power- ";
    cin >> power;
    cout << "Enter the method:\n1 - Describing a two-dimensional array as one-dimensional;\n2 - Describing a two-dimensional array as a pointer to an array of pointers;\n";
    cin >> num_way;
    switch (num_way) {
        case TWODIMENSIONAL_ARRAY_AS_ONEDIMENSIONAL:
            twodimensional_array_as_onedimensional(size, power);
            break;
        case TWODIMENSIONAL_AS_POINTER:
            twodimensional_array_as_pointer(size, power);
            break;
        default:
            cout << "incorrect data entered";
            main();
            break;
    }
    return 0;
}
