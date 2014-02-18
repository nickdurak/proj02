/******************************************************
 ** FILE: abstractsort.h
 **
 ** ABSTRACT:
 ** Provides declarations for the AbstractSort
 ** and BubbleSort classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 11/02/2014
 **
 *******************************************************/

#ifndef ABSTRACTSORT_H
#define	ABSTRACTSORT_H

class AbstractDatabase;

/*
 AbstractSort...class used as interface for sort
 */
class AbstractSort 
{
public:
    AbstractSort() {}
    virtual void sort(AbstractDatabase*) = 0;
    virtual ~AbstractSort() {}

};

/*
 BubbleSort...class used to implement sort using bubble sort
 */
class BubbleSort : public AbstractSort
{
public:
    BubbleSort() {}
    virtual void sort(AbstractDatabase*);
    virtual ~BubbleSort() {}
};

#endif	/* ABSTRACTSORT_H */

