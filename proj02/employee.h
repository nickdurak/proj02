#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <iostream>

/**
 Employee
 Purpose: create an Employee
 */
class Employee
{
public:
    Employee(unsigned int id = 0, std::string name = "", unsigned int year = 0, unsigned int salary = 0);
    virtual void print() const;
    int getSalary() const;
    int getYear() const;
    
protected:
    
    int m_id;
    std::string m_name;
    unsigned m_salary;
    int m_year; // entrance year
};

/**
 Employee
 Purpose: create a faculty Employee
 */
class Faculty: public Employee
{
public:
    Faculty(unsigned int id, std::string name, unsigned int year, unsigned int salary, unsigned int numStudents = 0);
    virtual void print() const;
    
private:
    unsigned int m_numStudents;
};

/**
 Employee
 Purpose: create a staff Employee
 */
class Staff: public Employee
{
public:
    Staff(unsigned int id, std::string name, unsigned int year, unsigned int salary, std::string dep = "");
    virtual void print() const;

private:
    std::string m_dep;
};



#endif	/* EMPLOYEE_H */

