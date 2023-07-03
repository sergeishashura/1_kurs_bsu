#ifndef TIME_hpp
#define TIME_hpp
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class TIME
{
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
public:
    TIME();
    TIME(unsigned int _hours, unsigned int _minutes, unsigned int _seconds);
    TIME(unsigned int _second);
    TIME(TIME& other);
    TIME(TIME&& other);
    TIME& operator=(TIME& other);
    TIME& operator=(TIME&& other);
    TIME operator+(const TIME& other);
    TIME operator-(const TIME& other);
    bool operator==(TIME& other);
    bool operator!=(TIME& other);
    friend ostream& operator<<(ostream& os,TIME& other)
    {
        os << other.hours << "." << other.minutes << "." << other.seconds;
        return os;
    }
    friend istream& operator>>(istream& is, TIME& other)
    {
        char c;
        is >> other.hours >> c >> other.minutes >> c >> other.seconds;
        return is;
    }
public:
    void add_seconds(int _seconds);
    void substract_seconds(int _seconds);
    unsigned int total_seconds() const;
};

#endif 
