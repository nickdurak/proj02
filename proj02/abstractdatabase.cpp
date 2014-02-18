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


/*
 add a student to the back of the student database
 */
void StudentDatabase::push(Student* student)
{
    students.push_back(student);
}

/*
 return the number of students stored in the database
 */
int StudentDatabase::getSize()
{
    return students.size();
}

/*
 swap the student at posistion i with the student at posistion
 j in the vector of students
 */
void StudentDatabase::swap(int i, int j)
{
    Student* temp = students[i];
    students[i] = students[j];
    students[j] = temp;   
}

/*
 compare the student at posistion j with the student at posistion i
 in the vector of students.  Return true if student at posistion j
 is greater than the student at posistion i based on having a higher
 GPA, and then based on having a name closer to the beginning of 
 alphebet
 */
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

/*
 sort the database using the sortType passed to the function
 */
void StudentDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

/*
 print out all students in the database starting at
 the back of the vector
 */
void StudentDatabase::print()
{
    for(int i = students.size() - 1; i >= 0; --i)
    {
        students[i]->print();
    }
}

/*
 Destructor for StudentDatabase...pops out each student from
 the back of the vector and deletes them one by one.
 */
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



/*
 add a employee to the back of the employee database
 */
void EmployeeDatabase::push(Employee* employee)
{
    employees.push_back(employee);
}

/*
 return the number of employees stored in the database
 */
void EmployeeDatabase::swap(int i, int j)
{
    Employee* temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;   
}

/*
 swap the employee at posistion i with the employee at posistion
 j in the vector of employees
 */
int EmployeeDatabase::getSize()
{
    return employees.size();
}

/*
 compare the employee at posistion j with the employee at posistion i
 in the vector of employees.  Return true if employee at posistion j
 is greater than the employee at posistion i based on having a lower
 salary, and then based on having a lower starting year
 */
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

/*
 sort the database using the sortType passed to the function
 */
void EmployeeDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

/*
 print out all employees in the database starting at
 the back of the vector
 */
void EmployeeDatabase::print()
{
    for(int i = employees.size() - 1; i >= 0; --i)
    {
         employees[i]->print();
    }
}

/*
 Destructor for employeeDatabase...pops out each employee from
 the back of the vector and deletes them one by one.
 */
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