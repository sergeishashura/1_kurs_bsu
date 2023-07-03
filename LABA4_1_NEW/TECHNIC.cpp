#include "TECHNIC.hpp"


TECHNIC::TECHNIC()
{
    year_release = "1970";
}

TECHNIC::TECHNIC(string year_release_)
{
    year_release = year_release_;
}

TECHNIC::~TECHNIC()
{
    year_release = "/0";
    cout << "~TECHNIC" << endl;
}

TECHNIC::TECHNIC(TECHNIC &other)
{
    if (this != &other)
    {
        year_release = other.year_release;
    }
}

TECHNIC::TECHNIC(TECHNIC &&other) noexcept
{
    if (this != &other)
    {
        year_release = other.year_release;
        other.year_release = "/0";
    }
}

TECHNIC TECHNIC::operator=(TECHNIC &other)
{
    if (this != &other)
    {
        year_release = other.year_release;
    }
    return other;
}

TECHNIC TECHNIC::operator=(TECHNIC &&other) noexcept
{
    if (this != &other)
    {
        year_release = other.year_release;
        other.year_release = "/0";
    }
    return other;
}

void TECHNIC::print()
{
    cout << "Year of release: " << year_release << endl;
}

void TECHNIC::set_date(string year_release_)
{
    year_release =  year_release_;
}

void TECHNIC::get_date()
{
    cout << "Year of release: " << year_release << endl;
}












