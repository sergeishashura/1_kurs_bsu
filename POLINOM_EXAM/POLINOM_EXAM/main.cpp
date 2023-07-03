#include "POLINOM.hpp"
int main()
{
    POLYNOMIAL test1, test2, sum, sub, mult, div, mult_el, diff;
    cout << "test" << endl; cin >> test1;
    cout << test1;
    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "test"<< endl; cin >> test2;
    cout << test2;
    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
//    cout << "sum"<< endl;
//    sum = test1 + test2;
//    cout << sum;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
//    cout << "sub"<< endl;
//    sub = test1 - test2;
//    cout << sub;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
//    cout << "mult"<< endl;
//    mult =  test1 * test2;
//    cout << mult;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
//    cout << "div"<< endl;
//    div = test1 / test2;
//    cout << div;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
//    cout << "mult el"<< endl;
//    mult_el = test1 * 5;
//    cout << mult_el;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "diff"<< endl;
    diff = test1.differentiate_polynomial();
    cout << diff;
//    cout <<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
}

