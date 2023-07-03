#include <iostream>
#include <clocale>
#include <time.h>
#include <iomanip>
using namespace std;

struct Node
{
    double x;
    Node* next;
    Node* prev;
};
struct list
{
    Node* first;
    Node* last;
    int count;

};

void push_back(list* &L, double x);
void fill_list(list* &L, const unsigned int n);
double find_min_max(list* L, unsigned int n);
void output_list(Node* first);

void push_back(list* &L, double x)
{
    Node* new_node = new Node;
    new_node->x = x;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    if (L->first == nullptr)
    {
        L->first = new_node;
        L->last = new_node;
    }
    else
    {
        Node* current_node = L->first;
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->prev = current_node;
        L->last = new_node;
    }
    L->count++;
}

void fill_list(list* &L, const unsigned int n)
{
    srand(time(NULL));
    for (int i = 0; i < 2 * n; ++i)
    {
        double x = rand() % 100 * 0.1;
        push_back(L, x);
    }
}
void out(Node* first)
{
    Node* current_node = first;
    while (current_node != nullptr)
    {
        cout << setw(5) << current_node->x;
        current_node = current_node->next;
    }
    cout << endl;
}

double find_min_max(list* L, unsigned int n)
{
    double max = 0.0;
    Node* left = L->first;
    Node* right = L->last;
    double* array = new double[n];
    int i = 0;
    while (left -> next != right)
    {
        if (left->x > right->x)
        {
            max = left->x;
        }
        else if (left->x < right->x)
        {
            max = right->x;
        }
        left = left->next;
        right = right->prev;
        array[i] = max;
        //cout << array[i] << endl;
        i++;
    }
    if (left->x > right->x)
    {
        max = left->x;
        array[i] = max;
    }
    else if (left->x < right->x)
    {
        max = right->x;
        array[i] = max;
    }
    //cout << array[i] << endl;
    double min = 0.0;
    min = array[0];
    for (int j = 0; j < i; j++)
    {
        if (array[j] < min)
        {
            min = array[j];
            //cout << min;
        }
    }
    delete [] array;
    return min;
}

int main()
{

    list* L = new list;
    L->first = nullptr; L->last = nullptr; L->count = 0;

    cout << "Enter n:";
    unsigned int n;
    cin >> n;
    cout << endl;

    fill_list(L, n);
    
    out(L->first);

    cout << "min(max(a1,a2n),max(a2,a2n−1),..., max(an,an+1))= " <<find_min_max(L, n) << endl;

    return 0;
}

