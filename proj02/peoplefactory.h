/******************************************************
 ** FILE: sortfactory.h
 **
 ** ABSTRACT:
 ** Provides declaration of the Student, UndergradStudent,
 ** and GraduateStudent classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 12/02/2014
 **
 *******************************************************/

#ifndef __proj02__peoplefactory__
#define __proj02__peoplefactory__

#include <iostream>

class AbstractDatabase;

/*
 PeopleFactory...class with interface for people factories
 */
class PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string) = 0;
    PeopleFactory() {}
    virtual ~PeopleFactory() {}
};

/*
 StudentFactory...class for building student database
 */
class StudentFactory : public PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string);
    StudentFactory() {}
    virtual ~StudentFactory() {}
};

/*
 EmployeeFactory...class for building employee database
 */
class EmployeeFactory : public PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string);
    EmployeeFactory() {}
    virtual ~EmployeeFactory() {}
};

#endif /* defined(__proj02__peoplefactory__) */
