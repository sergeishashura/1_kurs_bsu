#include "List.hpp"

template<typename T>
LIST<T>::LIST()
{
    Size = 0;
    head = nullptr;
}


template<typename T>
LIST<T>::~LIST()
{
    clear();
}


template<typename T>
void LIST<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;

}

template<typename T>
void LIST<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void LIST<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template <typename T>
int LIST<T>::get_size()
{
    return Size;
}


template<typename T>
T& LIST<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    
    assert(index < Size);
    
    while (current != nullptr)
    {
        if (counter == index)
        {
            break;
        }
        current = current->pNext;
        counter++;
    }
    return current->data;
}

template<typename T>
void LIST<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void LIST<T>::insert(T data, int index)
{

    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T> *newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template<typename T>
void LIST<T>::remove_at(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }

}

template<typename T>
void LIST<T>::pop_back()
{
    remove_at(Size - 1);
}


