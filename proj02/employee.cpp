/******************************************************
 ** FILE: employee.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of the Employee, Faculty,
 ** and Staff classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 05/02/2014
 **
 *******************************************************/

#include "employee.h"
#include <string>

using namespace std;

/**
 constructor for Employee
 */
Employee::Employee(unsigned int id, string name, unsigned int year, unsigned int salary)
{
    m_id = id;
    m_name = name;
    m_salary = salary;
    m_year = year;
}

/**
 print data stored in Employee
 */
void Employee::print() const
{
    cout << m_id << " " << m_name << " " << m_year << " " << m_salary;
}

/*
 return the salary
 */
int Employee::getSalary() const
{
    return m_salary;
}

/*
 return the year
 */
int Employee::getYear() const
{
    return m_year;
}



/**
 constructor for Faculty
 */
Faculty::Faculty(unsigned int id, string name, unsigned int year, unsigned int salary, unsigned int numStudents)
: Employee(id, name, year, salary)
{
    m_numStudents = numStudents;
}

/**
 print data stored in Faculty
 */
void Faculty::print() const
{
    Employee::print();
    cout << " " << m_numStudents << endl;
}


/**
 constructor for Staff
 */
Staff::Staff(unsigned int id, string name, unsigned int year, unsigned int salary, string dep)
: Employee(id, name, year, salary)
{
    m_dep = dep;
}

/**
 print data stored in Staff
 */
void Staff::print() const
{
    Employee::print();
    cout << " " << m_dep << endl;
}
