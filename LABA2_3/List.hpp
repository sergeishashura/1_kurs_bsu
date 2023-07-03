#include<iostream>

using namespace std;

template<typename T>
class Node
{
public:
    T data;
    int size;
    Node<T>* prev;
    Node<T>* next;
public:
    Node(T data)
    {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

template<typename T>
class DoublyLinkedList
{
    
public:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }
    DoublyLinkedList(int value)
    {
        head->data = value;
    }
    ~DoublyLinkedList()
    {
        clear();
    }
    DoublyLinkedList(DoublyLinkedList& other);
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList& operator=(DoublyLinkedList& other);
    DoublyLinkedList& operator=(DoublyLinkedList&& other);
    Node<T>* push_front(T data)
    {
        Node<T>* tmp = new Node(data);
        tmp->next = head;
        if (head != nullptr)
        {
            head->prev = tmp;
        }
        if (tail == nullptr)
        {
            tail = tmp;
        }
        head = tmp;
        size++;
        return tmp;
    }
    Node<T>* push_back(T data)
    {
        Node<T>* tmp = new Node(data);
        tmp->prev = tail;
        if (tail != nullptr)
        {
            tail->next = tmp;
        }
        if (head == nullptr)
        {
            head = tmp;
        }
        tail = tmp;
        size++;
        return tmp;
    }
    Node<T>* get_at(int index)
    {
        Node<T>* tmp = head;
        int i = 0;
        while (i != index)
        {
            if (tmp == nullptr)
            {
                return tmp;
            }
            tmp = tmp->next;
            i++;
        }
        return tmp;
    }
    Node<T>* operator[](int index) { return get_at(index); }
    void pop_front()
    {
        if (head == nullptr) return;
        
        Node<T>* tmp = head->next;
        if (tmp != nullptr)
        {
            tmp->prev = nullptr;
        }
        else
        {
            tail = tmp;
        }
        delete head;
        head = tmp;
    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            return;
        }
        
        Node<T>* tmp = tail->prev;
        if (tmp != nullptr)
        {
            tmp->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete tail;
        tail = tmp;
    }
    void erase(int index)
    {
        if (index == 0)
        {
            pop_front();
        }
        else
        {
            Node<T>* current = this->head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            
            if (current == this->head)
            {
                this->head = current->next;
            }
            else
            {
                current->prev->next = current->next;
            }
            
            if (current == this->tail)
            {
                this->tail = current->prev;
            }
            else
            {
                current->next->prev = current->prev;
            }
            
            delete current;
            this->size--;
        }
    }
    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
    void print() const
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
    T& front() const {return head->data;}
    T& back() const {return tail->data;}
};

