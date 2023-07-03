#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;
void generate_numbers_in_file(fstream &input_file, int size, float value);
void fill_file_g(fstream &output_file, fstream &less_then, fstream &greater_then, float value);
void search_less_and_greater(fstream &infile, fstream &less, fstream &greater, float value);

int main()
{
    srand(time(NULL));
    fstream input_file("f.txt", ios::out);
    fstream infile("f.txt", ios::in);
    fstream less_then("less.txt", ios::out);
    fstream greater_then("greater.txt", ios::out);
    fstream output_file("g.txt", ios::out);
    int size;
    cout << "size = ";
    cin >> size;
    float value = sqrt(2);
    generate_numbers_in_file(input_file, size, value);
    cout << endl;
    search_less_and_greater(infile, less_then, greater_then, value);
    less_then.close();
    greater_then.close();
    fstream less("less.txt", ios::in);
    fstream greater("greater.txt", ios::in);
    fill_file_g(output_file, less, greater, value);
    output_file.close();
    input_file.close();
    infile.close();
    
    return 0;
}

void generate_numbers_in_file(fstream &input_file, int size, float value)
{
    cout << "file f: ";
    float num;
    for (int i = 0; i < size / 2; i++)
    {
        num = ((float)rand() / RAND_MAX) * value;
        input_file << num << "\n";
        cout << num << " ";
    }
    for (int i = 0; i < size / 2; i++)
    {
        num = value + ((float)rand() / RAND_MAX) * value;
        input_file << num << "\n";
        cout << num << " ";
    }
    input_file.seekg(0, ios::beg);
}

void search_less_and_greater(fstream &infile, fstream &less_then, fstream &greater_then, float value)
{
    float num;
    while (infile >> num)
    {
        if (num < value)
            {
                less_then << num << "\n";
            }
        if (num > value)
            {
                greater_then << num << "\n";
            }
    }
}

void fill_file_g(fstream &output_file, fstream &less, fstream &greater, float value)
{

    less.seekg(0, ios::beg);
    greater.seekg(0, ios::beg);
    cout << "file g: ";
    float num;
    while (less >> num)
    {
        output_file << num << endl;
        cout << num << " ";
        if (greater >> num)
        {
            output_file << num << endl;
            cout << num << " ";
        }
    }
}