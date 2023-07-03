#ifndef COMPLEX_hpp
#define COMPLEX_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

class COMPLEX
{
private:
    double modulus;
    double angle;
public:
    COMPLEX() {};
    COMPLEX(double _modulus, double _angle);
    COMPLEX operator+(const COMPLEX &object) const;
    COMPLEX operator-(COMPLEX &object);
    COMPLEX operator*(COMPLEX &object);
    COMPLEX operator/(COMPLEX &object);
    COMPLEX operator^(int degree);
    COMPLEX root_complex_num();
    double get_modulus() const;
    double get_angle() const;
    friend ostream& operator<<(ostream& os, const COMPLEX &object)
    {
        os << object.modulus << " * e^(i" << object.angle << "pi)";
        return os;
    }
//    friend istream& operator>>(istream& is, COMPLEX &object)
//    {
//        cout << "enter modulus: ";
//        cin >> object.modulus;
//        cout << endl << "enter angle: ";
//        cin >> object.angle;
//        return is;
//    }
};
#endif /* COMPLEX_hpp */
