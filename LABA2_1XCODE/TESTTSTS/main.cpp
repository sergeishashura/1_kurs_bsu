#include "vector.hpp"
#include "vector.cpp"
#include <algorithm>
#include <set>

enum CHOOSE_FILLING_METHOD
{
    FILL_WITH_RANDOM_NUM = 1,
    ENTER_BY_USER
};


template<typename T>
void fill_vector_rand(Vector<T>& vector, int n)
{
    int element;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        element = rand() % 10;
        vector.pushback(element);
    }
}

template<typename T>
void fill_vector_myself(Vector<T>& vector, int n)
{
    int element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        vector.pushback(element);
    }
}

template<typename T>
void check_and_output(Vector<T>& vector, int n)
{
    Vector<int> result;
    Vector<int> counter_element;
    cout << vector << "\n";
    sort(vector.begin(), vector.end());
    reverse(vector.begin(), vector.end());
    set<int> set(vector.begin(), vector.end());
    for(auto el : set) result.pushback(el);
    reverse(result.begin(), result.end());
    cout << result << "\n";
    

}

int main()
{
    int n, path_num;
    Vector<int> vector;
    cout << "Enter the array size - ";
    cin >> n;
    cout << "Enter the method:\n1 - Random numbers;\n2 - Enter yourself.\n";
    cin >> path_num;
    switch (path_num)
    {
        case FILL_WITH_RANDOM_NUM:
            fill_vector_rand(vector, n);
            break;
        case ENTER_BY_USER:
            fill_vector_myself(vector, n);
            break;
        default:
            cout << "Enter the correct option!\n";
            main();
            break;
    }
    check_and_output(vector, n);
    return 0;
}
