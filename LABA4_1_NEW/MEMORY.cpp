#include "MEMORY.hpp"


MEMORY::MEMORY()
{
    year_release = "1970";
    capacity_memory = 0;
    fabricator = "/0";
}

MEMORY::MEMORY(string year_release_, unsigned int capacity_memory_, string fabricator_)
{
    year_release = year_release_;
    capacity_memory = capacity_memory_;
    fabricator = fabricator_;
}

MEMORY::MEMORY(MEMORY &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
    }
}

MEMORY::MEMORY(MEMORY &&other) noexcept {
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

MEMORY::~MEMORY(){
    year_release = "/0";
    fabricator = "/0";
    capacity_memory = 0;
    cout << "~MEMORY" << endl;
}

MEMORY MEMORY::operator=(MEMORY &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
    }
    return other;
}

MEMORY MEMORY::operator=(MEMORY &&other) noexcept {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        other.year_release = "/0";
        other.capacity_memory = 0;
    }
    return other;
}

void MEMORY::print() {
    cout << "Year of release: " << year_release << endl;
    cout << "Capacity: " << capacity_memory << endl;
    cout << "Fabricator: " << fabricator << endl;
}

void MEMORY::set_capacity(unsigned int capacity_memory_)
{
    capacity_memory = capacity_memory_;
}

void MEMORY::get_capacity() {
    cout << "Capacity: " << capacity_memory << endl;
}














