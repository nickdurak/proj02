/******************************************************
 ** FILE: sortfactory.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of the Student, UndergradStudent,
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

#ifndef __proj02__sortfactory__
#define __proj02__sortfactory__

#include <iostream>

class AbstractSort;

/*
 SortFactory...class used as interface for a sort factory
 */
class SortFactory
{
public:
    virtual AbstractSort* create() = 0;
    SortFactory() {}
    virtual ~SortFactory() {}
};

/*
 BubbleSortFactory...class that creats a bubblesort object
 */
class BubbleSortFactory : public SortFactory
{
public:
    virtual AbstractSort* create();
    BubbleSortFactory() {}
    virtual ~BubbleSortFactory() {}
};

#endif /* defined(__proj02__sortfactory__) */
