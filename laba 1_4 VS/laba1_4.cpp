#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read_data_from_file(fstream&, float*, int*);
void calculate_average_score(int*, float*, float*);
void find_and_enroll_stupid_students(fstream&, ofstream&, unsigned int, float*);

string name;
unsigned int year_study;
float grade;
const unsigned int number_courses = 4; 

int main() 
{
    fstream input_file("List_stud.rtf", ios::in);//можно записать название файла через стринг далее вести работу внутри функции оставив в main только функции открытие произвести в ФУНКЦИЯХ 
    
    unsigned int n;
    float total_grades[number_courses]; 
    int amount_students[number_courses];
    read_data_from_file(input_file, total_grades, amount_students);
    input_file.close();
    float avg_grades[number_courses];
    calculate_average_score(amount_students, avg_grades, total_grades);
    cout << "Enter course: ";
    cin >> n;
    ofstream output_file("Stupid_list.rtf");
    find_and_enroll_stupid_students(input_file, output_file, n, avg_grades);
    output_file.close();
    return 0;
}

void read_data_from_file(fstream& input_file, float* total_grades, int* amount_students)
{
    
    while (input_file >> name >> year_study >> grade)
    {
        total_grades[year_study - 1] += grade;
        amount_students[year_study - 1]++;
    }
}

void calculate_average_score(int *amount_students, float *avg_grades, float *total_grades)
{
    for (int i = 0; i < number_courses; i++)
    {
        if (amount_students[i] > 0)
        {
            avg_grades[i] = total_grades[i] / amount_students[i];
        }
    }

}

void find_and_enroll_stupid_students(fstream& input_file, ofstream& output_file, unsigned int n, float* avg_grades)
{
    input_file.open("List_stud.rtf");
    while (input_file >> name >> year_study >> grade) 
    {
        if (year_study == n && grade < avg_grades[n - 1])
        {
            output_file << name << " " << year_study << " " << grade << endl;

        }
    }
    input_file.close();
}