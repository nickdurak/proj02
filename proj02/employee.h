/******************************************************
 ** FILE: employee.h
 **
 ** ABSTRACT:
 ** Provides declarations for the Employee, Faculty,
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

#ifndef __proj02__employee__
#define __proj02__employee__

#include <iostream>
#include <string>

using std::string;

/**
 Employee
 Purpose: create a Employee
 */

class Employee
{
public:
    
    /**
     constructor for Employee
     */
    Employee(unsigned int employeeID = 0, string name = "", unsigned int salary = 0, unsigned int year = 0);
    
    /**
     print data stored in Employee
     */
    virtual void print();
    
protected:
    
    int m_employeeID;
    string m_name;
    unsigned m_salary;
    int m_year; // entrance year
};


class Faculty: public Employee
{
public:
    
    /**
     constructor for Faculty
     */
    Faculty(unsigned int employeeID, string name, unsigned int salary, unsigned int year, unsigned int numStudents = 0);
    
    /**
     print data stored in Faculty
     */
    virtual void print();
    
private:
    unsigned int m_numStudents;
    
    
};


class Staff: public Employee
{
public:
    
    /**
     constructor for Staff
     */
    Staff(unsigned int employeeID, string name, unsigned int salary, unsigned int year, string dep = "");
    
    /**
     print data stored in Staff
     */
    virtual void print();
    
private:
    string m_dep;
};


#endif /* defined(__proj02__employee__) */
