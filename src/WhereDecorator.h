//
//  SelectDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 13/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef __sem15_2__SelectDecorator__
#define __sem15_2__SelectDecorator__

#include "BaseDecorator.h"

template <class T, class container = vector<T> >
class WhereDecorator: public IEnumerable<T, container>
{
public:
    
    WhereDecorator(typename IEnumerable<T, container>::enum_ptr base,
                   typename IEnumerable<T, container>::where_predicate pred): m_base(base), m_pred(pred) {}
    
    virtual T next()
    {
        while (true)
        {
            T value = m_base->next();
            if (m_pred(value))
                return value;
        }
    }
    
private:
    typename IEnumerable<T, container>::enum_ptr m_base;
    typename IEnumerable<T, container>::where_predicate m_pred;
};

#endif /* defined(__sem15_2__SelectDecorator__) */
