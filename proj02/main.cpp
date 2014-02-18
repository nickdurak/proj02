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
int main(int argc, char* argv[])
{
    // read in strings from command line
    if(argc != 3)
    {
		cerr << "Incorrect nubmer of command line arguments." << endl;
		cerr << "Usage: " << argv[0] << " <first_input_file> <second_input_file>" << endl;
		exit(EXIT_FAILURE);
	}
    
	string first_input_file = argv[1];    // first input file, should be an input file of students
	string second_input_file = argv[2];   // second input file, should be an input file of employees

    // create factory objects
    StudentFactory studentFactory;
    EmployeeFactory employeeFactory;
    BubbleSortFactory bubbleSortFactory;
    
    
    // use factory to build database objects and sort object
    AbstractDatabase* students = studentFactory.load(first_input_file);
    AbstractDatabase* employees = employeeFactory.load(second_input_file);
    AbstractSort* BS = bubbleSortFactory.create();
    
    students->sort(BS); //sorts the database of students using bubblesort
    cout << "The list of students are :\n";
    students->print(); //prints database of students
    
    cout << endl;
    
    employees->sort(BS); //sorts the database of employeess using bubblesort
    cout << "The list of employees are :\n";
    employees->print(); //prints database of employees
    
    //free up memory
    delete students;
    delete employees;
    delete BS;
}

