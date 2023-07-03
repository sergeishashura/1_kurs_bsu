#include "exponentiation_of_matrix.hpp"
#include <iostream>
using namespace std;

int** Multiply_for_matrix(int** matrix, int** matrix_pow, int size)
{
    int sum;
    int** matrix_result = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix_result[i] = new int[size];
    }
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            sum = 0;
            for (int r = 0; r < size; r++)
            {
                sum += matrix[j][r] * matrix_pow[r][i];
            }
            matrix_result[j][i] = sum;
        }
    }
    return matrix_result;
}

int** MatrixPower_for_matrix(int** matrix, int size, int power)
{
    if (power == 1)
        return matrix;
    if (power % 2 == 1)
        return Multiply_for_matrix(MatrixPower_for_matrix(matrix, size, power - 1), matrix, size);
    else
    {
        matrix = MatrixPower_for_matrix(matrix, size, power / 2);
        return Multiply_for_matrix(matrix, matrix, size);
    }
}

int* Multiply_for_array(int *matrix_from_array, int* matrix_from_array_pow, int size)
{
    int sum;
    int* matrix_from_array_result = new int[size * size];
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            sum = 0;
            for (int r = 0; r < size; r++)
            {
                sum += matrix_from_array[i * size + r] * matrix_from_array_pow[r * size + j];
            }
            matrix_from_array_result[i * size + j] = sum;
        }
    }
    return matrix_from_array_result;
}
int* MatrixPower_for_array(int* matrix_from_array, int size, int power)
{
    if (power == 1)
        return matrix_from_array;
    if (power % 2 == 1)
        return Multiply_for_array(MatrixPower_for_array(matrix_from_array, size, power - 1), matrix_from_array, size);
    else
    {
        matrix_from_array = MatrixPower_for_array(matrix_from_array, size, power / 2);
        return Multiply_for_array(matrix_from_array, matrix_from_array, size);
    }
}
