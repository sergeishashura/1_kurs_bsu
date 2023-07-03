#pragma once
#include "INTERNAL_DEVICE.hpp"

class MEMORY : public INTERNAL_DEVICE
{
public:
    unsigned int capacity_memory;
    
    MEMORY();
    MEMORY(string year_release_, unsigned int capacity_memory_, string fabricator_);
    MEMORY(MEMORY &other);
    MEMORY(MEMORY &&other) noexcept;
    virtual ~MEMORY();
    MEMORY operator=(MEMORY &other);
    MEMORY operator=(MEMORY &&other) noexcept;
    virtual void print() override;
    
    void set_capacity(unsigned int capacity_memory_);
    void get_capacity();
    
};


