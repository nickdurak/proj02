

#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

#include "student.h"
#include "employee.h"

int main()
{
    ifstream studentFile ("Users/njd/Documents/School/CSE 335/proj02/proj02/input1.txt");
    ifstream employeeFile ("/Users/njd/Documents/School/CSE 335/proj02/proj02/input2.txt");
    string line = "";
    unsigned int studentID = 0;
    unsigned int year = 0;
    float grade = 0;
    string name = "";
    string major = "";
    string minor = "";
    string dep = "";
    string advisor = "";
    unsigned int employeeID = 0;
    unsigned int salary = 0;
    unsigned int numStudents = 0;
    string dummy = "";
    
    
    vector<Student*> studentList;
    vector<Employee*> employeeList;
    
    if (studentFile.is_open())
    {
        while (getline (studentFile, line))
        {
            if (line[0] == 'U')
            {
                stringstream undergradStream;
                undergradStream << line;
                
                
                undergradStream >> dummy >> studentID >> name >> year >> grade >> major >> minor;
                
                studentList.push_back(new UndergradStudent(studentID, name, year, grade, major, minor));
                
            }
            
            if (line[0] == 'G')
            {
                stringstream graduateStream;
                graduateStream << line;
                
                graduateStream >> dummy >> studentID >> name >> year >> grade >> dep >> advisor;
                
                studentList.push_back(new GraduateStudent(studentID, name, year, grade, dep, advisor));
            }
        }
    }
    
    studentFile.close();
    
    if (employeeFile.is_open())
    {
        while (getline (employeeFile, line))
        {
            if (line[0] == 'F')
            {
                stringstream facultyStream;
                facultyStream << line;
                
                facultyStream >> dummy >> employeeID >> name >> salary >> year >> numStudents;
                
                employeeList.push_back(new Faculty(employeeID, name, salary, year, numStudents));
                
            }
            
            if (line[0] == 'S')
            {
                stringstream staffStream;
                staffStream << line;
                
                staffStream >> dummy >> employeeID >> name >> salary >> year >> numStudents;
                
                employeeList.push_back(new Staff(employeeID, name, salary, year, dep));
            }
        }
    }
    
    employeeFile.close();
    

}

