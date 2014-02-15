//
//  BaseDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef __sem15_2__BaseDecorator__
#define __sem15_2__BaseDecorator__

#include <exception>
#include <vector>
#include <memory>

#include "Declarations.h"

#include "IEnumerable.h"

using std::vector;
using std::exception;
using std::shared_ptr;

class BaseDecorator: public IEnumerable
{
public:
    BaseDecorator(){}
    BaseDecorator(int_iter beg, int_iter end): m_cur(beg), m_end(end) {}
    
    virtual int next()
    {
        if (m_cur == m_end)
            throw exception();
        int value = *m_cur;
        ++m_cur;
        return value;
    }
    
private:
    int_iter m_cur;
    int_iter m_end;
};

#endif /* defined(__sem15_2__BaseDecorator__) */
