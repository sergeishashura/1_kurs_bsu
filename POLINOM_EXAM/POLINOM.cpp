#include "POLINOM.hpp"

//POLYNOMIAL::POLYNOMIAL(vector<int> coefficients) {
//    for(int i = 0; i < coefficients.size(); i++)
//    {
//        coefficients[i] = coefficients[i];
//    }
//}

int POLYNOMIAL::get_degree_polynomial() const {
    return coefficients.size() - 1;
}

int POLYNOMIAL::get_сoefficient_unknown(int degree) const { 
    return coefficients[degree];
}

POLYNOMIAL POLYNOMIAL::differentiate_polynomial() { 
    int size = get_degree_polynomial();
    vector<int> diff_coefficients(size);
    for(int i = 0; i <= size; i++)
    {
        diff_coefficients[i] = get_сoefficient_unknown(i + 1) * (i + 1);
    }
    return POLYNOMIAL(diff_coefficients);
}

int POLYNOMIAL::operator()(POLYNOMIAL &object, int x) {
    int result = 0;
    for(int i = 0; i < get_degree_polynomial(); i++)
    {
        result += get_сoefficient_unknown(i) * pow(x,i);
    }
    return result;
}

POLYNOMIAL operator+(POLYNOMIAL &object_first, POLYNOMIAL &object_second) {
    int max_size = max(object_first.get_degree_polynomial(), object_second.get_degree_polynomial());
    vector<int> sum_coefficients(max_size + 1);
    for(int i = 0; i <= max_size; i++)
    {
        sum_coefficients[i] = object_first.get_сoefficient_unknown(i) + object_second.get_сoefficient_unknown(i);
    }
    return POLYNOMIAL(sum_coefficients);
}

POLYNOMIAL operator-(POLYNOMIAL &object_first, POLYNOMIAL &object_second) {
    int max_size = max(object_first.get_degree_polynomial(), object_second.get_degree_polynomial());
    vector<int> sub_coefficients(max_size + 1);
    for(int i = 0; i <= max_size; i++)
    {
        sub_coefficients[i] = object_first.get_сoefficient_unknown(i) - object_second.get_сoefficient_unknown(i);
    }
    return POLYNOMIAL(sub_coefficients);
}

POLYNOMIAL operator*(POLYNOMIAL &object_first, POLYNOMIAL &object_second){
    int max_size = object_first.get_degree_polynomial() + object_second.get_degree_polynomial();
    vector<int> mult_coefficients(max_size + 1);
    for(int i = 0; i <= object_first.get_degree_polynomial(); i++)
    {
        for(int j = 0; j <= object_second.get_degree_polynomial(); j++)
        {
            mult_coefficients[i+j] += object_first.get_сoefficient_unknown(i) * object_second.get_сoefficient_unknown(i);
        }
    }
    return mult_coefficients;
}

POLYNOMIAL operator*(POLYNOMIAL &object, int element) {
    int size = object.get_degree_polynomial();
    vector<int> mult_coefficients(size + 1);
    for(int i = 0; i <= size; i++)
    {
        mult_coefficients[i] = object.get_сoefficient_unknown(i) * element;
    }
    return POLYNOMIAL(mult_coefficients);
}

POLYNOMIAL operator/(POLYNOMIAL &object_first, POLYNOMIAL &object_second){
    POLYNOMIAL dividend = object_first;
    POLYNOMIAL divider = object_second;
    POLYNOMIAL quotient;
    while (dividend.get_degree_polynomial() >= divider.get_degree_polynomial()) {
        double ratio = dividend.get_сoefficient_unknown(dividend.get_degree_polynomial()) /
        divider.get_сoefficient_unknown(divider.get_degree_polynomial()); // Находим коэффициент главного члена частного
        vector<int> div_coefficients(dividend.get_degree_polynomial() - divider.get_degree_polynomial() + 1);
        div_coefficients[div_coefficients.size() - 1] = ratio;
        POLYNOMIAL term(div_coefficients);
        quotient = quotient + term;
        POLYNOMIAL q;
        q = term * divider;
        dividend = dividend - q; // Вычитаем произведение частного на делитель из делимого
    }
    return quotient;
}
