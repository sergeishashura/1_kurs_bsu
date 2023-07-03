#include "List.hpp"


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>& other)
{
    Node<T>* current = other.head;
    while (current != nullptr)
    {
        push_back(current->data);
        current = current->next;
    }
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept : head(other.head), tail(other.tail), size(other.size)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}


template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>& other)
{
    if (this != &other)
    {
        clear();
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
    
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other)
{
    if (this != &other)
    {
        clear();
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
    
}
