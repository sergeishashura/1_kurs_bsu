//find min(max(a1,a2n),max(a2,a2n−1),..., max(an,an+1))
#include <iostream>
#include <list>
#include <time.h>
using namespace std;

const int RANDOM_TOP_BORDER = 100;
const float RANDOM_FLOATING_FACTOR = 0.1;

void fill_list(list<double> &, unsigned int);
void print_list(list<double> &);
double find_min_max_element(list<double> &, unsigned int);



int main()
{
    unsigned int n;
    cout << "Enter n:";
    cin >> n;
    list<double> list;
    fill_list(list, n);
    print_list(list);
    cout << endl<< "min(max(a1,a2n),max(a2,a2n−1),..., max(an,an+1))= " << find_min_max_element(list, n) << endl;
    return 0;
}

void fill_list(list<double> &list, unsigned int n)
{
    srand(time(NULL));
    double element;
    for(int i = 0; i < 2 * n; i++)
    {
        
        element = rand() % RANDOM_TOP_BORDER * RANDOM_FLOATING_FACTOR;
        list.push_back(element);
    }
}

void print_list(list<double> &list)
{
    for(double element : list)
    {
        cout << element << "\t";
    }
}

double find_min_max_element(list<double> &list, unsigned int n)
{
    double min_max_el = max(list.front(),list.back());
    double max_el;
    for (int i = 1; i < n; i++)
    {
        max_el = max(list.front(),list.back());
        if (max_el < min_max_el)
        {
            min_max_el = max_el;
        }
        list.pop_back();
        list.pop_front();
    }
    return min_max_el;
}
