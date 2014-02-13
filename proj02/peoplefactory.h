//
//  peoplefactory.h
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __proj02__peoplefactory__
#define __proj02__peoplefactory__

#include <iostream>


class AbstractDatabase;

class PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string) = 0;
    PeopleFactory() {}
    virtual ~PeopleFactory() {}
};

class StudentFactory : public PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string);
    StudentFactory() {}
    virtual ~StudentFactory() {}
    
};

class EmployeeFactory : public PeopleFactory
{
public:
    virtual AbstractDatabase* load(std::string);
    EmployeeFactory() {}
    virtual ~EmployeeFactory() {}
};

#endif /* defined(__proj02__peoplefactory__) */
