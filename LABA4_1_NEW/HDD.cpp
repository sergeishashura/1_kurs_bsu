#include "HDD.hpp"


HDD::HDD()
{
    year_release = "1970";
    capacity_memory = 0;
    fabricator = "/0";
}

HDD::HDD(string year_release_, unsigned int capacity_memory_, string fabricator_)
{
    year_release = year_release_;
    capacity_memory = capacity_memory_;
    fabricator = fabricator_;
}

HDD::HDD(HDD &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
    }
}

HDD::HDD(HDD &&other) noexcept {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
        other.year_release = "/0";
        other.capacity_memory = 0;
        other.fabricator = "/0";
    }
}

HDD::~HDD() noexcept {
    year_release = "/0";
    fabricator = "/0";
    capacity_memory = 0;
    cout << "~HDD" << endl;
}

HDD HDD::operator=(HDD &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
    }
    return other;
}

HDD HDD::operator=(HDD &&other) noexcept {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        other.year_release = "/0";
        other.capacity_memory = 0;
    }
    return other;
}

void HDD::print() {
    cout << "Year of release: " << year_release << endl;
    cout << "Capacity: " << capacity_memory << endl;
    cout << "Fabricator: " << fabricator << endl;
}














