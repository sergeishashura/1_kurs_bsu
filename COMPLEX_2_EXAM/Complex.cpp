#include "Complex.hpp"


Complex::Complex(double _real_num, double _imag_num) {
    real_num = _real_num;
    imag_num = _imag_num;
}

Complex::Complex(Complex &object) {
    real_num = object.real_num;
    imag_num = object.imag_num;
}

Complex Complex::operator+(Complex &object) { 
    double real = real_num + object.real_num;
    double imag = imag_num + object.imag_num;
    return Complex(real, imag);
}

Complex Complex::operator-(Complex &object) { 
    double real = real_num - object.real_num;
    double imag = imag_num - object.imag_num;
    return Complex(real, imag);;
}

Complex Complex::operator*(Complex &object) { 
    double real = (real_num * object.real_num) - (imag_num * object.imag_num);
    double imag = (real_num * object.imag_num) + (imag_num * object.real_num);
    return Complex(real, imag);
}

Complex Complex::operator/(Complex &object) {
    double divider = object.real_num * object.real_num + object.imag_num * imag_num;
    double real = (real_num * object.real_num + imag_num * object.imag_num) / divider;
    double imag = (imag_num * object.real_num + real * object.imag_num) / divider;
    return Complex(real, imag);
}

Complex Complex::operator^(int degree) { 
    Complex result = *this;
    for(int i = 0; i < degree; i++)
    {
        result = result * *this;
    }
    return result;
}

//Complex Complex::root_complex_num() { 
//    
//}

double Complex::get_real_num() const{
    return real_num;
}

double Complex::get_imag_num() const{ 
    return imag_num;
}










