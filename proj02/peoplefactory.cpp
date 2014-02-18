/******************************************************
 ** FILE: peoplefactory.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of the StudentFactory
 ** and EmployeeFactory classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 12/02/2014
 **
 *******************************************************/

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "peoplefactory.h"
#include "abstractdatabase.h"
#include "student.h"
#include "employee.h"

using namespace std;

/*
 loads a student database from an input file.  Takes in the name
 of the input file as a parameter
 */
AbstractDatabase* StudentFactory::load(string file)
{
    // create StudentDatabase to fill
    StudentDatabase* students = new StudentDatabase();
    
    string line = "";
    unsigned int id = 0;
    unsigned int year = 0;
    float grade = 0;
    string name = "";
    string major = "";
    string minor = "";
    string dep = "";
    string advisor = "";
    string dummy = "";
    ifstream studentFile (file);
    
    // checks if file is open
    if (studentFile.is_open())
    {
        // reads the file line by line
        while (getline (studentFile, line))
        {
            // adds a UndergradStudent to students
            if (line[0] == 'U')
            {
                stringstream undergradStream;
                undergradStream << line;
                
                undergradStream >> dummy >> id >> name >> year >> grade >> major >> minor;
                
                students->push(new UndergradStudent(id, name, year, grade, major, minor));
            }
            // adds a GraduateStudent to students
            if (line[0] == 'G')
            {
                stringstream graduateStream;
                graduateStream << line;
                
                graduateStream >> dummy >> id >> name >> year >> grade >> dep >> advisor;
                
                students->push(new GraduateStudent(id, name, year, grade, dep, advisor));
            }
        }
    }
    
    studentFile.close();
    
    return students;
}


/*
 loads a employee database from an input file.  Takes in the name
 of the input file as a parameter
 */
AbstractDatabase* EmployeeFactory::load(string file)
{
    // create EmployeeDatabase to fill
    EmployeeDatabase* employees = new EmployeeDatabase();
    
    ifstream employeeFile (file);
    string line = "";
    unsigned int id = 0;
    unsigned int year = 0;
    float grade = 0;
    string dep = "";
    string name = "";
    unsigned int salary = 0;
    unsigned int numStudents = 0;
    string dummy = "";
    
    // checks if file is open
    if (employeeFile.is_open())
    {
        // reads the file line by line
        while (getline (employeeFile, line))
        {
            // adds a Faculty to employees
            if (line[0] == 'F')
            {
                stringstream facultyStream;
                facultyStream << line;
                
                facultyStream >> dummy >> id >> name >> year >> salary >> numStudents;
                
                employees->push(new Faculty(id, name, year, salary, numStudents));
                
            }
            // adds a Staff to employees
            if (line[0] == 'S')
            {
                stringstream staffStream;
                staffStream << line;
                
                staffStream >> dummy >> id >> name >> year >> salary >> dep;
                
                employees->push(new Staff(id, name, year, salary, dep));
            }
        }
    }
    
    employeeFile.close();
    
    return employees;

}
