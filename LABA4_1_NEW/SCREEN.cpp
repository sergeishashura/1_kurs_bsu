#include "SCREEN.hpp"


SCREEN::SCREEN() { 
    year_release = "1970";
    diagonal = 0;
    permission = "/0";
    screen_frequency = 0;
}

SCREEN::SCREEN(std::string year_release_, unsigned int diagonal_, std::string permission_, unsigned int screen_frequency_) { 
    year_release = year_release_;
    diagonal = diagonal_;
    permission = permission_;
    screen_frequency = screen_frequency_;
}

SCREEN::SCREEN(SCREEN &other) { 
    if (this != &other)
    {
        year_release = other.year_release;
        diagonal = other.diagonal;
        permission = other.permission;
        screen_frequency = other.screen_frequency;
    }
}

SCREEN::SCREEN(SCREEN &&other) noexcept { 
    if (this != &other)
    {
        year_release = other.year_release;
        diagonal = other.diagonal;
        permission = other.permission;
        screen_frequency = other.screen_frequency;
        other.year_release = "/0";
        other.diagonal = 0;
        other.permission = "/0";
        other.screen_frequency = 0;
    }
}

SCREEN::~SCREEN(){ 
    year_release = "/0";
    diagonal = 0;
    permission = "/0";
    screen_frequency = 0;
    cout << "~SCREEN()" << endl;
}

SCREEN SCREEN::operator=(SCREEN &other) { 
    if (this != &other)
    {
        year_release = other.year_release;
        diagonal = other.diagonal;
        permission = other.permission;
        screen_frequency = other.screen_frequency;
    }
    return other;
}

SCREEN SCREEN::operator=(SCREEN &&other) noexcept { 
    if (this != &other)
    {
        year_release = other.year_release;
        diagonal = other.diagonal;
        permission = other.permission;
        screen_frequency = other.screen_frequency;
        other.year_release = "/0";
        other.diagonal = 0;
        other.permission = "/0";
        other.screen_frequency = 0;
    }
    return other;
}

void SCREEN::print() { 
    cout << "Year of release: " << year_release << endl;
    cout << "Diagonal: " << diagonal << " '' " << endl;
    cout << "Permission: " << permission << endl;
    cout << "Screen refresh rate: " << screen_frequency << "GHz"  << endl;
}

void SCREEN::set_permission(std::string permission_) { 
    permission = permission_;
}

void SCREEN::get_permission() { 
    cout << "Permission: " << permission << endl;
}

void SCREEN::set_diagonal(unsigned int diagonal_) {
    diagonal = diagonal_;
}

void SCREEN::get_diagonal() { 
    cout << "Diagonal: " << diagonal << " '' " << endl;
}

void SCREEN::set_screen_frequency(unsigned int screen_frequency_) { 
    screen_frequency = screen_frequency_;
}

void SCREEN::get_screen_frequency() { 
    cout << "Screen refresh rate: " << screen_frequency << "GHz" << endl;
}













