#include "Header.h"

const int RANDOM_TOP_BORDER = 1000;
const float RANDOM_FLOATING_FACTOR = 0.01;

void fill_list(DoublyLinkedList<double> &list, unsigned int n)
{
    srand(time(NULL));
    double element;
    for(int i = 0; i < 2 * n; i++)
    {
        element = rand() % RANDOM_TOP_BORDER * RANDOM_FLOATING_FACTOR;
        list.push_back(element);
    }
}

double find_min_max_element(DoublyLinkedList<double> &list, unsigned int n)
{
    double min_max_el = max(list.front(),list.back());
    for (int i = 0; i < n; i++)
    {
        double max_el = max(list.front(),list.back());
        if (max_el < min_max_el)
        {
            min_max_el = max_el;
        }
        list.pop_back();
        list.pop_front();
    }
    return min_max_el;
}
