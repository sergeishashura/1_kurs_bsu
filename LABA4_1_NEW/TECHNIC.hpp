#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class TECHNIC
{
public:
    string year_release;
    TECHNIC();
    TECHNIC(string year_release_);
    TECHNIC(TECHNIC& other);
    TECHNIC(TECHNIC&& other) noexcept;
    virtual ~TECHNIC();
    TECHNIC operator=(TECHNIC& other);
    TECHNIC operator=(TECHNIC&& other) noexcept;
    virtual void print();

    void set_date(string year_release_);
    void get_date();
    
    friend ostream& operator<< (ostream& os, TECHNIC& type)
    {
        type.print();
        return os;
    }
    
};



