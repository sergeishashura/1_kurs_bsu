#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template<class T>
class Vector{
    private:
    T *array;
    int size = 0;
    int capacity;
    
    void add_memory()
    {
        capacity *= 2;
        T *tmp = array;
        array = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            array[i] = tmp[i];
        }
        delete [] tmp;
    }

    public:
    Vector();
    Vector(Vector& other);
    Vector(Vector&& other);
    Vector& operator=(Vector& other);
    Vector& operator=(Vector&& other);
    ~Vector();

    public:
    int get_size() const;
    int get_capacity() const;
    void pushback(const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;
    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;
};
