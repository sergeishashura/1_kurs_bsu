#include "List.hpp"
#include "List.cpp"
int main()
{
    setlocale(LC_ALL, "ru");
    LIST<int> lst;
    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    for (int i = 0; i < lst.get_size(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "pop_back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.get_size(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}

