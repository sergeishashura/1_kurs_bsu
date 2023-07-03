#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    Node *next;
    Node *prev;// указатель хранящий адрес на следующуюячейку списка
    int element;           // указатель хранящий значение
};

struct list
{
  Node* first;
  Node* last;
  int count;

};
void find_element(Node*, Node*&, Node*);
void fill_rand_el(Node*&, int);
void output_list(Node*);
void push_back(Node*&, int);
void delete_el(Node*&, Node*&, Node*&);
void insert_list(Node*&, Node*&, Node*&, Node*&, Node*&, int);

int main()
{
    list* L = new list;
    list* L_1 = new list;
    list* L_2 = new list;
    L->first = nullptr; L->last = nullptr;
    L_1->first = nullptr; L_1->last = nullptr;
    L_2->first = nullptr; L_2->last = nullptr;
    int size_L, size_L1, size_L2;
    cout << "Enter size of L\n";
    cin >> size_L;
    fill_rand_el(L->first, size_L);
    output_list(L->first);
    cout << "Enter size of L1\n";
    cin >> size_L1;
    fill_rand_el(L_1->first, size_L1);
    output_list(L_1->first);
    cout << "Enter size of L2\n";
    cin >> size_L2;
    fill_rand_el(L_2->first, size_L2);
    output_list(L_2->first);
    cout << "modified list L\n";
    insert_list(L->first, L->last, L_1->first, L_2->first, L_2->last, size_L2);
    output_list(L->first);
    return 0;
}
void push_back(Node*& first, int element)
{
    Node* new_node = new Node;
    new_node->element = element;
    new_node->next = nullptr;
    if (first == nullptr)
    {
        first = new_node;
    }
    else
    {
        Node* current_node = first;
        while (current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}
void output_list(Node* first)
{
    Node* current_node = first;
    while (current_node != nullptr)
    {
      cout << setw(5) << current_node->element;
      current_node = current_node->next;
    }
    cout << endl;
}
void fill_rand_el(Node*& first, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        int element = 1 + rand() % 10;
        push_back(first, element);
    }
}
void delete_el(Node*& first, Node*& last, Node*& element_list)
{
    Node *curr, *find_elem;
    find_element(first, find_elem, element_list);     // поиск по ключу
    curr = find_elem->next;
        if (!curr)                 // если не нашли
            return;              // то нечего тут больше делать
        // нашли - удаляем элемент из середины или конца списка
        find_elem->next = curr->next;
        if (curr->next)
            curr->next->prev = find_elem;
}
void find_element(Node* first, Node*& find_el, Node* element_list)
{
    Node *current = first;
    find_el = first;
             // поиск элемента c ключом = key
    while (current && current->element != element_list->element )
    {
        find_el = current;  // запоминаем адрес предыдущего элемента
        current = current->next;
    }
}
void insert_list(Node*& first_L, Node*& last_L, Node*& first_L_1, Node*& first_L_2, Node*& last_L_2, int size_L2)
{
    Node *current = first_L;
    
    while (current != NULL)
    {
        if (current == first_L_1)
        {
            delete_el(first_L, last_L, first_L_1);
            for (int i = 0; i < size_L2; i++)
            {
                push_back(current, size_L2);
                current->next = first_L_2->next;
            }
        }
        current = current->next;
    }
    
}
