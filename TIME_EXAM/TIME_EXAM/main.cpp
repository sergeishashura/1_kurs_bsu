#include "TIME.hpp"

int main()
{
    TIME ti1;
    TIME ti2;
    TIME ti3;
    cout << "enter first" << endl;
    cin >> ti1;
    cout << "enter second" << endl;
    cin >> ti2;
    ti3 = ti1 + ti2; cout << "result 1: " << ti3 << endl;
    ti3 = ti3 - ti1;  cout << "result 2: " << ti3 << endl;
    ti3 = ti3 + ti1 - ti2; cout << "result 3: " << ti3 << endl;
    ti3.add_seconds(23); cout << "result 4: " << ti3 << endl;
    ti3.add_seconds(60); cout << "result 5: " << ti3 << endl;
    ti3.substract_seconds(32); cout << "result 6: " << ti3 << endl;
    ti3 = ti1; cout << "result 7: " << ti3 << endl;
    
}
