/* 
 * File:   abstractdatabase.cpp
 * Author: njd
 * 
 * Created on February 11, 2014, 2:20 PM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "student.h"
#include "employee.h"
#include "abstractsort.h"
#include "abstractdatabase.h"

using namespace std;



void StudentDatabase::push(Student* student)
{
    students.push_back(student);
}

int StudentDatabase::getSize()
{
    return students.size();
}

void StudentDatabase::swap(int i, int j)
{
    Student* temp = students[i];
    students[i] = students[j];
    students[j] = temp;   
}

bool StudentDatabase::compare(int j, int i)
{
    if(students[i]->getGrade() < students[j]->getGrade()) return true;
    
    else if(students[i]->getGrade() == students[j]->getGrade())
    {
        if(students[i]->getName() > students[j]->getName()) return true;
        return false;
    }
    return false;
        
}

void StudentDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

void StudentDatabase::print()
{
    for(int i = students.size() - 1; i >= 0; --i)
    {
        students[i]->print();
    }
}

StudentDatabase::~StudentDatabase()
{
    int size = students.size();
    
    for(unsigned int i = 0; i < size; i++)
    {
         Student* tmp = students.back();        
         students.pop_back();
         delete tmp;
    }

}




void EmployeeDatabase::push(Employee* employee)
{
    employees.push_back(employee);
}

void EmployeeDatabase::swap(int i, int j)
{
    Employee* temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;   
}

int EmployeeDatabase::getSize()
{
    return employees.size();
}

bool EmployeeDatabase::compare(int j, int i)
{
    if(employees[i]->getSalary() > employees[j]->getSalary()) return true;
    
    else if(employees[i]->getSalary() == employees[j]->getSalary())
    {
        if(employees[i]->getYear() > employees[j]->getYear()) return true;
        return false;
    }
    return false;
}

void EmployeeDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

void EmployeeDatabase::print()
{
    for(int i = employees.size() - 1; i >= 0; --i)
    {
         employees[i]->print();
    }
}

EmployeeDatabase::~EmployeeDatabase()
{
    int size = employees.size();
    
    for(unsigned int i = 0; i < size; i++)
    {
        Employee* tmp = employees.back();
        employees.pop_back();
        delete tmp;
    }
}