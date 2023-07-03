#include"Header.h"

int main()
{
    unsigned int n;
    cout << "Enter n:";
    cin >> n;
    DoublyLinkedList<double> list;
    fill_list(list, n);
    list.print();
    cout << endl<< "min(max(a1,a2n),max(a2,a2n−1),..., max(an,an+1))= " << find_min_max_element(list, n) << endl;
    return 0;
}
