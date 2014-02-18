//
//  peopleFactory.cpp
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "peoplefactory.h"
#include "abstractdatabase.h"
#include "student.h"
#include "employee.h"

using namespace std;

AbstractDatabase* StudentFactory::load(string file)
{
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
    
    
    if (studentFile.is_open())
    {
        while (getline (studentFile, line))
        {
            if (line[0] == 'U')
            {
                stringstream undergradStream;
                undergradStream << line;
                
                
                undergradStream >> dummy >> id >> name >> year >> grade >> major >> minor;
                
                students->push(new UndergradStudent(id, name, year, grade, major, minor));
                
            }
            
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

AbstractDatabase* EmployeeFactory::load(string file)
{
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
    
    
    if (employeeFile.is_open())
    {
        while (getline (employeeFile, line))
        {
            if (line[0] == 'F')
            {
                stringstream facultyStream;
                facultyStream << line;
                
                facultyStream >> dummy >> id >> name >> year >> salary >> numStudents;
                
                employees->push(new Faculty(id, name, year, salary, numStudents));
                
            }
            
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
