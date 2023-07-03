#pragma once
#include "TECHNIC.hpp"

class PERIPHERAL : public TECHNIC
{
public:
    PERIPHERAL();
    PERIPHERAL(string year_release_);
    PERIPHERAL(PERIPHERAL& other);
    PERIPHERAL(PERIPHERAL&& other) noexcept;
    virtual ~PERIPHERAL();
    PERIPHERAL operator=(PERIPHERAL& other);
    PERIPHERAL operator=(PERIPHERAL&& other) noexcept;
    virtual void print() override;    
};


