#include "vector.hpp"

template<class T>
Vector<T>::Vector()
{
    array = new T[1];
    capacity = 1;
}

template<class T>
Vector<T>::Vector(Vector<T> &other)
{
    if (this != &other)
    {
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = other.capacity = 0;
    }
}

template<class T>
Vector<T>::Vector(Vector<T> &&other)
{
    if (this != &other)
    {
        delete [] array;
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = other.capacity = 0;
    }
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector<T> &other)
{
    if (this != &other)
    {
        delete [] array;
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = other.capacity = 0;
    }
    return *this;
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other)
{
    if (this != &other)
    {
        delete [] array;
        array = other.array;
        size = other.size;
        capacity = other.capacity;
        other.array = nullptr;
        other.size = other.capacity = 0;
    }
    return *this;
}

template<class T>
Vector<T>::~Vector()
{
    delete [] array;
}

template<class T>
int Vector<T>::get_size() const
{
    return size;
}

template<class T>
int Vector<T>::get_capacity() const
{
    return capacity;
}

template<class T>
void Vector<T>::pushback(const T& value)
{
    if (size >= capacity)
    {
        add_memory();
    }
    array[size++] = value;
}

template<class T>
T& Vector<T>::operator[](int index)
{
    return array[index];
}

template<class T>
const T &Vector<T>::operator[](int index) const
{
    return array[index];
}

template<typename T>
inline ostream& operator << (ostream& filling, const Vector<T>& vector)//оператор потокого вывода
{
    for (int i = 0; i < vector.get_size(); i++)
    {
        filling << vector[i] << " ";
    }
    return filling;
}

template<class T>
inline T *Vector<T>::begin()
{
    return &array[0];
}

template<class T>
inline const T *Vector<T>::begin() const
{
    return &array[0];
}

template<class T>
inline T *Vector<T>::end()
{
    return &array[size];

}

template<class T>
inline const T *Vector<T>::end() const
{
    return &array[size];
}
