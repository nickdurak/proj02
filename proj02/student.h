/******************************************************
 ** FILE: student.h
 **
 ** ABSTRACT:
 ** Provides declarations for the Student, UndergradStudent,
 ** and GraduateStudent classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 15/01/2014
 **
 *******************************************************/

#ifndef __proj02__student__
#define __proj02__student__

#include<iostream>
#include<vector>
using namespace std;

/**
    Student
    Purpose: create a student
*/
class Student
{
public:
    
    /**
        constructor for student
     */
    Student(int studentID = 0, string name = "", int year = 0, float grade = 0.0);
    
    /**
        print data stored in student
     */
    virtual void print();
    
protected:
    
    int m_studentID;
    string m_name;
    int m_year;
    float m_grade; // GPA
};


class UndergradStudent: public Student
{
public:
    
    /**
        constructor for UndergradStudent
     */
    UndergradStudent(int studentID, string name, int year, float grade, string major, string minor);
    
    /**
        print data stored in UndergradStudent
     */
    virtual void print();
    
private:
    string m_major;
    string m_minor;
    
    
};


class GraduateStudent: public Student
{
public:
    
    /**
        constructor for GraduateStudent
     */
    GraduateStudent(int studentID, string name, int year, float grade, string dep, string advisor);
    
    /**
        print data stored in GraduateStudent
     */
    virtual void print();
    
private:
    string m_dep;
    string m_advisor;
};



#endif

