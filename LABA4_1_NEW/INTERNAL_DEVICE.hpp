#pragma once
#include "PERIPHERAL.hpp"
class INTERNAL_DEVICE : public PERIPHERAL
{
public:
    string fabricator;
    INTERNAL_DEVICE();
    INTERNAL_DEVICE(string year_release_, string fabricator_);
    INTERNAL_DEVICE(INTERNAL_DEVICE &other);
    INTERNAL_DEVICE(INTERNAL_DEVICE &&other) noexcept;
    virtual ~INTERNAL_DEVICE();
    INTERNAL_DEVICE operator=(INTERNAL_DEVICE &other);
    INTERNAL_DEVICE operator=(INTERNAL_DEVICE &&other) noexcept;

    virtual void print() override;
    void set_fabricator(string fabricator_);
    void get_fabricator();
    
};


