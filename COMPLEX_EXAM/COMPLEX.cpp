#include "COMPLEX.hpp"


COMPLEX::COMPLEX(double _modulus, double _angle) { 
    modulus = _modulus;
    angle = _angle;
}

double COMPLEX::get_modulus() const {
    return modulus;
}

double COMPLEX::get_angle() const {
    return angle;
}

COMPLEX COMPLEX::operator+(const COMPLEX &object) const{
    double real = modulus * cos(angle) + object.modulus * cos(object.angle);
    double imaginary = modulus * sin(angle) + object.modulus * sin(object.angle);
    double modulus = sqrt(real * real + imaginary * imaginary);
    double angle = atan2(imaginary, real);
    return COMPLEX(modulus, angle);
}

COMPLEX COMPLEX::operator-(COMPLEX &object) { 
    double real = modulus * cos(angle) - object.modulus * cos(object.angle);
    double imaginary = modulus * sin(angle) - object.modulus * sin(object.angle);
    double modulus = sqrt(real * real + imaginary * imaginary);
    double angle = atan2(imaginary, real);
    return COMPLEX(modulus, angle);
}

COMPLEX COMPLEX::operator*(COMPLEX &object) {
    double modulus = this->modulus * object.modulus;
    double angle = this->angle + object.angle;
    return COMPLEX(modulus, angle);
}

COMPLEX COMPLEX::operator/(COMPLEX &object) { 
    double modulus = this->modulus / object.modulus;
    double angle = this->angle - object.angle;
    return COMPLEX(modulus, angle);
}

COMPLEX COMPLEX::operator^(int degree) { 
    double modulus = pow(this->modulus, degree);
    double angle = this->angle * degree;
    return COMPLEX(modulus, angle);
}

COMPLEX COMPLEX::root_complex_num() {
    double mod = sqrt(modulus);
    double angl = angle / 2;
    return COMPLEX(mod, angl);
}










