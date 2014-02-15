//
//  IEnumerable.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef __sem15_2__IEnumerable__
#define __sem15_2__IEnumerable__

#include "Declarations.h"

enum_ptr Do(vector<int> const & v);

class IEnumerable: public std::enable_shared_from_this<IEnumerable>
{
public:
    virtual int next() = 0;
    enum_ptr where(where_predicate pred);
    enum_ptr select(select_function func);
    int count();
    
    virtual ~IEnumerable() {}
};


#endif /* defined(__sem15_2__IEnumerable__) */
