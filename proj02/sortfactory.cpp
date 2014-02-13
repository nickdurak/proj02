//
//  sortfactory.cpp
//  proj02
//
//  Created by Nick Durak on 2/12/14.
//  Copyright (c) 2014 Nick Durak. All rights reserved.
//

#include "sortfactory.h"

#include "abstractsort.h"

AbstractSort* BubbleSortFactory::create()
{
    return new BubbleSort;
}