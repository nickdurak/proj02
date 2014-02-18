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

#ifndef STUDENT_H
#define	STUDENT_H

#include <iostream>


/**
    Student
    Purpose: create a student
*/
class Student
{
public:
    Student(unsigned int id = 0, std::string name = "", unsigned int year = 0, float grade = 0.0);
    virtual void print() const;
    int getGrade() const;
    std::string getName() const;
    
protected:
    unsigned int m_id;
    std::string m_name;
    unsigned int m_year;
    float m_grade; // GPA
};


class UndergradStudent: public Student
{
public:
    UndergradStudent(unsigned int id, std::string name, unsigned int year, float grade, std::string major = "", std::string minor = "");
    virtual void print() const;
    
private:
    std::string m_major;
    std::string m_minor;
};


class GraduateStudent: public Student
{
public:
    GraduateStudent(unsigned int id, std::string name, unsigned int year, float grade, std::string dep = "", std::string advisor = "");
    virtual void print() const;
    
private:
    std::string m_dep;
    std::string m_advisor;
};

#endif	/* STUDENT_H */

