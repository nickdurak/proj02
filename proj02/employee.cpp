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


/**
 constructor for Employee
 */
Employee::Employee(unsigned int employeeID, string name, unsigned int salary, unsigned int year)
{
    m_employeeID = studentID;
    m_name = name;
    m_salary = salary;
    m_year = year;
}

/**
 print data stored in Employee
 */
void Employee::print()
{
    cout << std::setprecision(3) << m_employeeID << " " << m_name << " " << m_salary << " " << m_year;
}


/**
 constructor for Faculty
 */
Faculty::Faculty(unsigned int employeeID, string name, unsigned int salary, unsigned int year, unsigned int numStudents)
: Employee(employeeID, name, salary, year)
{
    m_numStudents = numStudents;
}

/**
 print data stored in Faculty
 */
void Faculty::print()
{
    Employee::print();
    cout << " " << m_numStudents << endl;
}


/**
 constructor for Staff
 */
Staff::Staff(unsigned int employeeID, string name, unsigned int salary, unsigned int year, string dep)
: Employee(employeeID, name, salary, year)
{
    m_dep = dep;
}

/**
 print data stored in Staff
 */
void Staff::print()
{
    Employee::print();
    cout << " " << m_dep << endl;
}