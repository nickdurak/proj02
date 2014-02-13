//
//  sortfactory.h
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#ifndef __proj02__sortfactory__
#define __proj02__sortfactory__

#include <iostream>

class AbstractSort;

class SortFactory
{
public:
    virtual AbstractSort* create() = 0;
    SortFactory() {}
    virtual ~SortFactory() {}
};

class BubbleSortFactory : public SortFactory
{
public:
    virtual AbstractSort* create();
    BubbleSortFactory() {}
    virtual ~BubbleSortFactory() {}
};

#endif /* defined(__proj02__sortfactory__) */
