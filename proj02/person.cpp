//
//  person.cpp
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include <iostream>

#include "person.h"

using namespace std;

Person::Person(unsigned int id, std::string name)
{
    m_id = id;
    m_name = name;
}

void Person::print() const
{
    cout << m_id << " " << m_name;
}