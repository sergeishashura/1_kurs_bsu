#pragma once
#include "PERIPHERAL.hpp"

class SCREEN : public PERIPHERAL
{
public:
    string permission;
    unsigned int diagonal;
    unsigned int screen_frequency;
    SCREEN();
    SCREEN(string year_release_, unsigned int diagonal_, string permission_, unsigned int screen_frequency_);
    SCREEN(SCREEN& other);
    SCREEN(SCREEN&& other) noexcept;
    virtual ~SCREEN() override;
    SCREEN operator=(SCREEN& other);
    SCREEN operator=(SCREEN&& other) noexcept;
    virtual void print() override;
    
    void set_permission(string permission_);
    void get_permission();
    void set_diagonal(unsigned int diagonal_);
    void get_diagonal();
    void set_screen_frequency(unsigned int screen_frequency_);
    void get_screen_frequency();
    
    
};

