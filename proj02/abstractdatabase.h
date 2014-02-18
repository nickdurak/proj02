/******************************************************
 ** FILE: abstractdatabase.h
 **
 ** ABSTRACT:
 ** Provides declarations for AbstractDatabase, StudentDatabase,
 ** and EmployeeDatabase classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 11/02/2014
 **
 *******************************************************/

#ifndef ABSTRACTDATABASE_H
#define	ABSTRACTDATABASE_H

#include <string>
#include <vector>

class Student;
class Employee;
class AbstractSort;

/*
 AbstractDatabase class interface
 */
class AbstractDatabase
{
public:
    virtual void swap(int,int) = 0;
    virtual bool compare(int,int) = 0;
    virtual void sort(AbstractSort*) = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;
    AbstractDatabase() {}
    virtual ~AbstractDatabase() {}
    
};

/*
 StudentDatabase...class to store a list of students
 */
class StudentDatabase : public AbstractDatabase
{
public:
    virtual int getSize();
    void push(Student*);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    StudentDatabase() {}
    virtual ~StudentDatabase();
    
private:
    std::vector<Student*> students;
};

/*
 EmployeeDatabase...class to store a list of employees
 */
class EmployeeDatabase : public AbstractDatabase
{
public:
    virtual int getSize();
    void push(Employee*);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    EmployeeDatabase() {}
    virtual ~EmployeeDatabase();
    
private:
    std::vector<Employee*> employees;
};

#endif	/* ABSTRACTDATABASE_H */

