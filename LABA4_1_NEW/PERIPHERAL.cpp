#include "PERIPHERAL.hpp"


PERIPHERAL::PERIPHERAL()
{
    year_release = "1970";
}

PERIPHERAL::PERIPHERAL(string year_release_)
{
    year_release = year_release_;
}

PERIPHERAL::~PERIPHERAL()
{
    year_release = "/0";
    cout << "~PERIPHERAL" << endl;
}

PERIPHERAL::PERIPHERAL(PERIPHERAL &other)
{
    if (this != &other)
    {
        year_release = other.year_release;
    }
}

PERIPHERAL::PERIPHERAL(PERIPHERAL &&other) noexcept
{
    if (this != &other)
    {
        year_release = other.year_release;
        other.year_release = "/0";
    }
}

PERIPHERAL PERIPHERAL::operator=(PERIPHERAL &other)
{
    if (this != &other)
    {
        year_release = other.year_release;
    }
    return other;
}

PERIPHERAL PERIPHERAL::operator=(PERIPHERAL &&other) noexcept
{
    if (this != &other)
    {
        year_release = other.year_release;
        other.year_release = "/0";
    }
    return other;
}

void PERIPHERAL::print()
{
    cout << "Year of release: " << year_release << endl;;
}












