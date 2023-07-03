#include "two-dimensional_vector_as_pointer.hpp"
#include "exponentiation_of_matrix.hpp"

void matrix_output(vector<vector<int>>&, int size);
void fill_the_matrix(vector<vector<int>>&, int size);

int twodimensional_vector_as_pointer(int size, int power)
{
    vector<vector <int>> matrix(size, vector <int>(size));
    fill_the_matrix(matrix, size);
    cout << "first matrix:" << endl;
    matrix_output(matrix, size);
    matrix = matrixpower_for_matrix(matrix, size, power);
    cout << "exponentiation matrix:" << endl;
    matrix_output(matrix, size);
    return 0;
}

void fill_the_matrix(vector<vector<int>>& matrix, int size)
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

void matrix_output(vector<vector<int>>& matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(10) << matrix[i][j];
        cout << endl;
    }
}
