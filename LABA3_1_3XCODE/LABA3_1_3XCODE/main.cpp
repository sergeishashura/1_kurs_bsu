//убрать повторные вхождения символов
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool has_duplicate(string str)
{
    sort(str.begin(), str.end());
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1])
        {
            return true;
        }
    }
    return false;
}

string remove_duplicates(string input)
{
    string output = "";
    string word = "";
    for (int i = 0; i < input.length(); i++)
    {
        char temp = input[i];
        if (temp == ' ' || temp == '\t' || temp == '\n')
        {
            if (!has_duplicate(word))
            {
                output += word + " ";
            }
            word = "";
        }
        else
        {
            word += temp;
        }
    }
  
    if (!has_duplicate(word))
    {
        output += word + " ";
    }
    return output;
}

int main()
{
    string input = "hi! Good to see you anton vladimirovich";
    string output = remove_duplicates(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;
    return 0;
}

