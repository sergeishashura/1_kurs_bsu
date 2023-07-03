#pragma once
#include "MEMORY.hpp"

class SSD : public MEMORY
{
public:
    unsigned int TBW;
    unsigned int num_bytes;
    
    SSD();
    SSD(string year_release_, unsigned int capacity_memory_, string fabricator_, unsigned int TBW_, unsigned int num_bytes_);
    SSD(SSD& other);
    SSD(SSD&& other) noexcept;
    virtual ~SSD();
    SSD operator=(SSD& other);
    SSD operator=(SSD&& other);
    virtual void print() override;
    
    void set_TBW(unsigned int TBW_);
    void get_TBW();
    void set_num_bytes(unsigned int num_bytes_);
    void get_num_bytes();
    
    
    
};


