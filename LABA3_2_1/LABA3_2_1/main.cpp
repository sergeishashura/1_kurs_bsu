//убрать все повторы в векторе и вывести поубыванию используя vector
#include <iostream>
#include <vector>
#include "vector_filling_paths.hpp"
#include "output_vector.hpp"
using namespace std;
enum CHOOSE_FILLING_METHOD
{
    FILL_WITH_RANDOM_NUM = 1,
    ENTER_BY_USER
};
int main()
{
    int n, num_way;
    cout << "Enter the vector size - ";
    cin >> n;
    vector<int> numbers;
    cout << "Enter the method:\n1 - Random numbers;\n2 - Enter yourself.\n";
    cin >> num_way;
    switch (num_way)
    {
        case FILL_WITH_RANDOM_NUM:
            fill_vector_rand(numbers, n);
            break;
        case ENTER_BY_USER:
            fill_vector_myself(numbers, n);
            break;
        default:
            cout << "Enter the correct option!\n";
            main();
            break;
    }
    check_and_output(numbers);
    return 0;
}
