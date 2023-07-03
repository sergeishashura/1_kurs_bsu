//Вывести строку, удалив из нее повторные вхождения символов. Вывести в алфавитном порядке все гласные латинские буквы, входящие в строку.
// AaaaAAAAbewgoiwjeroghjwOOOOoOOzzzzKLLLpyyyeee
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    string line;
    cout << "ENTER STRING: ";
    cin >> line;
    string alph_vowels = "AaEeIiOoUuYy";
    string result_vowels;
    set<char> unique_let;
    cout << endl << "a string without repeated occurrences of characters: " << endl;
    for(char letter : line)
    {
        unique_let.insert(letter);
    }
    copy(unique_let.begin(), unique_let.end(), ostream_iterator<char>(cout));
    cout << endl << endl;
    cout << "alphabetically, all vowel Latin letters included in the string: " << endl;
    for(char vowel : line)
    {
        if(alph_vowels.find(vowel) != string::npos)
        {
            result_vowels += vowel;
        }
    }
    sort(result_vowels.begin(), result_vowels.end());
    cout << result_vowels << endl;
    return 0;
}
