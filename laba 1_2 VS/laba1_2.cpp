#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

void generate_numbers_in_file(ofstream& input_file, int size, double value);
void fill_file_g(ifstream& less, ifstream& greater, ofstream& output_file, float value);
void search_less_and_greater(ifstream& infile, ofstream& less_then, ofstream& greater_then, float value);

int main()
{
    srand(time(NULL));
    ofstream input_file("f.bin", ios::binary);
    ifstream infile("f.bin", ios::binary);
    ofstream less_then("less.bin", ios::binary);
    ofstream greater_then("greater.bin", ios::binary);
    ofstream output_file("g.bin", ios::binary);
    int size;
    cout << "size = ";
    cin >> size;
    double value = sqrt(2);
    generate_numbers_in_file(input_file, size, value);
    input_file.close();
    search_less_and_greater(infile, less_then, greater_then, value);
    less_then.close();
    greater_then.close();
    ifstream less("less.bin", ios::binary);
    ifstream greater("greater.bin", ios::binary);
    fill_file_g(less, greater, output_file, value);
    output_file.close();
    less.close();
    greater.close();
    return 0;
}

void generate_numbers_in_file(ofstream& input_file, int size, double value)
{
    cout << "file f: ";
    double num;
    for (int i = 0; i < size / 2; i++)
    {
        num = ((double)rand() / RAND_MAX) * value;
        input_file.write(reinterpret_cast<const char*>(&num), sizeof(double));
        cout << num << " ";
    }
    for (int i = 0; i < size / 2; i++)
    {
        num = value + ((double)rand() / RAND_MAX) * value;
        input_file.write(reinterpret_cast<const char*>(&num), sizeof(double));
        cout << num << " ";
    }
}

void search_less_and_greater(ifstream& infile, ofstream& less_then, ofstream& greater_then, float value)
{
    double num;
    while (infile.read(reinterpret_cast<char*>(&num), sizeof(double)))
    {
        if (num < value)
        {
            less_then.write(reinterpret_cast<const char*>(&num), sizeof(double));
        }
        if (num > value)
        {
            greater_then.write(reinterpret_cast<const char*>(&num), sizeof(double));
        }
    }
}

void fill_file_g(ifstream& less, ifstream& greater, ofstream& output_file, float value)
{
    cout << endl << "file g: ";
    bool write_greater = false;
    double num;
    while (less.read(reinterpret_cast<char*>(&num), sizeof(double)))
    {
        output_file.write(reinterpret_cast<const char*>(&num), sizeof(double));
        cout << num << " ";
        if (greater.read(reinterpret_cast<char*>(&num), sizeof(double)))
        {
            output_file.write(reinterpret_cast<const char*>(&num), sizeof(double));
            cout << num << " ";
            write_greater = true;
        }
        else
        {
            break;
        }
    }
}