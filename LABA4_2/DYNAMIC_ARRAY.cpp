#include "DYNAMIC_ARRAY.hpp"

DYNAMIC_ARRAY::DYNAMIC_ARRAY() { 
    size = 0;
    capacity = 0;
    objects = nullptr;
}

DYNAMIC_ARRAY::DYNAMIC_ARRAY(DYNAMIC_ARRAY &other) {
    if(this != &other)
    {
        size =  other.size;
        capacity = other.capacity;
        objects = new TECHNIC*[capacity];
        for (int i = 0; i < size; i++)
        {
            objects[i] = other.objects[i];
        }
    }
}

DYNAMIC_ARRAY::DYNAMIC_ARRAY(DYNAMIC_ARRAY &&other) noexcept {
    if (this != &other)
    {
        size =  other.size;
        capacity = other.capacity;
        objects = other.objects;
        other.size = 0;
        other.capacity = 0;
        other.objects = nullptr;
    }
}

DYNAMIC_ARRAY::~DYNAMIC_ARRAY() { 
    size = 0;
    capacity = 0;
    for (int i = 0; i < size; i++)
    {
        delete objects[i];
    }
    delete [] objects;
}

DYNAMIC_ARRAY DYNAMIC_ARRAY::operator=(DYNAMIC_ARRAY &other) { 
    if (this != &other) {
        for (int i = 0; i < size; ++i) {
            delete objects[i];
        }
        delete[] objects;
        size = other.size;
        capacity = other.capacity;
        objects = new TECHNIC* [capacity];
        for (int i = 0; i < size; ++i)
        {
            objects[i] = other.objects[i];
        }
    }
    return *this;
}

DYNAMIC_ARRAY DYNAMIC_ARRAY::operator=(DYNAMIC_ARRAY &&other) noexcept { 
    if (this != &other) {
        for (int i = 0; i < size; ++i) {
            delete objects[i];
        }
        delete[] objects;
        size = other.size;
        capacity = other.capacity;
        objects = new TECHNIC* [capacity];
        for (int i = 0; i < size; ++i)
        {
            objects[i] = other.objects[i];
        }
        other.size = 0;
        other.capacity = 0;
        other.objects = nullptr;
    }
    return *this;
}

void DYNAMIC_ARRAY::print_obj() {
    if (size == 0)
    {
        cout << endl << "//////////////////////////////////" << endl
        << endl << "Array empty" << endl
        << endl << "//////////////////////////////////" << endl;
    }
    for (int i = 0; i < size; ++i)
    {
        cout << typeid(*objects[i]).name() << endl;
        objects[i]->print();
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
   
}

void DYNAMIC_ARRAY::add_object(TECHNIC *object_) { 
    if (size == capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        TECHNIC** new_object = new TECHNIC*[new_capacity];
        std::copy(objects, objects + size, new_object);
        delete[] objects;
        objects = new_object;
        capacity = new_capacity;
    }
    objects[size] = object_;
    size++;
}

void DYNAMIC_ARRAY::remove_object(int index) {
    if (index >= 0 && index < size) {
        cout << "trying to delete object with index " << index << endl;
        for (int j = index; j < size; j++)
        {
            objects[j] = objects[j+1];
        }
        size--;
    }
}

void DYNAMIC_ARRAY::clear_array() { 
    delete [] objects;
    size = 0;
    objects = nullptr;
    capacity = 0;
}









