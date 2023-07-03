#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
void fill_array(int *array, int size);
int& find_num_occurs_most_often(int *array, int size);
void output_num_occurs_most_often(int *array, int size, int index);
void output_array(int *array, int size);
int main()
{
    int size, index, k;
    srand(time(NULL));
    cout << "Enter k = ";
    // cin >> k;
    k = 5;
    size = 7;
    cout << "Enter size of array: ";
    // cin >> size;
    int *array = new int[size];
    fill_array(array, size);
    cout << "the original array: " << endl;
    output_array(array, size);
    find_num_occurs_most_often(array, size);
    output_num_occurs_most_often(array, size, index);
    find_num_occurs_most_often(array, size) = k;
    cout << endl << "the final array: " << endl;
    output_array(array, size);
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
    int index;
    int current_frequent_el = array[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        if (maxcount < count)
        {
            maxcount = count;
            index = i - 1;
            current_frequent_el = array[i];
        }
        if (array[i] < array[index])
        {
            i = index;
        }
        count = 0;
    }
    return array[index];
}
void output_num_occurs_most_often(int *array, int size, int index)
{
    cout << endl << "The number that occurs most often in the array: " << array[index];
}
