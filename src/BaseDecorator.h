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

#include "IEnumerable.h"

using std::vector;
using std::exception;
using std::shared_ptr;

template <class T, class container = vector<T> >
class BaseDecorator: public IEnumerable<T, container>
{
public:
    BaseDecorator(){}
    BaseDecorator(typename IEnumerable<T, container>::obj_iter beg,
                  typename IEnumerable<T, container>::obj_iter end): m_cur(beg), m_end(end) {}
    
    virtual T next()
    {
        if (m_cur == m_end)
            throw exception();
        T value = *m_cur;
        ++m_cur;
        return value;
    }
    
private:
    typename IEnumerable<T, container>::obj_iter m_cur;
    typename IEnumerable<T, container>::obj_iter m_end;
};

#endif /* defined(__sem15_2__BaseDecorator__) */
