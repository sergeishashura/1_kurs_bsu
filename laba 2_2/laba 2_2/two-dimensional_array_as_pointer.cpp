#include "two-dimensional_array_as_pointer.hpp"
#include "exponentiation_of_matrix.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
int **allocate_memory_for_matrix(int size);
void matrix_output(int **matrix, int size);
void free_memory(int **matrix, int size);
void fill_the_matrix(int **matrix, int size);
int twodimensional_array_as_pointer(int size, int power)
{
    int** matrix = allocate_memory_for_matrix(size);
    fill_the_matrix(matrix, size);
    cout << "first matrix:" << endl;
    matrix_output(matrix, size);
    matrix = MatrixPower_for_matrix(matrix, size, power);
    cout << "exponentiation matrix:" << endl;
    matrix_output(matrix, size);
    free_memory(matrix, size);
    return 0;
}
int **allocate_memory_for_matrix(int size)
{
    int **matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    return matrix;
}
void fill_the_matrix(int **matrix, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 9;
        }
    }
}
void free_memory(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void matrix_output(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(10) << matrix[i][j];
        cout << endl;
    }
}
