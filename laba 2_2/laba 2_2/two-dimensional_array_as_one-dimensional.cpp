#include "two-dimensional_array_as_one-dimensional.hpp"
#include "exponentiation_of_matrix.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int Dimension(int i, int j, int size);
int *allocate_memory_for_array(int lines, int columns);
void fill_array(int* matrix_from_array, int lines, int columns, int size);
void output_array(int* matrix_from_array, int lines, int columns);
void free_memory_array(int* matrix_from_array, int rows, int cols);

int twodimensional_array_as_onedimensional(int size, int power)
{
    int columns = size, lines = size;
    int* matrix_from_array = allocate_memory_for_array(lines, columns);
    fill_array(matrix_from_array, lines, columns, size);
    cout << "first matrix:" << endl;
    output_array(matrix_from_array, lines, columns);
    cout << "exponentiation matrix:" << endl;
    matrix_from_array = MatrixPower_for_array(matrix_from_array, size, power);
    output_array(matrix_from_array, lines, columns);
    free_memory_array(matrix_from_array, lines, columns);
    return 0;
}

int* allocate_memory_for_array(int lines, int columns)
{
    int* matrix_from_array = new int[lines * columns];
    return matrix_from_array;
}

int Dimension(int i, int j, int size)
{
    return (i * size + j);
}

void fill_array(int* matrix_from_array, int lines, int columns, int size)
{
    srand(time(NULL));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix_from_array[Dimension(i, j, size)] = rand() % 10;
        }
    }
}

void output_array(int* matrix_from_array, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(10) << matrix_from_array[Dimension(i, j, columns)] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void free_memory_array(int* matrix, int rows, int cols)
{
    delete[] matrix;
}
