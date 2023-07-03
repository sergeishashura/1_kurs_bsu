#include "COMPLEX.hpp"
int main() {
    const double pi = M_PI;

    // Создаем два комплексных числа
    COMPLEX z1(2, pi/4);
    COMPLEX z2(3, pi/6);

    // Выводим их на экран
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    // Выполняем операции
    cout << "z1 + z2 = " << z1 + z2 << endl;
    cout << "z1 - z2 = " << z1 - z2 << endl;
    cout << "z1 * z2 = " << z1 * z2 << endl;
    cout << "z1 / z2 = " << z1 / z2 << endl;

    return 0;
}

