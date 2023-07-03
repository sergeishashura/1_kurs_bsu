#include "SSD.hpp"

SSD::SSD() {
    year_release = "1970";
    capacity_memory = 0;
    fabricator = "/0";
    TBW = 0;
    num_bytes = 0;
}

SSD::SSD(std::string year_release_, unsigned int capacity_memory_, std::string fabricator_, unsigned int TBW_, unsigned int num_bytes_) {
    year_release = year_release_;
    capacity_memory = capacity_memory_;
    fabricator = fabricator_;
    TBW = TBW_;
    num_bytes = num_bytes_;
}

SSD::SSD(SSD &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
        TBW = other.TBW;
        num_bytes = other.num_bytes;
    }
}

SSD::SSD(SSD &&other) noexcept {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
        TBW = other.TBW;
        num_bytes = other.num_bytes;
        other.year_release = "/0";
        other.capacity_memory = 0;
        other.fabricator = "/0";
        other.TBW = 0;
        other.num_bytes = 0;
    }
}

SSD::~SSD() noexcept {
    year_release = "/0";
    capacity_memory = 0;
    fabricator = "/0";
    TBW = 0;
    num_bytes = 0;
}

SSD SSD::operator=(SSD &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
        TBW = other.TBW;
        num_bytes = other.num_bytes;
    }
    return other;
}

SSD SSD::operator=(SSD &&other) {
    if (this != &other)
    {
        year_release = other.year_release;
        capacity_memory = other.capacity_memory;
        fabricator = other.fabricator;
        TBW = other.TBW;
        num_bytes = other.num_bytes;
        other.year_release = "/0";
        other.capacity_memory = 0;
        other.fabricator = "/0";
        other.TBW = 0;
        other.num_bytes = 0;
    }
    return other;
}

void SSD::print() {
    cout << "Year of release: " << year_release << endl;
    cout << "Capacity: " << capacity_memory << endl;
    cout << "Fabricator: " << fabricator << endl;
    cout << "TBW: " << TBW << endl;
    cout << "Number of bytes written: " << num_bytes<< endl;
}

void SSD::set_TBW(unsigned int TBW_) {
    TBW = TBW_;
}

void SSD::get_TBW() {
    cout << "TBW: " << TBW << endl;
}

void SSD::set_num_bytes(unsigned int num_bytes_) {
    num_bytes = num_bytes_;
}

void SSD::get_num_bytes() {
    cout << "Number of bytes written: " << num_bytes << endl;
}













