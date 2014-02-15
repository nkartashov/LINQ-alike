//
//  IEnumerable.cpp
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#include "IEnumerable.h"
#include <cstring>


#include "WhereDecorator.h"
#include "SelectDecorator.h"
#include "CountDecorator.h"

enum_ptr IEnumerable::where(where_predicate pred)
{
    return enum_ptr(new WhereDecorator(shared_from_this(), pred));
}

enum_ptr IEnumerable::select(select_function func)
{
    return enum_ptr(new SelectDecorator(shared_from_this(), func));
}

int IEnumerable::count()
{
    return enum_ptr(new CountDecorator(shared_from_this()))->next();
}

enum_ptr Do(vector<int> const & v)
{
    return enum_ptr(new BaseDecorator(v.begin(), v.end()));
}
