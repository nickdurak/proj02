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

#include "sortfactory.h"

#include "abstractsort.h"

/*
 returns a new BubbleSort object
 */
AbstractSort* BubbleSortFactory::create()
{
    return new BubbleSort;
}