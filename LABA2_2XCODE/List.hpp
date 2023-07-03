#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LIST
{
public:
    LIST();
    ~LIST();
    void pop_front();
    void push_back(T data);
    void clear();
    int get_size();
    T& operator[](const int index);
    void push_front(T data);
    void insert(T data, int index);
    void remove_at(int index);
    void pop_back();

private:

    template<typename t>
    class Node
    {
    public:
        Node * pNext;
        t data;

        Node(t data = t(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};
