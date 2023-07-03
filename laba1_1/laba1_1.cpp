#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;
int **allocate_memory_for_matrix(int size);
void free_memory(int **matrix, int size);
void fill_the_matrix(int **matrix, int size);
void matrix_output(int **matrix, int size);
int main()
{
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;
    cout << "Matrix:" << endl;
    int **matrix = allocate_memory_for_matrix(size);
    fill_the_matrix(matrix, size);
    matrix_output(matrix, size);
    free_memory(matrix, size);
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
void free_memory(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void fill_the_matrix(int **matrix, int size)
{
    int element = size * size;
    matrix[size / 2][size / 2] = 1;
    for (int num_rings = 1; num_rings <= size / 2; num_rings++)
    {
        for (int j = size - num_rings; j >= num_rings; j--)
        {
            matrix[j][num_rings - 1] = element--;
        }
        for (int j = num_rings - 1; j < size - num_rings + 1; j++)
        {
            matrix[num_rings - 1][j] = element--;
        }
        for (int j = num_rings; j < size - num_rings + 1; j++)
        {
            matrix[j][size - num_rings] = element--;
        }
        for (int j = size - num_rings - 1; j >= num_rings; j--)
        {
            matrix[size - num_rings][j] = element--;
        }
    }
}
void matrix_output(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(5) << matrix[i][j];
        cout << endl;
    }
}