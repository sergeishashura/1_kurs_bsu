#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int course;
    float avg_grade;
    //конструктор 
    Student (string name, int course, float avg_grade) :
    name(name), course(course), avg_grade(avg_grade) {}
};

void read_data_from_file(fstream& , vector<Student>&,  string , int , float , float*, int*);
void calculate_average_score(int*, float*, float*);
void find_and_enroll_stupid_students(ofstream&, vector<Student>&, int, float*);
int main() 
{
    fstream input_file("List_stud.rtf", ios::in);
    int n;
    vector<Student> students; 
    string name;
    int course;
    float grade;
    float total_grades[4];
    int num_students[4];
    read_data_from_file(input_file, students, name, course, grade, total_grades, num_students);
    input_file.close(); 
    float avg_grades[4] = {0};
    calculate_average_score(num_students, avg_grades, total_grades);
    cout << "Enter course: ";
    cin >> n;
    ofstream output_file("Stupid_list.bin", ios::binary);
    find_and_enroll_stupid_students(output_file, students, n, avg_grades);
    output_file.close();
    return 0;
}

void read_data_from_file(fstream& input_file, vector<Student>& students, string name, int course, float grade, float* total_grades, int* num_students)
{
    while (input_file >> name >> course >> grade)
    {
        students.push_back(Student(name, course, grade));
        total_grades[course - 1] += grade;
        num_students[course - 1]++;
    }
}

void calculate_average_score(int *num_students, float *avg_grades, float *total_grades)
{
    for (int i = 0; i < 4; i++)
    {
        if (num_students[i] > 0)
        {
            avg_grades[i] = total_grades[i] / num_students[i];
        }
    }
}

void find_and_enroll_stupid_students(ofstream& output_file, vector<Student>& students, int n, float* avg_grades)
{
    string name;
    float grade;
    int course;

    for (const auto& student : students) 
    {
        if (student.course == n && student.avg_grade < avg_grades[n - 1])
        {
            //output_file << student.name << " " << student.course << " " << student.avg_grade << endl;
            name = student.name;
            grade = student.avg_grade;
            course = student.course;
            output_file.write(reinterpret_cast<char*> (&name), sizeof(name));
            output_file.write(reinterpret_cast<char*> (&course), sizeof(course));
            output_file.write(reinterpret_cast<char*> (&grade), sizeof(grade));
        }
    }
}