#include "CPU.hpp"


CPU::CPU() { 
    year_release = "1970";
    fabricator = "/0";
    model = "/0";
    num_cores = 0;
    frequency = 0;
}

CPU::CPU(std::string year_release_, std::string fabricator_, std::string model_, unsigned int num_cores_, unsigned int frequency_) { 
    year_release = year_release_;
    fabricator = fabricator_;
    model = model_;
    num_cores = num_cores_;
    frequency = frequency_;
}

CPU::CPU(CPU &other) { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        model = other.model;
        num_cores = other.num_cores;
        frequency = other.frequency;
    }
}

CPU::CPU(CPU &&other) noexcept { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        model = other.model;
        num_cores = other.num_cores;
        frequency = other.frequency;
        other.year_release = "/0";
        other.fabricator = "/0";
        other.model = "/0";
        other.num_cores = 0;
        other.frequency = 0;
    }
}

CPU::~CPU() noexcept { 
    year_release = "/0";
    fabricator = "/0";
    model = "/0";
    num_cores = 0;
    frequency = 0;
    cout << "~CPU()" << endl;
}

CPU CPU::operator=(CPU &other) { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        model = other.model;
        num_cores = other.num_cores;
        frequency = other.frequency;
    }
    return other;
}

CPU CPU::operator=(CPU &&other) noexcept { 
    if (this != &other)
    {
        year_release = other.year_release;
        fabricator = other.fabricator;
        model = other.model;
        num_cores = other.num_cores;
        frequency = other.frequency;
        other.year_release = "/0";
        other.fabricator = "/0";
        other.model = "/0";
        other.num_cores = 0;
        other.frequency = 0;
    }
    return other;
}

void CPU::print() { 
    cout << "Year of release: " << year_release  << endl;
    cout << "Fabricator: " << fabricator  << endl;
    cout << "Model: " << model << endl;
    cout << "Num cores: " << num_cores << endl;
    cout << "Frequency: " << frequency << endl;
}

void CPU::set_model(std::string model_) { 
    model = model_;
}

void CPU::get_model() { 
    cout << "Model: " << model << endl;;
}

void CPU::set_num_cores(unsigned int num_cores_) { 
    num_cores = num_cores_;
}

void CPU::get_num_cores() { 
    cout << "Num cores: " << num_cores << endl;
}

void CPU::set_frequency(unsigned int frequency_) { 
    frequency = frequency_;
}

void CPU::get_frequency() { 
    cout << "Frequency: " << frequency << endl;
}













