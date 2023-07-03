#include <iostream>
#include <vector>
#include <string>

using namespace std;
class BigInt {
    vector<int> num;
public:
    BigInt(string number) {
        try {
            for (size_t i = 0; i < number.size(); i++) {
                num.push_back(stoi(string(1, number[i])));
            }
        }
        catch (const std::exception&) {
            std::cout << "input only nums" << endl;
            system("pause");
            system("taskkill /F /IM test.exe");
        }
    }
    void print() {
        for (size_t i = 0; i < num.size(); i++)
        {
            cout << num[i];
        }
    }
    
    friend ostream& operator<<(ostream& os, BigInt& num) {
        num.print();
        return os;
    }
    string toBinary() {
        string binary = "";
        for (int i = num.size() - 1; i >= 0; i--) {
            int n = num[i];
            for (int j = 0; j < 9; j++) {
                binary = to_string(n % 2) + binary;
                n /= 2;
            }
        }
        int i = 0;
        while (binary[i] == '0' && i < binary.size() - 1) {
            i++;
        }
        return binary.substr(i);
    }
    
    BigInt operator+(BigInt const& obj)
    {
        BigInt res("");
        int carry = 0;
        int n1 = num.size(), n2 = obj.num.size();
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0  || carry)
        {
            int sum = carry;
            if (i >= 0) sum += num[i];
            if (j >= 0) sum += obj.num[j];
            res.num.push_back(sum % 10);
            carry = sum / 10;
            i--; j--;
        }
        reverse(res.num.begin(), res.num.end());
        return res;
    }
    friend BigInt operator++(BigInt n) {
        return n + BigInt("1");//++a
    }
    BigInt operator++(int)//a++
    {
        BigInt res(*this);
        *this = *this + BigInt("1");
        return res;
    }
    
    BigInt operator-(BigInt const& obj)
    {
        BigInt res("");
        int borrow = 0;
        int n1 = num.size(), n2 = obj.num.size();
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0) {
            int diff = borrow;
            if (i >= 0) diff += num[i];
            if (j >= 0) diff -= obj.num[j];
            if (diff < 0)
            {
                diff += 10;
                borrow = -1;
            }
            else borrow = 0;
            res.num.push_back(diff);
            i--; j--;
        }
        while (res.num.size() > 1 && res.num.back() == 0) res.num.pop_back();
        reverse(res.num.begin(), res.num.end());
        return res;
    }
    
    BigInt operator*(BigInt const& obj) {
        BigInt res("0");
        int n1 = num.size(), n2 = obj.num.size();
        vector<int> prod(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                prod[i + j + 1] += num[i] * obj.num[j];
                prod[i + j] += prod[i + j + 1] / 10;
                prod[i + j + 1] %= 10;
            }
        }
        int i = prod.size() - 1;
        while (i >= 0 && prod[i] == 0) i--;
        if (i == -1) return BigInt("0");
        while (i >= 0) {
            res.num.push_back(prod[i]);
            i--;
        }
        reverse(res.num.begin(), res.num.end());
        while (res.num.size() > 1 && res.num[0] == 0) {
            res.num.erase(res.num.begin());
        }
        res.num.pop_back();
        return res;
    }
};

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    BigInt s = to_string(11111111111111111111);
    BigInt a(s1), b(s2);
    BigInt c = a + b;
    BigInt d = a - b;
    BigInt e = a * b;
    string str = a.toBinary();
    c.print(); cout << endl;
    d.print(); cout << endl;
    cout << e << endl;
    cout << str << "\n";
    s++;
    cout << s;
    return 0;
}
