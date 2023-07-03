#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
void fill_array(int *array, int size);
int& find_num_occurs_most_often(int *array, int size);
void output_num_occurs_most_often(int *array, int size);
void output_array(int *array, int size);
int main()
{
    int size, k;
    srand(time(NULL));
    cout << "Enter k = ";
    cin >> k;
    cout << "Enter size of array: ";
    cin >> size;
    int *array = new int[size];
    fill_array(array, size);
    cout << "the original array: " << endl;
    output_array(array, size);
    find_num_occurs_most_often(array, size) = k;
    cout << endl << "the final array: " << endl;
    output_array(array, size);
    cout << endl;
    delete [] array;
    return 0;
}
void fill_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 1 + rand() % 10;
    }
}
void output_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i];
    }
}
int& find_num_occurs_most_often(int *array, int size)
{
    int count = 0;
    int maxcount = 0;
    int mx = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
            if (array[i] == array[j])
            {
                count++;
            }
        if (((maxcount == count) && (mx > array[i])) || (maxcount < count))
        {
            maxcount = count;
            mx = array[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (mx == array[i])
        {
            cout << endl << "index = " << i << " The number that occurs most often in the array: " << array[i];
            return array[i];
        }
    }
    return array[0];
}


