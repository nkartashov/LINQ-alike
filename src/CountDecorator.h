//
//  CountDecorator.h
//  sem15_2
//
//  Created by Nikita Kartashov on 16/02/2014.
//  Copyright (c) 2014 Nikita Kartashov. All rights reserved.
//

#ifndef sem15_2_CountDecorator_h
#define sem15_2_CountDecorator_h

#include "BaseDecorator.h"

template <class T, class container>
class CountDecorator: public IEnumerable<T, container>
{
public:
    CountDecorator(typename IEnumerable<T, container>::enum_ptr base): m_base(base), m_result(0)
    {
        try
        {
            while(true)
            {
                m_base->next();
                ++m_result;
            }
        }
        catch (std::exception) {}
    }
    
    virtual int next()
    {
        return m_result;
    }
    
private:
    typename IEnumerable<T, container>::enum_ptr m_base;
    int m_result;
};

#endif
