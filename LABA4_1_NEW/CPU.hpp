#pragma once
#include "INTERNAL_DEVICE.hpp"

class CPU : public INTERNAL_DEVICE
{
public:
    string model;
    unsigned int num_cores;
    unsigned int frequency;
    CPU();
    CPU(string year_release_, string fabricator_, string model_, unsigned int num_cores_, unsigned int frequency_);
    CPU(CPU& other);
    CPU(CPU&& other) noexcept;
    virtual ~CPU();
    CPU operator=(CPU& other);
    CPU operator=(CPU&& other) noexcept;
    virtual void print() override;
    
    void set_model(string model_);
    void get_model();
    void set_num_cores( unsigned int num_cores_);
    void get_num_cores();
    void set_frequency(unsigned int frequency_);
    void get_frequency();
    
};


