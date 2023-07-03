//вывести числа которые являются полиндромами в двоичной системе до N
//https://calculatori.ru/perevod-chisel.html
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome(int num) {
    int rev = 0;
    int n = num;
    while(n > 0)
    {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return num == rev;
}

int main()
{
    int N;
    cout << "Enter a natural number N:";
    cin >> N;

    vector<int> palindromes;
    for(int i = 1; i <= N; i++)
    {
        if(is_palindrome(i))
        {
            palindromes.push_back(i);
        }
    }

    cout << "All numbers are palindromes in the binary system, not exceeding " << N << ": ";
    for_each(palindromes.begin(), palindromes.end(), [](int num){cout << num << " ";});
    cout << endl;

    return 0;
}
