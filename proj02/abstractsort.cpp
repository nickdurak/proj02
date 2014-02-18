/******************************************************
 ** FILE: abstractsort.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of BubbleSort class
 ** 
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 11/02/2014
 **
 *******************************************************/


#include "abstractsort.h"
#include "abstractdatabase.h"

using namespace std;


/*
 sorts database using bubblesort
 */
void BubbleSort::sort(AbstractDatabase* database)
{
    for(int i = database->getSize()-1; i > 0; --i)
        for(int j = 0; j < i; j++)
            if(database->compare(j, i)) database->swap(j, i);
}
