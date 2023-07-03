#ifndef POLINOM_hpp
#define POLINOM_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class POLYNOMIAL{
private:
    //const int polynomial_degree;
    vector<int> coefficients;
public:
    POLYNOMIAL() {};
    POLYNOMIAL(vector<int> coefficients) : coefficients(coefficients) {};
    friend ostream& operator<<(ostream& os, POLYNOMIAL &object)
    {
        for(int i = 0; i < object.coefficients.size(); i++)
        {
            os << object.coefficients[i] << "x^" << i << "+";
        }
        return os;
    }
    friend istream& operator>>(istream& is, POLYNOMIAL &object)
    {
        int _polynomial_degree = 0;
        cout << "Enter degree of polynomial: ";
        cin >> _polynomial_degree;
        object.coefficients.resize(_polynomial_degree + 1);
        for(int i = 0; i < object.coefficients.size(); i++)
        {
            cin >> object.coefficients[i];
        }
        return is;
    }
    friend POLYNOMIAL operator+(POLYNOMIAL &object_1, POLYNOMIAL &object_2);
    friend POLYNOMIAL operator-(POLYNOMIAL &object_1, POLYNOMIAL &object_2);
    friend POLYNOMIAL operator*(POLYNOMIAL &object_1, POLYNOMIAL &object_2);
    friend POLYNOMIAL operator*(POLYNOMIAL &object, int);
    friend POLYNOMIAL operator/(POLYNOMIAL &object_1, POLYNOMIAL &object_2);
    int operator()(POLYNOMIAL &object, int);
    int get_degree_polynomial() const;
    int get_сoefficient_unknown(int degree) const;
    POLYNOMIAL differentiate_polynomial();
    
};

#endif /* POLINOM_hpp */
