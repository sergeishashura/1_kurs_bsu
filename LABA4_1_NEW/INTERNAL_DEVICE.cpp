#include "INTERNAL_DEVICE.hpp"


INTERNAL_DEVICE::INTERNAL_DEVICE() {
    year_release = "1970";
    fabricator = "/0";
}

INTERNAL_DEVICE::INTERNAL_DEVICE(std::string year_release_, std::string fabricator_) { 
    year_release = year_release_;
    fabricator = fabricator_;
}

INTERNAL_DEVICE::INTERNAL_DEVICE(INTERNAL_DEVICE &other) {
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
    }
}

INTERNAL_DEVICE::INTERNAL_DEVICE(INTERNAL_DEVICE &&other) noexcept {
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        other.year_release = "/0";
        other.fabricator = "/0";
    }
}

INTERNAL_DEVICE::~INTERNAL_DEVICE() noexcept { 
    year_release = "/0";
    fabricator = "/0";
    cout << "~INTERNAL_DEVICE" << endl;
}

INTERNAL_DEVICE INTERNAL_DEVICE::operator=(INTERNAL_DEVICE &other) { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
    }
    return other;
}

INTERNAL_DEVICE INTERNAL_DEVICE::operator=(INTERNAL_DEVICE &&other) noexcept { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        other.year_release = "/0";
        other.fabricator = "/0";
    }
    return other;
}

void INTERNAL_DEVICE::print() {
    cout << "Year of release: " << year_release << endl;
    cout << "Fabricator: " << fabricator << endl;
}

void INTERNAL_DEVICE::set_fabricator(std::string fabricator_) { 
    fabricator = fabricator_;;
}

void INTERNAL_DEVICE::get_fabricator() { 
    cout << "Fabricator: " << fabricator << endl;
}











