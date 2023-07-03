
#pragma once
#include "MEMORY.hpp"

class HDD : public MEMORY
{
public:
    HDD();
    HDD(string year_release_, unsigned int capacity_memory_, string fabricator_);
    HDD(HDD &other);
    HDD(HDD &&other) noexcept;
    virtual ~HDD();
    HDD operator=(HDD &other);
    HDD operator=(HDD &&other) noexcept;
    virtual void print() override;
};


