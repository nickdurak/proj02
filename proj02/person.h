//
//  person.h
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __proj02__person__
#define __proj02__person__

#include <iostream>

class Person
{
public:
    Person(unsigned int id = 0, std::string name = "");
    
    virtual void print() const;
    virtual int getGrade() const;
    virtual std::string getName() const;
    virtual int getSalary() const;
    virtual int getYear() const;
    
protected:
    unsigned int m_id;
    std::string m_name;
    
};

#endif /* defined(__proj02__person__) */
