#include "vector_filling_paths.hpp"
#include <iostream>
int element;
void fill_vector_rand(vector<int>& numbers, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        element = rand() % n;
        numbers.push_back(element);
    }
    copy(numbers.begin(), numbers.end(), ostream_iterator<int> (std::cout, " "));
    cout << endl;
}

void fill_vector_myself(vector<int>& numbers, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        numbers.push_back(element);
    }
    copy(numbers.begin(), numbers.end(), ostream_iterator<int> (std::cout, " "));
    cout << endl;
}


