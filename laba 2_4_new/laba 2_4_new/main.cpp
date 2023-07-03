#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <list>

using namespace std;

void filling_list(list<int>&, int);
void output_list(list<int>&);
void replace_list(list<int>&, list<int>&, list<int>&);

int main()
{
    list<int> L;
    list<int> L1;
    list<int> L2;
    int size, size_1, size_2;
    cout << "Enter size of L\n";
    cin >> size;
    filling_list(L, size);
    output_list(L);
    cout << "Enter size of L1\n";
    cin >> size_1;
    filling_list(L1, size_1);
    output_list(L1);
    cout << "Enter size of L2\n";
    cin >> size_2;
    filling_list(L2, size_2);
    output_list(L2);
    cout << "modified list L\n";
    replace_list(L, L1, L2);
    output_list(L);
    return 0;
}

void filling_list(list<int>& list, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int element = 1 + rand() % 10;
        list.push_back(element);
    }
}

void output_list(list<int>& list)
{
    for (auto element = list.begin(); element != list.end(); element++)
            cout << *element << " ";
        cout << "\n";
}

void replace_list(list<int>& L, list<int>& L1, list<int>& L2)
{
    auto last_entry_L1 = L.end(); // last occurrence of the list L1
    
    // find L1
    for (auto it = L.begin(); it != L.end(); ++it)
    {
        if (equal(L1.begin(), L1.end(), it))
        {
            last_entry_L1 = it;
        }
    }

    if (last_entry_L1 != L.end())// If the list L1 is found, replace it with the list L2
    {
         // erase delete element iterator
        L.insert(last_entry_L1, L2.begin(), L2.end());
        L.erase(last_entry_L1, next(last_entry_L1, L1.size()));
    }
    else
        cout << "L1 not found...\n" << "List L:\n";
}
