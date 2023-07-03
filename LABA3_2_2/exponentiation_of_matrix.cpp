#include "exponentiation_of_matrix.hpp"

#include <iostream>

vector<vector<int>> multiply_for_matrix(vector<vector<int>>& matrix, vector<vector<int>>& matrix_pow, int size)
{
    int sum;
    vector<vector<int>> matrix_result(size, vector <int>(size));
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

vector<vector<int>> matrixpower_for_matrix(vector<vector<int>>& matrix, int size, int power)
{
    if (power == 1)
    {
        return matrix;
    }
    if (power % 2 == 1)
    {
        vector<vector<int>> gap(size, vector<int>(size));
        gap = matrixpower_for_matrix(matrix, size, power - 1);
        return multiply_for_matrix(gap, matrix, size);
    }
    else
    {
        matrix = matrixpower_for_matrix(matrix, size, power / 2);
        return multiply_for_matrix(matrix, matrix, size);
    }
}

vector<int> multiply_for_array(vector<int>& matrix_from_array, vector<int>& matrix_from_array_pow, int size)
{
    int sum;
    vector<int> matrix_from_array_result(size*size);
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
vector<int> matrixpower_for_array(vector<int>& matrix_from_array, int size, int power)
{
    if (power == 1)
    {
        return matrix_from_array;
    }
    if (power % 2 == 1)
    {
        vector<int> gap = matrixpower_for_array(matrix_from_array, size, power - 1);
        return multiply_for_array(gap, matrix_from_array, size);
    }
    else
    {
        matrix_from_array = matrixpower_for_array(matrix_from_array, size, power / 2);
        return multiply_for_array(matrix_from_array, matrix_from_array, size);
    }
}
