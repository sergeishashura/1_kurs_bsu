#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real_num;
    double imag_num;
public:
    Complex() {};
    Complex(double _real_num, double _imag_num);
    Complex(Complex & object);
    Complex operator+(Complex& object);
    Complex operator-(Complex& object);
    Complex operator*(Complex& object);
    Complex operator/(Complex& object);
    Complex operator^(int degree);
    //Complex root_complex_num();
    double get_real_num() const;
    double get_imag_num() const;
    friend ostream& operator<<(ostream& os,Complex& object)
    {
        os << object.real_num << " + " << object.imag_num << "i" << endl;
        return os;
    }
    friend istream& operator>>(istream& is,Complex& object)
    {
        cout << "Enter real num: ";
        is >> object.real_num;
        cout << "Enter imag num:";
        is >> object.imag_num;
        return is;
    }
};

#endif /* Complex_hpp */
