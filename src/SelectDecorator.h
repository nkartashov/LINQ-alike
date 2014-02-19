//
//  SelectDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 16/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef sem15_2_SelectDecorator_h
#define sem15_2_SelectDecorator_h

#include "BaseDecorator.h"

template <class T, class container = vector<T> >
class SelectDecorator: public IEnumerable<T, container>
{
public:
    
    SelectDecorator(typename IEnumerable<T, container>::enum_ptr base,
                    typename IEnumerable<T, container>::select_function func): m_base(base), m_func(func) {}
    
    virtual T next()
    {
        return m_func(m_base->next());
    }
    
private:
    typename IEnumerable<T, container>::enum_ptr m_base;
    typename IEnumerable<T, container>::select_function m_func;
};

#endif
