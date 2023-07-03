#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

int **allocate_memory_for_matrix(int size);
void free_memory(int **matrix, int size);
void fill_the_matrix(int **matrix, int size);
void matrix_output(int **matrix, int size);

int main()
{
    int size = 0;
    cin >> size;
    int **matrix = allocate_memory_for_matrix(size);
    fill_the_matrix(matrix, size);
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
    int i = pow(size, 2), j, k;
    for (k = 1; k <= size / 2; k++)
    {
        matrix[size / 2][size / 2] = 1;
        for (j = size - k; j >= k; j--)
        {
            matrix[j][k - 1] = i--;
        }
        for (j = k - 1; j < size - k + 1; j++)
        {
            matrix[k - 1][j] = i--;
        }
        for (j = k; j < size - k + 1; j++)
        {            matrix[j][size - k] = i--;}
        for (j = size - k - 1; j >= k; --j)
        {
            matrix[size - k][j] = i--;
        }
    }
}

void output(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
        
    }
}