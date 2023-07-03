#pragma once
#include <typeinfo>
#include "TECHNIC.hpp"

class DYNAMIC_ARRAY
{
    int size;
    int capacity;
    TECHNIC** objects;
public:
    DYNAMIC_ARRAY();
    DYNAMIC_ARRAY(DYNAMIC_ARRAY& other);
    DYNAMIC_ARRAY(DYNAMIC_ARRAY&& other) noexcept;
    ~DYNAMIC_ARRAY();
    DYNAMIC_ARRAY operator=(DYNAMIC_ARRAY& other);
    DYNAMIC_ARRAY operator=(DYNAMIC_ARRAY&& other) noexcept;
    
    void print_obj();
    void add_object(TECHNIC* object_);
    void remove_object(int index);
    void clear_array();
};
