#include "output_vector.hpp"
#include <iostream>
#include <algorithm>

void remove(vector<int>& numbers)
{
    auto end = numbers.end();
    for (auto it = numbers.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
 
    numbers.erase(end, numbers.end());
}

void sort_vector(vector<int>& vector)
{
    remove(vector);
    sort(vector.begin(), vector.end());
    reverse(vector.begin(),vector.end());
}

void check_and_output(vector<int>& numbers)
{
    sort_vector(numbers);
    copy(numbers.begin(), numbers.end(), ostream_iterator<int> (std::cout, " "));
}
