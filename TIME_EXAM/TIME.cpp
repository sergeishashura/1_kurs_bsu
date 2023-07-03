#include "TIME.hpp"

TIME::TIME()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

TIME::TIME(unsigned int _hours, unsigned int _minutes, unsigned int _seconds) { 
    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
}

TIME::TIME(unsigned int _second) {
    hours = _second / 3600;
    if(hours >= 24)
    {
        hours -= 24;
    }
    minutes = (_second % 3600) / 60;
    seconds = _second % 60;
}

TIME::TIME(TIME &other) {
    if (this != &other)
    {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
}

TIME::TIME(TIME &&other) { 
    if (this != &other)
    {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        other.hours = 0;
        other.minutes = 0;
        other.seconds = 0;
    }
}

TIME &TIME::operator=(TIME &other) { 
    if (this != &other)
    {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

TIME &TIME::operator=(TIME &&other) { 
    if (this != &other)
    {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        other.hours = 0;
        other.minutes = 0;
        other.seconds = 0;
    }
    return *this;
}

TIME TIME::operator+(const TIME &other) { 
    unsigned int _second = total_seconds() + other.total_seconds();
    return TIME(_second);
}

TIME TIME::operator-(const TIME &other) {
    if(other.hours > hours)
    {
        cout << "error";
        abort();
    }
    unsigned int _second = total_seconds() - other.total_seconds();
    return TIME(_second);
}

bool TIME::operator==(TIME &other) {
    unsigned int seconds_first = total_seconds();
    unsigned int seconds_second = other.total_seconds();
    if (seconds_first == seconds_second)
    {
        return true;
    }else return false;
}

bool TIME::operator!=(TIME &other) {
    unsigned int seconds_first = total_seconds();
    unsigned int seconds_second = other.total_seconds();
    if (seconds_first != seconds_second)
    {
        return true;
    }else return false;
}

void TIME::add_seconds(int _seconds) {
    unsigned int result = total_seconds() + _seconds;
    hours = result / 3600;
    minutes = (result % 3600) / 60;
    seconds = result % 60;
}

void TIME::substract_seconds(int _seconds) { 
    unsigned int result = total_seconds() - _seconds;
    hours = result / 3600;
    minutes = (result % 3600) / 60;
    seconds = result % 60;;
}

unsigned int TIME::total_seconds() const{
    return hours * 3600 + minutes * 60 + seconds;
}















