#include "two-dimensional_vector_as_one-dimensional.hpp"
#include "exponentiation_of_matrix.hpp"

int recalc_arr_index(int i, int j, int size);
void fill_array(vector<int>& matrix_from_array, int lines, int columns, int size);
void output_array(vector<int>& matrix_from_array, int lines, int columns);

int twodimensional_vector_as_onedimensional(int size, int power)
{
    int columns = size, lines = size;
    vector<int> matrix_from_array(size*size);
    fill_array(matrix_from_array, lines, columns, size);
    cout << "first matrix:" << endl;
    output_array(matrix_from_array, lines, columns);
    cout << "exponentiation matrix:" << endl;
    matrix_from_array = matrixpower_for_array(matrix_from_array, size, power);
    output_array(matrix_from_array, lines, columns);
    return 0;
}

int recalc_arr_index(int i, int j, int size)
{
    return (i * size + j);
}

void fill_array(vector<int>& matrix_from_array, int lines, int columns, int size)
{
    srand(time(NULL));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix_from_array[recalc_arr_index(i, j, size)] = rand() % 10;
        }
    }
}

void output_array(vector<int>& matrix_from_array, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(10) << matrix_from_array[recalc_arr_index(i, j, columns)] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
