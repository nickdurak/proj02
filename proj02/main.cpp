/* 
 * File:   main.cpp
 * Author: njd
 *
 * Created on February 11, 2014, 11:59 AM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "student.h"
#include "employee.h"
#include "abstractdatabase.h"
#include "abstractsort.h"
#include "peoplefactory.h"
#include "sortfactory.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    string studentFile = "input1.txt";
    string employeeFile = "input2.txt";
    
    StudentFactory studentFactory;
    EmployeeFactory employeeFactory;
    BubbleSortFactory bubbleSortFactory;
    
    AbstractDatabase* students = studentFactory.load(studentFile);
    AbstractDatabase* employees = employeeFactory.load(employeeFile);
    AbstractSort* BS = bubbleSortFactory.create();
    
    cout << "Student database prior to sort:\n";
    students->print();
    cout << endl;
    students->sort(BS); //sorts the database of students using bubblesort
    cout << "Student database after sort:\n";
    students->print();
    cout << endl;
    
    cout << "**************************************************\n";
    
    cout << "Employee database prior to sort:\n";
    employees->print();
    cout << endl;
    employees->sort(BS); //sorts the database of students using bubblesort
    cout << "Employee database after sort:\n";
    employees->print();
    
    delete students;
    delete employees;
    delete BS;
}

